// SPDX-License-Identifier: Apache-2.0
#include "common/value.h"
#include "expvm/configure.h"
#include "expvm/vm.h"
#include "storage_module.h"

int main(int Argc, char *Argv[]) {

  SSVM::ExpVM::Configure Conf;
  SSVM::ExpVM::VM VM(Conf);

  SSVM::Host::SSVMStorageModule StorageMod;
  VM.registerModule(StorageMod);

  /// Parameters and return values.
  std::vector<SSVM::ValVariant> Params, Results;
  VM.execute("ssvm_native", "ssvm_storage_endLoadTx", Params);
  VM.execute("ssvm_native", "ssvm_storage_endStoreTx", Params);
  return 0;
}
