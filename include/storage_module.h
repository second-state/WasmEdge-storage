// SPDX-License-Identifier: Apache-2.0
#pragma once

#include "runtime/importobj.h"
#include "storage_env.h"

namespace SSVM {
namespace Host {

class SSVMStorageModule : public Runtime::ImportObject {
public:
  SSVMStorageModule();

private:
  StorageEnvironment Env;
};

} // namespace Host
} // namespace SSVM
