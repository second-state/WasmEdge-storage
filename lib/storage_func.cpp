// SPDX-License-Identifier: Apache-2.0

#include "storage_func.h"
#include "test_lib.h"

#include <ctime>
#include <string>

#include <iostream>

namespace SSVM {
namespace Host {

Expect<uint32_t>
SSVMStorageCreateUUID::body(Runtime::Instance::MemoryInstance &MemInst) {
  std::time_t CurrTime = std::time(nullptr);
  return static_cast<uint32_t>(CurrTime);
}

Expect<void>
SSVMStorageBeginStoreTx::body(Runtime::Instance::MemoryInstance &MemInst,
                              uint32_t NewKey) {
  Env.getKey() = std::to_string(NewKey);
  Env.getBuf().clear();
  return {};
}

Expect<void>
SSVMStorageBeginLoadTx::body(Runtime::Instance::MemoryInstance &MemInst,
                             uint32_t NewKey) {
  Env.getKey() = std::to_string(NewKey);
  Env.getBuf().clear();
  uint32_t Len =
      get_byte_array_length(Env.getKey().c_str(), Env.getKey().length());
  char *Ptr =
      get_byte_array_pointer(Env.getKey().c_str(), Env.getKey().length());
  if (Ptr == nullptr) {
    return Unexpect(ErrCode::ExecutionFailed);
  }
  std::copy_n(Ptr, Len, std::back_inserter(Env.getBuf()));
  Env.getLoadOff() = 0;
  free_byte_array_pointer(Ptr, Len);
  return {};
}

Expect<void>
SSVMStorageStoreI32::body(Runtime::Instance::MemoryInstance &MemInst,
                          uint32_t Value) {
  uint8_t Buf[4];
  std::memcpy(&Buf, &Value, sizeof(Value));
  std::copy_n(Buf, 4, std::back_inserter(Env.getBuf()));
  return {};
}

Expect<uint32_t>
SSVMStorageLoadI32::body(Runtime::Instance::MemoryInstance &MemInst) {
  auto &Off = Env.getLoadOff();
  if (Off >= Env.getBuf().size() || Off + 4 > Env.getBuf().size()) {
    return Unexpect(ErrCode::ExecutionFailed);
  }
  uint32_t Value = 0;
  std::memcpy(&Value, &Env.getBuf()[Off], 4);
  Off += 4;
  return Value;
}

Expect<void>
SSVMStorageStoreI64::body(Runtime::Instance::MemoryInstance &MemInst,
                          uint64_t Value) {
  uint8_t Buf[8];
  std::memcpy(&Buf, &Value, sizeof(Value));
  std::copy_n(Buf, 8, std::back_inserter(Env.getBuf()));
  return {};
}

Expect<uint64_t>
SSVMStorageLoadI64::body(Runtime::Instance::MemoryInstance &MemInst) {
  auto &Off = Env.getLoadOff();
  if (Off >= Env.getBuf().size() || Off + 8 > Env.getBuf().size()) {
    return Unexpect(ErrCode::ExecutionFailed);
  }
  uint64_t Value = 0;
  std::memcpy(&Value, &Env.getBuf()[Off], 8);
  Off += 8;
  return Value;
}

Expect<void>
SSVMStorageEndStoreTx::body(Runtime::Instance::MemoryInstance &MemInst) {
  store_byte_array(Env.getKey().c_str(), Env.getKey().length(),
                   reinterpret_cast<char *>(&(Env.getBuf()[0])),
                   Env.getBuf().size());
  return {};
}

Expect<void>
SSVMStorageEndLoadTx::body(Runtime::Instance::MemoryInstance &MemInst) {
  Env.getLoadOff() = 0;
  return {};
}

} // namespace Host
} // namespace SSVM
