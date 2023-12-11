#include <cstdint>
#include <cstring>
#include <iomanip>

using namespace std;

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
  Guid(uint32_t guidChunk1, uint16_t guidChunk2, uint16_t guidChunk3,
       char guidChunk4[8]);
  size_t Deserialize(char *begin);
  static string ToString(const Guid &guid);
  static bool Compare(const Guid &guid1, const Guid &guid2);

  uint32_t Data1;
  uint16_t Data2;
  uint16_t Data3;
  uint8_t Data4[8];

private:
  friend ostream &operator<<(ostream &os, const Guid &guid);
};


/**
 * @brief Construct a new Guid:: Guid object
 * 
 * @param Data1 
 * @param Data2 
 * @param Data3 
 * @param Data4 
 */

inline Guid::Guid() noexcept {
  Data1 = {0};
  Data2 = {0};
  Data3 = {0};
  memset(Data4, 0, sizeof(Data4));
};

inline Guid::Guid(uint32_t guidChunk1, uint16_t guidChunk2, uint16_t guidChunk3, char guidChunk4[8]) {
  Data1 = guidChunk1;
  Data2 = guidChunk2;
  Data3 = guidChunk3;
  memcpy(Data4, guidChunk4, sizeof(Data4));
};

/**
 * @brief 
 * 
 * @param begin 
 * @return size_t 
 */
inline size_t Guid::Deserialize(char *begin) {
  // Current buffer pointer position
  char *byteIndex = begin;

  // Fill in structure
  memcpy((char *) &Data1, byteIndex, sizeof(Data1));
  byteIndex += sizeof(Data1);
  memcpy((char *) &Data2, byteIndex, sizeof(Data2));
  byteIndex += sizeof(Data2);
  memcpy((char *) &Data3, byteIndex, sizeof(Data3));
  byteIndex += sizeof(Data3);
  memcpy((char *) &Data4, byteIndex, sizeof(Data4));
  byteIndex += sizeof(Data4);

  // Return a length of Guid structure
  return static_cast<size_t>(byteIndex - begin);
};

/**
 * @brief 
 * 
 * @param guid 
 * @return true 
 * @return false 
 */
inline bool Guid::Compare(const Guid &g1, const Guid &g2) {
  int res = memcmp(&g1, &g2, sizeof(Guid));
  return (res == 0) ? true : false;
};


inline string Guid::ToString(Guid const &guid) {
  cout << guid << endl;
  std::ostringstream ss;
  ss << guid;
  return ss.str();
};


inline ostream &operator<<(ostream &os, const Guid &guid) {
  return os 
    << setfill('0') << setw(8) << hex << guid.Data1
    << "-" 
    << setfill('0') << setw(4) << hex << guid.Data2 
    << "-" 
    << setfill('0') << setw(4) << hex << guid.Data3
    << "-" 
    << setfill('0') << std::setw(2) << hex << (0xff & (uint16_t)guid.Data4[0]) 
    << setfill('0') << std::setw(2) << hex << (0xff & (uint16_t)guid.Data4[1])
    << "-" 
    << setfill('0') << std::setw(2) << hex << (0xff & (uint16_t)guid.Data4[2]) 
    << setfill('0') << std::setw(2) << hex << (0xff & (uint16_t)guid.Data4[3])
    << setfill('0') << std::setw(2) << hex << (0xff & (uint16_t)guid.Data4[4]) 
    << setfill('0') << std::setw(2) << hex << (0xff & (uint16_t)guid.Data4[5])
    << setfill('0') << std::setw(2) << hex << (0xff & (uint16_t)guid.Data4[6]) 
    << setfill('0') << std::setw(2) << hex << (0xff & (uint16_t)guid.Data4[7]);
};