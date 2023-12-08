/**
 * @file BitReader.hpp
 * @author Alpa (you@domain.com)
 * @brief A wrapper over a standart C++ bitstream
 * @version 0.1
 * @date 2023-12-06
 * 
 * @copyright Copyleft 2023
 * 
 */

#include <bitset>

template <typename T>
class BitReader {
    private:
        uint pos;
        T number;
        std::bitset< sizeof(T)*8 > bs;

    public:
        /**
        * @brief Construct a new Bit Reader object
        * num - number to convert to bitset
        * @param num 
        */
        BitReader(T num) {
            number = num;
            pos = 0;
            bs |= num;
        }

        /**
        * @brief Reading N-number of bits
        * returns the same type as in constructor parameter  
        * keep previous position from previous function call
        * 
        * @param nBts 
        * @return T 
        */
        T Read(uint nBts) {
            pos += nBts;
            std::bitset< sizeof(T)*8 > tbs(bs);
            return static_cast<T>( (tbs >>= (tbs.size() - pos)).to_ulong() );
        }
};