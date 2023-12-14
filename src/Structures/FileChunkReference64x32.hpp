#include <cstring>
#include <limits>
#include <sys/types.h>
#include <ostream>
#include <iomanip>

using namespace std;

#ifndef FileChunkReference64x32_H
#define FileChunkReference64x32_H

/**
 * @brief 
 *  u_int64_t Stp;
    u_int32_t Cb;
 */
class FileChunkReference64x32 {
    public:
    FileChunkReference64x32() noexcept;
      static size_t Deserialize(FileChunkReference64x32 &obj, char *pBufSrc);

      bool IsfcrNil();
      bool IsfcrZero();

      u_int64_t Stp = {};
      u_int32_t Cb = {};

    private:
      friend ostream &operator<<(ostream &os, const FileChunkReference64x32 &ref32);
};

using namespace std;

inline FileChunkReference64x32::FileChunkReference64x32() noexcept {
  Stp = {};
  Cb = {};
};

inline size_t FileChunkReference64x32 ::Deserialize(FileChunkReference64x32 &obj, char *pBufSrc) {
  const size_t TYPE_SIZE = 12;

  char *pIndex = pBufSrc;
  memcpy((char *)&obj, pBufSrc, TYPE_SIZE);
  pIndex += TYPE_SIZE;

  return static_cast<size_t>(pIndex - pBufSrc);
};

inline ostream &operator<<(ostream &os, const FileChunkReference64x32 &ref64x32) {
  return os << setw(sizeof(ref64x32.Stp) * 2) << std::hex
            << (uint64_t)ref64x32.Stp << "-" << setw(sizeof(ref64x32.Cb) * 2)
            << std::hex << (uint32_t)ref64x32.Cb;
};

inline bool FileChunkReference64x32::IsfcrNil() {
  if (Stp == numeric_limits<uint64_t>::max() &&
      Cb == numeric_limits<uint64_t>::min()) {
    return true;
  }

  return false;
};

inline bool FileChunkReference64x32::IsfcrZero() {
  if (Stp == numeric_limits<uint64_t>::min() &&
      Cb == numeric_limits<uint64_t>::min()) {
    return true;
  }

  return false;
};

#endif
