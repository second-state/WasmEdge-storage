# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.11)
project(SSVM-Storage)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()
option(BUILD_TOOLS "Generate ssvm and ssvmc tools." OFF)

# Clone ssvm-core
if(NOT SSVM_CORE_PATH)
  include(FetchContent)
  FetchContent_Declare(
    ssvm
    GIT_REPOSITORY https://github.com/second-state/SSVM.git
    GIT_TAG 0.7.2
  )

  FetchContent_GetProperties(ssvm)
  if (NOT ssvm_POPULATED)
      FetchContent_Populate(ssvm)
  endif ()
  add_subdirectory(${ssvm_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/utils/ssvm-core)
  set(SSVM_CORE_SRC_DIR ${ssvm_SOURCE_DIR})
else()
  get_filename_component(
    SSVM_CORE_PATH "${SSVM_CORE_PATH}"
    REALPATH
    BASE_DIR "${CMAKE_CURRENT_BINARY_DIR}")
  add_subdirectory(${SSVM_CORE_PATH} ${CMAKE_CURRENT_BINARY_DIR}/utils/ssvm-core)
  set(SSVM_CORE_SRC_DIR ${SSVM_CORE_PATH})
endif()

set(RUST_STORAGE_LIB_DIR utils/rust_native_storage_library)

include_directories(BEFORE
  ${CMAKE_CURRENT_BINARY_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_BINARY_DIR}/${RUST_STORAGE_LIB_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/${RUST_STORAGE_LIB_DIR}/src
)

# rustc target
if(CMAKE_SYSTEM_NAME STREQUAL Darwin)
  set(RUSTC_TARGET "x86_64-apple-darwin")
else()
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(RUSTC_TARGET "x86_64-unknown-linux-gnu")
  else()
    set(RUSTC_TARGET "i686-unknown-linux-gnu")
  endif()
endif()

# Cargo build command
set(RUST_STORAGE_LIB "${CMAKE_CURRENT_BINARY_DIR}/target/${RUSTC_TARGET}/release/${CMAKE_STATIC_LIBRARY_PREFIX}ssvm_storage_rust.a")
if(CMAKE_BUILD_TYPE STREQUAL Release OR CMAKE_BUILD_TYPE STREQUAL RelWithDebInfo)
  set(RUST_STORAGE_FLAG "RUSTFLAGS=\"-Clinker-plugin-lto\"")
endif()
add_custom_command(
  OUTPUT ${RUST_STORAGE_LIB}
  COMMAND ${CMAKE_COMMAND} -E env CARGO_TARGET_DIR=${CMAKE_CURRENT_BINARY_DIR}/target ${RUST_STORAGE_FLAG} cargo build --release --target ${RUSTC_TARGET}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT "running cargo")

add_custom_target(ssvmStorageRust_target ALL DEPENDS ${RUST_STORAGE_LIB})
add_library(ssvmStorageRust STATIC IMPORTED GLOBAL)
add_dependencies(ssvmStorageRust ssvmStorageRust_target)
set_target_properties(ssvmStorageRust PROPERTIES IMPORTED_LOCATION ${RUST_STORAGE_LIB})

set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(include)
add_subdirectory(lib)
