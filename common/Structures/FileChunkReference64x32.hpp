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

#endif

/**
 * @brief 

  public override bool IsfcrNil()
        {
            if (this.Stp == ulong.MaxValue && this.Cb == uint.MinValue)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        /// <summary>
        /// This method is used the check the instance whether is fcrZero.
        /// </summary>
        /// <returns>return the whether the instance is fcrZero.</returns>
        public override bool IsfcrZero()
        {
            if (this.Stp == ulong.MinValue && this.Cb == uint.MinValue)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
 * 
 */