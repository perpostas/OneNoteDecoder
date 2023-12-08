#include <cstring>
#include <sys/types.h>
#include <ostream>
#include <iomanip>

using namespace std;

/**
 * @brief 
 *  u_int32_t Stp;
 *  u_int32_t Cb;
 */
class FileChunkReference32 {
    public:
      static size_t Deserialize(FileChunkReference32 &obj, char *src);
      
      u_int32_t Stp;
      u_int32_t Cb;

    private:
      friend ostream &operator<<(ostream &os, const FileChunkReference32 &ref32);
};

using namespace std;

/**
 * @brief 
 * 
 * @param obj 
 * @param src 
 * @return size_t 
 */
inline size_t FileChunkReference32::Deserialize(FileChunkReference32 &obj, char *src) {
  const size_t TYPE_SIZE = 8;

  char *idx = src;
  memcpy((char *)&obj, src, TYPE_SIZE);
  idx += TYPE_SIZE;

  return static_cast<size_t>(idx - src);
};

/**
 * @brief Operator << redefinition for FileChunkReference32
 * 
 * @param os 
 * @param ref32 
 * @return ostream& 
 */
inline ostream &operator<<(ostream &os, const FileChunkReference32 &ref32) {
  return os 
    << setw(sizeof(ref32.Stp)*2) << std::hex << (uint32_t)ref32.Stp 
    << "-" 
    << setw(sizeof(ref32.Cb)*2) << std::hex << (uint32_t)ref32.Cb;
};
