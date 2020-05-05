// SPDX-License-Identifier: Apache-2.0
#include "storage_module.h"
#include "storage_func.h"

#include <memory>

namespace SSVM {
namespace Host {

SSVMStorageModule::SSVMStorageModule() : ImportObject("ssvm_native") {
  addHostFunc("ssvm_storage_createUUID",
              std::make_unique<SSVMStorageCreateUUID>(Env));
  addHostFunc("ssvm_storage_beginStoreTx",
              std::make_unique<SSVMStorageBeginStoreTx>(Env));
  addHostFunc("ssvm_storage_beginLoadTx",
              std::make_unique<SSVMStorageBeginLoadTx>(Env));
  addHostFunc("ssvm_storage_storeI32",
              std::make_unique<SSVMStorageStoreI32>(Env));
  addHostFunc("ssvm_storage_loadI32",
              std::make_unique<SSVMStorageLoadI32>(Env));
  addHostFunc("ssvm_storage_storeI64",
              std::make_unique<SSVMStorageStoreI64>(Env));
  addHostFunc("ssvm_storage_loadI64",
              std::make_unique<SSVMStorageLoadI64>(Env));
  addHostFunc("ssvm_storage_endStoreTx",
              std::make_unique<SSVMStorageEndStoreTx>(Env));
  addHostFunc("ssvm_storage_endLoadTx",
              std::make_unique<SSVMStorageEndLoadTx>(Env));
}

} // namespace Host
} // namespace SSVM