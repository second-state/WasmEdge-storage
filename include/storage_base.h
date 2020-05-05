// SPDX-License-Identifier: Apache-2.0
#pragma once

#include "common/errcode.h"
#include "runtime/hostfunc.h"
#include "storage_env.h"

namespace SSVM {
namespace Host {

template <typename T> class SSVMStorage : public Runtime::HostFunction<T> {
public:
  SSVMStorage(StorageEnvironment &HostEnv)
      : Runtime::HostFunction<T>(0), Env(HostEnv) {}

protected:
  StorageEnvironment &Env;
};

} // namespace Host
} // namespace SSVM