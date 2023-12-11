#include <gtest/gtest.h>
#include "../../Structures/Guid.hpp"

TEST(Guid, ToString0) {
    // Zero guid
    Guid test0;
    // Expecting to be "00000000-0000-0000-0000-000000000000"
    EXPECT_EQ(
        Guid::ToString(test0), 
        "00000000-0000-0000-0000-000000000000"
    );
}

TEST(Guid, ToString1) {
    uint8_t data [] = {0xb5, 0x7e, 0x74, 0x27, 0xce, 0xc5, 0x56, 0x0c};
    Guid test0 ( (uint32_t) 0x01e75c83, (uint16_t) 0xc6f5, (uint16_t) 0x4192, (char*)data);
    // Expecting to be "1e75c83-c6f5-4192-b57e-7427cec5560c"
    EXPECT_EQ(
        Guid::ToString(test0), 
        "01e75c83-c6f5-4192-b57e-7427cec5560c"
    );
}

TEST(Guid, Compare0) {
    Guid test0, test1;
    // Comparing two zero guids
    EXPECT_TRUE(Guid::Compare(test0, test1));
}

TEST(Guid, Compare1) {
    uint8_t data [] = {0xb5, 0x7e, 0x74, 0x27, 0xce, 0xc5, 0x56, 0x0c};
    
    Guid test0, 
        test1 ( (uint32_t) 0x01e75c83, (uint16_t) 0xc6f5, (uint16_t) 0x4192, (char*) data);
    // Comparing two different guids
    EXPECT_FALSE(Guid::Compare(test0, test1));
}

TEST(Guid, Deserialize0) {
    // Zero guid
    Guid testGuid;

    uint8_t data[] = { 0xe4, 0x52, 0x5c, 0x7b, 0x8c, 0xd8, 0xa7, 0x4d, 0xae, 0xb1, 0x53, 0x78, 0xd0, 0x29, 0x96, 0xd3 };
    auto size = testGuid.Deserialize((char*) data);

    // Deserialized Guid should be 16 bytes
    EXPECT_EQ(size, 16);

    // Compare equality of desialized guid
    // And a predefined guid "7b5c52e4-d88c-4da7-aeb1-5378d02996d3"
    EXPECT_EQ(
        Guid::ToString(testGuid),
        //"e4525c7b-8cd8-a74d-aeb1-5378d02996d3"
        "7b5c52e4-d88c-4da7-aeb1-5378d02996d3"
    );
}