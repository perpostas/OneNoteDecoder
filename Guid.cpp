#include <iostream>
#include <ostream>
#include "./common/Structures/Guid.hpp"

using namespace std;

/**
 * @brief Construct a new Guid:: Guid object
 * 
 * @param Data1 
 * @param Data2 
 * @param Data3 
 * @param Data4 
 */

Guid::Guid() noexcept {
  this->Data1 = {};
  this->Data2 = {};
  this->Data3 = {};
  this->Data4[8] = {};
};

Guid::Guid(uint32 guidChunk1, uint16_t guidChunk2, uint16_t guidChunk3, char guidChunk4[8]) {
  this->Data1 = guidChunk1;
  this->Data2 = guidChunk2;
  this->Data3 = guidChunk3;
  memcpy(this->Data4, guidChunk4, sizeof(this->Data4));
};

/**
 * @brief 
 * 
 * @param begin 
 * @return size_t 
 */
size_t Guid::Deserialize(char *begin) {
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
bool Guid::CompareTo(Guid &guid) {
  return memcmp(this, &guid, sizeof(Guid)) == 0 ? true: false;
};

ostream &operator<<(ostream &os, const Guid &guid) {
  return os 
    << setfill('0') << setw(8) << hex << guid.Data1
    << "-" 
    << setfill('0') << setw(4) << hex << guid.Data2 
    << "-" 
    << setfill('0') << setw(4) << hex << guid.Data3
    << "-" 
    << setfill('0') << std::setw(2) << hex << (0xff & (uint16)guid.Data4[0]) 
    << setfill('0') << std::setw(2) << hex << (0xff & (uint16)guid.Data4[1])
    << "-" 
    << setfill('0') << std::setw(2) << hex << (0xff & (uint16)guid.Data4[2]) 
    << setfill('0') << std::setw(2) << hex << (0xff & (uint16)guid.Data4[3])
    << setfill('0') << std::setw(2) << hex << (0xff & (uint16)guid.Data4[4]) 
    << setfill('0') << std::setw(2) << hex << (0xff & (uint16)guid.Data4[5])
    << setfill('0') << std::setw(2) << hex << (0xff & (uint16)guid.Data4[6]) 
    << setfill('0') << std::setw(2) << hex << (0xff & (uint16)guid.Data4[7]);
};