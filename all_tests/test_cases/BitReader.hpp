#include <gtest/gtest.h>
#include <cstdint>
#include "../../Helpers/BitReader.hpp"

#include <iostream>

const uint32_t bitmask = 0xc4f4f7f5;
BitReader<uint32_t> br(bitmask);

/**
                                   fNid        size       stp    cb    base   reserved
                                -------------------------------------------------------   
                                 10 bits      13 bits    2bits  2bits  4bits  1bit  
    32 bit integer 0xc4f4f7f5 - 1100010011 1101001111011   11    11    1010   1
    -----------------------------------------------------------------------------------
    10 first bits (from left ro right) 1100010011    - 0x313 - 787 (in dec)
    13 bits                            1101001111011 - 0x15173
    2 bits                                        11 - 0x3
    2 bits                                        11 - 0x3
    4 bits                                      1010 - 0xa
    1 bit                                          1 - 0x1

*/

/**
        size     = br.Read(13),
        stp      = br.Read(2),
        cb       = br.Read(2),
        base     = br.Read(4),
        reserved = br.Read(1);
*/

TEST(BitReader, Read) {
    std::cout << br.getBits() << std::endl;
    uint32_t fnId = br.Read(10);
    EXPECT_EQ(fnId, 0x313);


    uint32_t size = br.Read(13);
    EXPECT_EQ(size, 0x1A7B);

    uint32_t stp = br.Read(2);
    EXPECT_EQ(stp, 0x03);

    uint32_t cb = br.Read(2);
    EXPECT_EQ(cb, 0x03);

    uint32_t base = br.Read(4);
    EXPECT_EQ(base, 0x0a);

    uint32_t reserved = br.Read(1);
    EXPECT_EQ(reserved, 0x01);    
}