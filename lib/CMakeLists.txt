# SPDX-License-Identifier: Apache-2.0

add_library(ssvmHostModuleSSVMStorage
  storage_module.cpp
  storage_func.cpp
)

add_dependencies(ssvmHostModuleSSVMStorage ssvmStorageRust)

target_link_libraries(ssvmHostModuleSSVMStorage
  PRIVATE
  ssvmStorageRust
)

target_include_directories(ssvmHostModuleSSVMStorage
  PUBLIC
  ${SSVM_CORE_SRC_DIR}/include
)
