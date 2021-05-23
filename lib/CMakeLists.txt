# SPDX-License-Identifier: Apache-2.0

add_library(wasmedgeHostModuleWasmEdgeStorage
  storage_module.cpp
  storage_func.cpp
)

add_dependencies(wasmedgeHostModuleWasmEdgeStorage wasmedgeStorageRust)

target_link_libraries(wasmedgeHostModuleWasmEdgeStorage
  PRIVATE
  wasmedgeStorageRust
  wasmedgeCommon
  wasmedgeSystem
)

target_include_directories(wasmedgeHostModuleWasmEdgeStorage
  PUBLIC
  ${Boost_INCLUDE_DIR}
  ${WASMEDGE_CORE_PATH}/include
  ${WASMEDGE_CORE_PATH}/thirdparty
)

if (BUILD_SHARED_LIB)
  add_library(wasmedge-storage_c SHARED
    # Rebuild these files without linking the built targets because the static libraries enabled LTO.
    ${WASMEDGE_CORE_PATH}/lib/common/hexstr.cpp
    ${WASMEDGE_CORE_PATH}/lib/common/log.cpp
    ${WASMEDGE_CORE_PATH}/lib/common/configure.cpp
    ${WASMEDGE_CORE_PATH}/thirdparty/easyloggingpp/easylogging++.cc
    ${WASMEDGE_CORE_PATH}/lib/system/allocator.cpp
    # Add this in 0.8.1:
    #${WASMEDGE_CORE_PATH}/lib/system/mmap.cpp
    wasmedge-storage.cpp
    storage_module.cpp
    storage_func.cpp
  )

  add_dependencies(wasmedge-storage_c wasmedgeStorageRust)

  # Forced disable LTO to link the static library in rust (LLVM12) with self (LLVM10)
  set_property(TARGET wasmedge-storage_c PROPERTY INTERPROCEDURAL_OPTIMIZATION false)

  # Used by easylogging++
  target_compile_definitions(wasmedge-storage_c
    PUBLIC
    -DELPP_NO_DEFAULT_LOG_FILE
  )

  target_include_directories(wasmedge-storage_c
    PUBLIC
    ${Boost_INCLUDE_DIR}
    ${WASMEDGE_CORE_PATH}/include
    ${WASMEDGE_CORE_PATH}/thirdparty
    ${WASMEDGE_CORE_BIN_PATH}/include/api
    # Used by wasmedgeSystem
    ${WASMEDGE_CORE_BIN_PATH}/lib/system
  )

  target_link_libraries(wasmedge-storage_c
    PRIVATE
    wasmedgeStorageRust
  )

endif()
