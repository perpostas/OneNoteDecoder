#include <sys/types.h>

#ifndef FileChunkReference64_H
#define FileChunkReference64_H

/**
 * @brief 
 *  u_int64_t Stp;
 *  u_int64_t Cb;
 * 
 */
class FileChunkReference64 {
    public:
        static size_t Deserialize(FileChunkReference64 &obj, char *src);
        size_t Deserialize(char *src);
        u_int64_t Stp;
        u_int64_t Cb;
};

#endif