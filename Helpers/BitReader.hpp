#include <bitset>

template <typename T>
class BitReader {
    private:
        std::bitset<sizeof(T) * 8> bs;
        size_t pos;
        T number;

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

        std::bitset<sizeof(T)*8> getBits() {
            return bs;
        }

        /**
        * @brief Reading N-number of bits
        * returns the same type as provided in constructor  
        * keep bit position index from previous function call
        * 
        * @param nBts 
        * @return T 
        */
        T Read(uint nBts) {
            pos += nBts;
            // Make copy of initial bitset
            std::bitset<sizeof(T)*8> tbs(bs);
            
            // Calculation shift size
            size_t shift = sizeof(T) * 8 - pos;
            std::bitset<sizeof(T)*8> ret = (tbs >>= shift);

            // Save shifted biset to the private bs class variable
            bs = (bs << pos) >> pos;
            
            return static_cast<T>(ret.to_ulong());
        }
};