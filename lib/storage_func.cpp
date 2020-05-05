// SPDX-License-Identifier: Apache-2.0

#include "storage_func.h"
#include "test_lib.h"

#include <ctime>
#include <string>

#include <iostream>

namespace SSVM {
namespace Host {

ErrCode SSVMStorageCreateUUID::body(Runtime::Instance::MemoryInstance &MemInst,
                                    uint32_t &UUID) {
  std::time_t CurrTime = std::time(nullptr);
  UUID = static_cast<uint32_t>(CurrTime);
  return ErrCode::Success;
}

ErrCode
SSVMStorageBeginStoreTx::body(Runtime::Instance::MemoryInstance &MemInst,
                              uint32_t NewKey) {
  Env.getKey() = std::to_string(NewKey);
  Env.getBuf().clear();
  return ErrCode::Success;
}

ErrCode SSVMStorageBeginLoadTx::body(Runtime::Instance::MemoryInstance &MemInst,
                                     uint32_t NewKey) {
  Env.getKey() = std::to_string(NewKey);
  char *Ptr = load_bytes(Env.getKey().c_str());
  if (Ptr == nullptr) {
    return ErrCode::ExecutionFailed;
  }
  Env.getLoadPtr().Ptr = Ptr;
  Env.getLoadPtr().Off = 0;
  return ErrCode::Success;
}

ErrCode SSVMStorageStoreI32::body(Runtime::Instance::MemoryInstance &MemInst,
                                  uint32_t Value) {
  uint8_t Buf[4];
  std::memcpy(&Buf, &Value, sizeof(Value));
  std::copy_n(Buf, 4, std::back_inserter(Env.getBuf()));
  return ErrCode::Success;
}

ErrCode SSVMStorageLoadI32::body(Runtime::Instance::MemoryInstance &MemInst,
                                 uint32_t &Value) {
  auto &DBBuf = Env.getLoadPtr();
  std::memcpy(&Value, DBBuf.Ptr + DBBuf.Off, 4);
  DBBuf.Off += 4;
  return ErrCode::Success;
}

ErrCode SSVMStorageStoreI64::body(Runtime::Instance::MemoryInstance &MemInst,
                                  uint64_t Value) {
  uint8_t Buf[8];
  std::memcpy(&Buf, &Value, sizeof(Value));
  std::copy_n(Buf, 8, std::back_inserter(Env.getBuf()));
  return ErrCode::Success;
}

ErrCode SSVMStorageLoadI64::body(Runtime::Instance::MemoryInstance &MemInst,
                                 uint64_t &Value) {
  auto &DBBuf = Env.getLoadPtr();
  std::memcpy(&Value, DBBuf.Ptr + DBBuf.Off, 8);
  DBBuf.Off += 8;
  return ErrCode::Success;
}

ErrCode
SSVMStorageEndStoreTx::body(Runtime::Instance::MemoryInstance &MemInst) {
  store_bytes(Env.getKey().c_str(),
              reinterpret_cast<char *>(&(Env.getBuf()[0])));
  return ErrCode::Success;
}

ErrCode SSVMStorageEndLoadTx::body(Runtime::Instance::MemoryInstance &MemInst) {
  free_pointer(Env.getLoadPtr().Ptr);
  Env.getLoadPtr() = {nullptr, 0};
  return ErrCode::Success;
}

} // namespace Host
} // namespace SSVM
