#include <cstdint>
#include <cstring>
#include <iomanip>

using namespace std;

typedef uint32_t uint32;
typedef uint16_t uint16;

/**
 * @brief Guid class:
    uint32_t Data1;
    uint16_t Data2;
    uint16_t Data3;
    char Data4[8];
 */
class Guid {
public:
  Guid() noexcept;
  Guid(uint32 guidChunk1, uint16_t guidChunk2, uint16_t guidChunk3,
       char guidChunk4[8]);
  size_t Deserialize(char *begin);
  bool CompareTo(Guid &guid);

  uint32_t Data1;
  uint16_t Data2;
  uint16_t Data3;
  char Data4[8];

private:
  friend ostream &operator<<(ostream &os, const Guid &guid);
};