#include "./common/Structures/FileChunkReference64.hpp"
#include <cstring>
#include <iomanip>

using namespace std;

/**
 * @brief 
 * 
 * @param obj 
 * @param src 
 * @return size_t 
 */

size_t FileChunkReference64::Deserialize(FileChunkReference64 &obj, char *src) {
 const size_t TYPE_SIZE = 16;

  char *idx = src;
  memcpy((char *)&obj, src, TYPE_SIZE);
  idx += TYPE_SIZE;

  return static_cast<size_t>(idx - src);
};

size_t FileChunkReference64::Deserialize(char *src) {
  memcpy((char *)this, src,sizeof(FileChunkReference64));
  return sizeof(FileChunkReference64);
};

ostream &operator<<(ostream &os, const FileChunkReference64 &ref64) {
  return os 
    << setw(sizeof(ref64.Stp)) << std::hex << (uint64_t)ref64.Stp 
    << "-" 
    << setw(sizeof(ref64.Cb)) << std::hex << (uint32_t)ref64.Cb;
};