// SPDX-License-Identifier: Apache-2.0
#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace SSVM {
namespace Host {

class StorageEnvironment {
public:
  struct DBBuffer {
    char *Ptr;
    uint32_t Off;
  };
  std::string &getKey() { return Key; }
  std::vector<uint8_t> &getBuf() { return Buf; }
  DBBuffer &getLoadPtr() { return DBBuf; }

private:
  std::string Key;
  std::vector<uint8_t> Buf;
  DBBuffer DBBuf;
};

} // namespace Host
} // namespace SSVM
