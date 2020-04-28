// SPDX-License-Identifier: Apache-2.0
#pragma once

#include "common/errcode.h"
#include "runtime/hostfunc.h"
#include "runtime/instance/memory.h"
#include "storage_base.h"

namespace SSVM {
namespace Host {

class SSVMStorageCreateUUID : public SSVMStorage<SSVMStorageCreateUUID> {
public:
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst, uint64_t &UUID);
};

class SSVMStorageBeginStoreTx : public SSVMStorage<SSVMStorageBeginStoreTx> {
public:
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst, uint64_t NewKey);
};

class SSVMStorageBeginLoadTx : public SSVMStorage<SSVMStorageBeginLoadTx> {
public:
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst, uint64_t NewKey);
};

class SSVMStorageStoreI32 : public SSVMStorage<SSVMStorageStoreI32> {
public:
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst, uint32_t Value);
};

class SSVMStorageLoadI32 : public SSVMStorage<SSVMStorageLoadI32> {
public:
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst, uint32_t &Value);
};

class SSVMStorageStoreI64 : public SSVMStorage<SSVMStorageStoreI64> {
public:
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst, uint64_t Value);
};

class SSVMStorageLoadI64 : public SSVMStorage<SSVMStorageLoadI64> {
public:
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst, uint64_t &Value);
};

class SSVMStorageEndStoreTx : public SSVMStorage<SSVMStorageEndStoreTx> {
public:
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst);
};

class SSVMStorageEndLoadTx : public SSVMStorage<SSVMStorageEndLoadTx> {
public:
  ErrCode body(Runtime::Instance::MemoryInstance &MemInst);
};

} // namespace Host
} // namespace SSVM