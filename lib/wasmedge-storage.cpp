// SPDX-License-Identifier: Apache-2.0
#include <wasmedge.h>

#include "storage_module.h"
#include "wasmedge-storage.h"

#ifdef __cplusplus
extern "C" {
#endif

WasmEdge_ImportObjectContext *WasmEdge_Storage_ImportObjectCreate() {
  return reinterpret_cast<WasmEdge_ImportObjectContext *>(
      new WasmEdge::Host::WasmEdgeStorageModule());
}

#ifdef __cplusplus
} /// extern "C"
#endif
