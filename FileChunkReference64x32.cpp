#include "./common/Structures/FileChunkReference64x32.hpp"
#include <cstring>
#include <limits>

using namespace std;

FileChunkReference64x32::FileChunkReference64x32() noexcept {
  Stp = {};
  Cb = {};
};

size_t FileChunkReference64x32 ::Deserialize(FileChunkReference64x32 &obj, char *pBufSrc) {
  const size_t TYPE_SIZE = 12;

  char *pIndex = pBufSrc;
  memcpy((char *)&obj, pBufSrc, TYPE_SIZE);
  pIndex += TYPE_SIZE;

  return static_cast<size_t>(pIndex - pBufSrc);
};

ostream &operator<<(ostream &os, const FileChunkReference64x32 &ref64x32) {
  return os << setw(sizeof(ref64x32.Stp) * 2) << std::hex
            << (uint64_t)ref64x32.Stp << "-" << setw(sizeof(ref64x32.Cb) * 2)
            << std::hex << (uint32_t)ref64x32.Cb;
};

bool FileChunkReference64x32::IsfcrNil() {
  if (Stp == numeric_limits<uint64_t>::max() &&
      Cb == numeric_limits<uint64_t>::min()) {
    return true;
  }

  return false;
};

bool FileChunkReference64x32::IsfcrZero() {
  if (Stp == numeric_limits<uint64_t>::min() &&
      Cb == numeric_limits<uint64_t>::min()) {
    return true;
  }

  return false;
};