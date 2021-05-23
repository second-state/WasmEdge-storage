// SPDX-License-Identifier: Apache-2.0
#pragma once

#include "runtime/importobj.h"
#include "storage_env.h"

namespace WasmEdge {
namespace Host {

class WasmEdgeStorageModule : public Runtime::ImportObject {
public:
  WasmEdgeStorageModule();

private:
  StorageEnvironment Env;
};

} // namespace Host
} // namespace WasmEdge
