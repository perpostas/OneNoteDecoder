#include <cstring>

#ifndef Primitive_H
#define Primitive_H

/**
 * @brief A wrapper of memcpy for primitive types
 * 
 */
class Primitive {
    public:
        template <typename T>
        static size_t Deserialize(T &var, char *src);
};

template <typename T>
size_t Primitive::Deserialize(T &var, char *src) {
  char *idx = src;
  memcpy((char *)&var, src,sizeof(var));
  idx += sizeof(var);

  return static_cast<size_t>(idx - src);
};

#endif