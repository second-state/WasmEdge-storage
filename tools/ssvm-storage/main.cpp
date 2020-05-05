// SPDX-License-Identifier: Apache-2.0
#include "common/value.h"
#include "expvm/configure.h"
#include "expvm/vm.h"
#include "storage_module.h"
#include "support/log.h"

#include <iostream>

int main(int Argc, char *Argv[]) {
  SSVM::Log::setErrorLoggingLevel();

  SSVM::ExpVM::Configure Conf;
  SSVM::ExpVM::VM VM(Conf);

  SSVM::Host::SSVMStorageModule StorageMod;
  VM.registerModule(StorageMod);

  /// Parameters and return values.
  std::vector<SSVM::ValVariant> Params, Results;
  uint32_t U32;
  uint64_t U64;

  /// Create UUID
  Results = *VM.execute("ssvm_native", "ssvm_storage_createUUID", {});
  uint32_t UUID = std::get<uint32_t>(Results[0]);
  std::cout << "  Created UUID : " << UUID << std::endl;

  /// Begin storing
  Params = {UUID};
  VM.execute("ssvm_native", "ssvm_storage_beginStoreTx", Params);
  std::cout << "  Begin store transection" << std::endl;

  /// Store values
  U32 = 1;
  Params = {U32};
  VM.execute("ssvm_native", "ssvm_storage_storeI32", Params);
  std::cout << "  Stored i32 value : " << static_cast<int32_t>(U32)
            << std::endl;
  U32 = 2;
  Params = {U32};
  VM.execute("ssvm_native", "ssvm_storage_storeI32", Params);
  std::cout << "  Stored i32 value : " << static_cast<int32_t>(U32)
            << std::endl;
  U64 = 3;
  Params = {U64};
  VM.execute("ssvm_native", "ssvm_storage_storeI64", Params);
  std::cout << "  Stored i64 value : " << static_cast<int64_t>(U64)
            << std::endl;
  U64 = 4;
  Params = {U64};
  VM.execute("ssvm_native", "ssvm_storage_storeI64", Params);
  std::cout << "  Stored i64 value : " << static_cast<int64_t>(U64)
            << std::endl;

  /// End storing
  VM.execute("ssvm_native", "ssvm_storage_endStoreTx", {});
  std::cout << "  End store transection" << std::endl;

  /// Begin loading
  Params = {UUID};
  VM.execute("ssvm_native", "ssvm_storage_beginLoadTx", Params);
  std::cout << "  Begin load transection" << std::endl;

  /// Load values
  Results = *VM.execute("ssvm_native", "ssvm_storage_loadI32", {});
  U32 = std::get<uint32_t>(Results[0]);
  std::cout << "  Loaded i32 value : " << static_cast<int32_t>(U32)
            << std::endl;
  Results = *VM.execute("ssvm_native", "ssvm_storage_loadI32", {});
  U32 = std::get<uint32_t>(Results[0]);
  std::cout << "  Loaded i32 value : " << static_cast<int32_t>(U32)
            << std::endl;
  Results = *VM.execute("ssvm_native", "ssvm_storage_loadI64", {});
  U64 = std::get<uint64_t>(Results[0]);
  std::cout << "  Loaded i64 value : " << static_cast<int64_t>(U64)
            << std::endl;
  Results = *VM.execute("ssvm_native", "ssvm_storage_loadI64", {});
  U64 = std::get<uint64_t>(Results[0]);
  std::cout << "  Loaded i64 value : " << static_cast<int64_t>(U64)
            << std::endl;

  /// End loading
  VM.execute("ssvm_native", "ssvm_storage_endLoadTx", {});
  std::cout << "  End load transection" << std::endl;
  return 0;
}
