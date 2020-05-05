// SPDX-License-Identifier: Apache-2.0
#pragma once

#include "common/errcode.h"
#include "runtime/hostfunc.h"
#include "runtime/instance/memory.h"
#include "storage_base.h"
#include "storage_env.h"

namespace SSVM {
namespace Host {

class SSVMStorageCreateUUID : public SSVMStorage<SSVMStorageCreateUUID> {
public:
  SSVMStorageCreateUUID(StorageEnvironment &Env) : SSVMStorage(Env) {}
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst, uint32_t &UUID);
};

class SSVMStorageBeginStoreTx : public SSVMStorage<SSVMStorageBeginStoreTx> {
public:
  SSVMStorageBeginStoreTx(StorageEnvironment &Env) : SSVMStorage(Env) {}
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst, uint32_t NewKey);
};

class SSVMStorageBeginLoadTx : public SSVMStorage<SSVMStorageBeginLoadTx> {
public:
  SSVMStorageBeginLoadTx(StorageEnvironment &Env) : SSVMStorage(Env) {}
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst, uint32_t NewKey);
};

class SSVMStorageStoreI32 : public SSVMStorage<SSVMStorageStoreI32> {
public:
  SSVMStorageStoreI32(StorageEnvironment &Env) : SSVMStorage(Env) {}
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst, uint32_t Value);
};

class SSVMStorageLoadI32 : public SSVMStorage<SSVMStorageLoadI32> {
public:
  SSVMStorageLoadI32(StorageEnvironment &Env) : SSVMStorage(Env) {}
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst, uint32_t &Value);
};

class SSVMStorageStoreI64 : public SSVMStorage<SSVMStorageStoreI64> {
public:
  SSVMStorageStoreI64(StorageEnvironment &Env) : SSVMStorage(Env) {}
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst, uint64_t Value);
};

class SSVMStorageLoadI64 : public SSVMStorage<SSVMStorageLoadI64> {
public:
  SSVMStorageLoadI64(StorageEnvironment &Env) : SSVMStorage(Env) {}
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst, uint64_t &Value);
};

class SSVMStorageEndStoreTx : public SSVMStorage<SSVMStorageEndStoreTx> {
public:
  SSVMStorageEndStoreTx(StorageEnvironment &Env) : SSVMStorage(Env) {}
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst);
};

class SSVMStorageEndLoadTx : public SSVMStorage<SSVMStorageEndLoadTx> {
public:
  SSVMStorageEndLoadTx(StorageEnvironment &Env) : SSVMStorage(Env) {}
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst);
};

} // namespace Host
} // namespace SSVM