// SPDX-License-Identifier: Apache-2.0

#include "storage_func.h"
#include "common/hexstr.h"
#include "test_lib.h"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <string>
#include <vector>

namespace WasmEdge {
namespace Host {

Expect<void>
WasmEdgeStorageCreateUUID::body(Runtime::Instance::MemoryInstance *MemInst,
                                uint32_t KeyPtr) {
  /// Check memory instance from module.
  if (MemInst == nullptr) {
    return Unexpect(ErrCode::ExecutionFailed);
  }

  boost::uuids::uuid UUID = boost::uuids::random_generator()();
  std::vector<uint8_t> Key;
  std::copy_n(&UUID.data[0], 16, std::back_inserter(Key));
  std::string KeyStr;
  convertBytesToHexStr(Key, KeyStr);
  char *Dst = MemInst->getPointer<char *>(KeyPtr);
  std::copy_n(KeyStr.c_str(), 32, Dst);
  *(Dst + 32) = '\0';
  return {};
}

Expect<void>
WasmEdgeStorageBeginStoreTx::body(Runtime::Instance::MemoryInstance *MemInst,
                                  uint32_t KeyPtr) {
  /// Check memory instance from module.
  if (MemInst == nullptr) {
    return Unexpect(ErrCode::ExecutionFailed);
  }

  char *Str = MemInst->getPointer<char *>(KeyPtr);
  Env.getKey().clear();
  std::copy_n(Str, 32, std::back_inserter(Env.getKey()));
  Env.getBuf().clear();
  return {};
}

Expect<void>
WasmEdgeStorageBeginLoadTx::body(Runtime::Instance::MemoryInstance *MemInst,
                                 uint32_t KeyPtr) {
  /// Check memory instance from module.
  if (MemInst == nullptr) {
    return Unexpect(ErrCode::ExecutionFailed);
  }

  char *Str = MemInst->getPointer<char *>(KeyPtr);
  Env.getKey().clear();
  std::copy_n(Str, 32, std::back_inserter(Env.getKey()));
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
WasmEdgeStorageStoreI32::body(Runtime::Instance::MemoryInstance *MemInst,
                              uint32_t Value) {
  uint8_t Buf[4];
  std::memcpy(&Buf, &Value, sizeof(Value));
  std::copy_n(Buf, 4, std::back_inserter(Env.getBuf()));
  return {};
}

Expect<uint32_t>
WasmEdgeStorageLoadI32::body(Runtime::Instance::MemoryInstance *MemInst) {
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
WasmEdgeStorageStoreI64::body(Runtime::Instance::MemoryInstance *MemInst,
                              uint64_t Value) {
  uint8_t Buf[8];
  std::memcpy(&Buf, &Value, sizeof(Value));
  std::copy_n(Buf, 8, std::back_inserter(Env.getBuf()));
  return {};
}

Expect<uint64_t>
WasmEdgeStorageLoadI64::body(Runtime::Instance::MemoryInstance *MemInst) {
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
WasmEdgeStorageEndStoreTx::body(Runtime::Instance::MemoryInstance *MemInst) {
  store_byte_array(Env.getKey().c_str(), Env.getKey().length(),
                   reinterpret_cast<char *>(&(Env.getBuf()[0])),
                   Env.getBuf().size());
  return {};
}

Expect<void>
WasmEdgeStorageEndLoadTx::body(Runtime::Instance::MemoryInstance *MemInst) {
  Env.getLoadOff() = 0;
  return {};
}

} // namespace Host
} // namespace WasmEdge
