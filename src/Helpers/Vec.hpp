#include <cstdint>
#include <vector>

/**
 * @brief Class to convert Vector to UINT
 * Great respect to Uncle Vova :)
 */
class Vec {
    const auto ToUint(std::vector<uint8_t> &v, std::size_t digitsNum) {
        uint32_t big = 0x0;

        // Number of bytes to convert should not be more than vector size
        if (digitsNum > v.size()) digitsNum = v.size();
        else if (digitsNum <= 0) digitsNum = 1; // Minimum 1 byte

        for (unsigned i=0; i < digitsNum; i++) {
            big += v.at(i);
            if (i != digitsNum - 1) big = big << 8;
        }

        return big;
    }
};