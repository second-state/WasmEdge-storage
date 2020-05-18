# SPDX-License-Identifier: Apache-2.0
add_executable(ssvm-storage
  main.cpp
)

target_link_libraries(ssvm-storage
  PRIVATE
  ssvmHostModuleSSVMStorage
  ssvmVM
)
