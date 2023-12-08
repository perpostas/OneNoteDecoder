#include <cstdint>
#include <iostream>
#include <ostream>
#include <assert.h> 
#include "../../Structures/Guid.hpp"

using namespace std;

int main() {
    unsigned char Data4[8] = { 0xb5, 0x7e, 0x74, 0x27, 0xce, 0xc5, 0x56, 0x0c};
    Guid test0;
    Guid test1((uint32_t) 0x01e75c83, (uint16_t) 0xc6f5, (uint16_t) 0x4192, (char*)Data4);
    cout << "Guid0: " << test0 << endl;
    cout << "Guid1: " << test1 << endl;

    cout << test0.CompareTo(test1) << " - Should be false" << endl;
    cout << test0.CompareTo(test0) << " - Should be true" << endl;
    cout << test1.CompareTo(test0) << " - Should be false" << endl;
    cout << test1.CompareTo(test1) << " - Should be true" << endl;

    assert(test0.CompareTo(test1) == false && "Comparing guid0 with guid1 should be false");
    assert(test0.CompareTo(test0) == true && "Comparing guid0 with guid0 should be true");
}

