#include <cstring>
#include "./common/Structures/FileChunkReference32.hpp"

using namespace std;

/**
 * @brief 
 * 
 * @param obj 
 * @param src 
 * @return size_t 
 */
size_t FileChunkReference32::Deserialize(FileChunkReference32 &obj, char *src) {
  const size_t TYPE_SIZE = 8;

  char *idx = src;
  memcpy((char *)&obj, src, TYPE_SIZE);
  idx += TYPE_SIZE;

  return static_cast<size_t>(idx - src);
};

ostream &operator<<(ostream &os, const FileChunkReference32 &ref32) {
  return os 
    << setw(sizeof(ref32.Stp)*2) << std::hex << (uint32_t)ref32.Stp 
    << "-" 
    << setw(sizeof(ref32.Cb)*2) << std::hex << (uint32_t)ref32.Cb;
};