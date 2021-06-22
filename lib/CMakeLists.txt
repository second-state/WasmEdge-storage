# SPDX-License-Identifier: Apache-2.0

add_library(wasmedgeHostModuleWasmEdgeStorage
  storage_module.cpp
  storage_func.cpp
)

add_dependencies(wasmedgeHostModuleWasmEdgeStorage wasmedgeStorageRust)

target_link_libraries(wasmedgeHostModuleWasmEdgeStorage
  PUBLIC
  wasmedgeCommon
  wasmedgeSystem
  wasmedgeStorageRust
)

target_include_directories(wasmedgeHostModuleWasmEdgeStorage
  PUBLIC
  ${WASMEDGE_CORE_PATH}/include
)

if (BUILD_SHARED_LIB)
  add_library(wasmedge-storage_c SHARED
    wasmedge-storage.cpp
    storage_module.cpp
    storage_func.cpp
  )

  add_dependencies(wasmedge-storage_c wasmedgeStorageRust)

  target_include_directories(wasmedge-storage_c
    PUBLIC
    ${WASMEDGE_CORE_PATH}/include
    ${WASMEDGE_CORE_BIN_PATH}/include/api
  )

  target_link_libraries(wasmedge-storage_c
    PUBLIC
    wasmedgeCommon
    wasmedgeSystem
    wasmedgeStorageRust
  )

endif()
