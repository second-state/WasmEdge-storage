// SPDX-License-Identifier: Apache-2.0
#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace SSVM {
namespace Host {

class StorageEnvironment {
public:
  std::string &getKey() { return Key; }
  std::vector<uint8_t> &getBuf() { return Buf; }
  uint32_t &getLoadOff() { return LoadOff; }

private:
  std::string Key;
  std::vector<uint8_t> Buf;
  uint32_t LoadOff;
};

} // namespace Host
} // namespace SSVM
