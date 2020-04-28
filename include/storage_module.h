// SPDX-License-Identifier: Apache-2.0
#pragma once

#include "runtime/importobj.h"

namespace SSVM {
namespace Host {

class SSVMStorageModule : public Runtime::ImportObject {
public:
  SSVMStorageModule();
};

} // namespace Host
} // namespace SSVM
