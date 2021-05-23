// SPDX-License-Identifier: Apache-2.0
#pragma once

#include "common/errcode.h"
#include "runtime/hostfunc.h"
#include "runtime/instance/memory.h"
#include "storage_base.h"
#include "storage_env.h"

namespace WasmEdge {
namespace Host {

class WasmEdgeStorageCreateUUID
    : public WasmEdgeStorage<WasmEdgeStorageCreateUUID> {
public:
  WasmEdgeStorageCreateUUID(StorageEnvironment &Env) : WasmEdgeStorage(Env) {}
  Expect<void> body(Runtime::Instance::MemoryInstance *MemInst,
                    uint32_t KeyPtr);
};

class WasmEdgeStorageBeginStoreTx
    : public WasmEdgeStorage<WasmEdgeStorageBeginStoreTx> {
public:
  WasmEdgeStorageBeginStoreTx(StorageEnvironment &Env) : WasmEdgeStorage(Env) {}
  Expect<void> body(Runtime::Instance::MemoryInstance *MemInst,
                    uint32_t KeyPtr);
};

class WasmEdgeStorageBeginLoadTx
    : public WasmEdgeStorage<WasmEdgeStorageBeginLoadTx> {
public:
  WasmEdgeStorageBeginLoadTx(StorageEnvironment &Env) : WasmEdgeStorage(Env) {}
  Expect<void> body(Runtime::Instance::MemoryInstance *MemInst,
                    uint32_t KeyPtr);
};

class WasmEdgeStorageStoreI32
    : public WasmEdgeStorage<WasmEdgeStorageStoreI32> {
public:
  WasmEdgeStorageStoreI32(StorageEnvironment &Env) : WasmEdgeStorage(Env) {}
  Expect<void> body(Runtime::Instance::MemoryInstance *MemInst, uint32_t Value);
};

class WasmEdgeStorageLoadI32 : public WasmEdgeStorage<WasmEdgeStorageLoadI32> {
public:
  WasmEdgeStorageLoadI32(StorageEnvironment &Env) : WasmEdgeStorage(Env) {}
  Expect<uint32_t> body(Runtime::Instance::MemoryInstance *MemInst);
};

class WasmEdgeStorageStoreI64
    : public WasmEdgeStorage<WasmEdgeStorageStoreI64> {
public:
  WasmEdgeStorageStoreI64(StorageEnvironment &Env) : WasmEdgeStorage(Env) {}
  Expect<void> body(Runtime::Instance::MemoryInstance *MemInst, uint64_t Value);
};

class WasmEdgeStorageLoadI64 : public WasmEdgeStorage<WasmEdgeStorageLoadI64> {
public:
  WasmEdgeStorageLoadI64(StorageEnvironment &Env) : WasmEdgeStorage(Env) {}
  Expect<uint64_t> body(Runtime::Instance::MemoryInstance *MemInst);
};

class WasmEdgeStorageEndStoreTx
    : public WasmEdgeStorage<WasmEdgeStorageEndStoreTx> {
public:
  WasmEdgeStorageEndStoreTx(StorageEnvironment &Env) : WasmEdgeStorage(Env) {}
  Expect<void> body(Runtime::Instance::MemoryInstance *MemInst);
};

class WasmEdgeStorageEndLoadTx
    : public WasmEdgeStorage<WasmEdgeStorageEndLoadTx> {
public:
  WasmEdgeStorageEndLoadTx(StorageEnvironment &Env) : WasmEdgeStorage(Env) {}
  Expect<void> body(Runtime::Instance::MemoryInstance *MemInst);
};

} // namespace Host
} // namespace WasmEdge