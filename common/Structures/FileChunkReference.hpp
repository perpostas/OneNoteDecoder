#include <cstddef>
#include <cstring>
#include <ostream>
#include <iomanip>

#include "FileChunkReference32.hpp"

/**
  * @brief Basic Class for FileChunkReference* classes
  * Pure virtual
*/
class FileChunkReference {
    private:

    public:
      // This method is used to deserialize the FileChunkReference object 
      // from the specified byte array
      virtual size_t Deserialize() = 0;

      // Return the whether the instance is fcrNil
      virtual bool IsfcrNil() = 0;

      // Return the whether the instance is IsfcrZero
      virtual bool IsfcrZero() = 0;
};