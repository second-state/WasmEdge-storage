// SPDX-License-Identifier: Apache-2.0
#include "storage_module.h"
#include "storage_func.h"

#include <memory>

namespace WasmEdge {
namespace Host {

WasmEdgeStorageModule::WasmEdgeStorageModule()
    : ImportObject("wasmedge_native") {
  addHostFunc("wasmedge_storage_createUUID",
              std::make_unique<WasmEdgeStorageCreateUUID>(Env));
  addHostFunc("wasmedge_storage_beginStoreTx",
              std::make_unique<WasmEdgeStorageBeginStoreTx>(Env));
  addHostFunc("wasmedge_storage_beginLoadTx",
              std::make_unique<WasmEdgeStorageBeginLoadTx>(Env));
  addHostFunc("wasmedge_storage_storeI32",
              std::make_unique<WasmEdgeStorageStoreI32>(Env));
  addHostFunc("wasmedge_storage_loadI32",
              std::make_unique<WasmEdgeStorageLoadI32>(Env));
  addHostFunc("wasmedge_storage_storeI64",
              std::make_unique<WasmEdgeStorageStoreI64>(Env));
  addHostFunc("wasmedge_storage_loadI64",
              std::make_unique<WasmEdgeStorageLoadI64>(Env));
  addHostFunc("wasmedge_storage_endStoreTx",
              std::make_unique<WasmEdgeStorageEndStoreTx>(Env));
  addHostFunc("wasmedge_storage_endLoadTx",
              std::make_unique<WasmEdgeStorageEndLoadTx>(Env));
}

} // namespace Host
} // namespace WasmEdge