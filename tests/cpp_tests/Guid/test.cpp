#include <cstdint>
#include <iostream>
#include <ostream>
#include <assert.h> 
#include "../../Structures/Guid.hpp"

using namespace std;

int main() {
    unsigned char Data4[8] = { 0xb5, 0x7e, 0x74, 0x27, 0xce, 0xc5, 0x56, 0x0c};
    Guid zeroGuid0, zeroGuid1;
    Guid guid0((uint32_t) 0x01e75c83, (uint16_t) 0xc6f5, (uint16_t) 0x4192, (char*)Data4);
    cout << "zeroGuid0   (Guid): " << zeroGuid0 << endl;
    cout << "zeroGuid1   (Guid): " << zeroGuid1 << endl;
    cout << "Guid0:  (Guid) " << guid0 << endl;;

    cout << Guid::Compare(zeroGuid0, zeroGuid1) << " - Should be true" << endl;
    cout << Guid::Compare(zeroGuid0, guid0) << " - Should be false" << endl;
    cout << Guid::Compare(guid0, guid0) << " - Should be true" << endl;
    cout << Guid::ToString(zeroGuid0) << " - Should be 00000000-0000-0000-0000-000000000000" << endl;

    assert(Guid::Compare(zeroGuid0, zeroGuid1) == true && "Comparing guid0 with guid2 should be true");
    assert(Guid::Compare(zeroGuid0, guid0) == false && "Comparing guid0 with guid1 should be false");
    assert(Guid::Compare(guid0, guid0) == true && "Comparing guid0 with guid0 should be true");
    assert( (Guid::ToString(zeroGuid0) != Guid::ToString(guid0)) == true && "Comparing (!=) two diffirent guids should be true");
    assert( (Guid::ToString(zeroGuid0) == Guid::ToString(zeroGuid1)) == true && "Comparing (==) two zero guids should be true");
};