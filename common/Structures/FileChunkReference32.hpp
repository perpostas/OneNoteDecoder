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
