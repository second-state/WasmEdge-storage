// SPDX-License-Identifier: Apache-2.0
#pragma once

#include "common/errcode.h"
#include "runtime/hostfunc.h"
#include "storage_env.h"

namespace WasmEdge {
namespace Host {

template <typename T> class WasmEdgeStorage : public Runtime::HostFunction<T> {
public:
  WasmEdgeStorage(StorageEnvironment &HostEnv)
      : Runtime::HostFunction<T>(0), Env(HostEnv) {}

protected:
  StorageEnvironment &Env;
};

} // namespace Host
} // namespace WasmEdge