// SPDX-License-Identifier: Apache-2.0

#include "storage_func.h"
#include "test_lib.h"

#include <iostream>

namespace SSVM {
namespace Host {

ErrCode SSVMStorageCreateUUID::body(Runtime::Instance::MemoryInstance &MemInst,
                                    uint64_t &UUID) {
  /// TODO: Function body.
  return ErrCode::Success;
}

ErrCode
SSVMStorageBeginStoreTx::body(Runtime::Instance::MemoryInstance &MemInst,
                              uint64_t NewKey) {
  /// TODO: Function body.
  return ErrCode::Success;
}

ErrCode SSVMStorageBeginLoadTx::body(Runtime::Instance::MemoryInstance &MemInst,
                                     uint64_t NewKey) {
  /// TODO: Function body.
  return ErrCode::Success;
}

ErrCode SSVMStorageStoreI32::body(Runtime::Instance::MemoryInstance &MemInst,
                                  uint32_t Value) {
  /// TODO: Function body.
  return ErrCode::Success;
}

ErrCode SSVMStorageLoadI32::body(Runtime::Instance::MemoryInstance &MemInst,
                                 uint32_t &Value) {
  /// TODO: Function body.
  return ErrCode::Success;
}

ErrCode SSVMStorageStoreI64::body(Runtime::Instance::MemoryInstance &MemInst,
                                  uint64_t Value) {
  /// TODO: Function body.
  return ErrCode::Success;
}

ErrCode SSVMStorageLoadI64::body(Runtime::Instance::MemoryInstance &MemInst,
                                 uint64_t &Value) {
  /// TODO: Function body.
  return ErrCode::Success;
}

ErrCode
SSVMStorageEndStoreTx::body(Runtime::Instance::MemoryInstance &MemInst) {
  /// TODO: Function body.
  std::cout << "  ------ ssvm storage end store tx\n";
  return ErrCode::Success;
}

ErrCode SSVMStorageEndLoadTx::body(Runtime::Instance::MemoryInstance &MemInst) {
  /// TODO: Function body.
  std::cout << "  ------ ssvm storage end load tx\n";
  return ErrCode::Success;
}

} // namespace Host
} // namespace SSVM
