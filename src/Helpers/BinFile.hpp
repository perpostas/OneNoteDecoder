#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>


/**
 * @brief Helper class for unit tests
 * - Opens a file in bin mode
 * - Reads N bytes from file
 * - Prints out bytes
 */
class BinFile {
    private:
        //std::string fileName;
        //uint bytesNum;
        //std::string content;

    public:
        /**
        * @brief Construct a new Bin File object
        * 
        * @param name 
        */
        BinFile() noexcept;

        /**
         * @brief ReadToContainer is a function to read binary file content into STL container
         * 
         * @param startPos 
         * @param endPos 
         * @return std::string 
         */
        static const std::vector<uint8_t> ReadToBytesVector(std::string filename) {
            std::ifstream in(filename, std::ios::in | std::ios::binary);
            if (in) {
                // 3-times slower than in.Read
                // https://insanecoding.blogspot.com/2011/11/how-to-read-in-file-in-c.html
                // https://stackoverflow.com/questions/63789443/i-cant-understand-the-use-of-stdistream-iterator

                std::istreambuf_iterator<char> 
                    itBegin(in), 
                    itEnd;

                return std::vector<uint8_t> (itBegin, itEnd);;
            }
            
            throw(errno);
        }


        /**
         * @brief Reads N bytes from bin file
         * 
         * @param nBytes 
         * @return char* 
         */
        const static char* ReadToBufferArray(std::string filename, uint nBytes) {
            std::ifstream oneFile;
            std::streampos fileSize;
            
            // Unit bytesNum private variable
            // bytesNum = nBytes;
            
            // Pointer to buffer
            char *buffer = NULL;

            oneFile.open(filename, std::ios::in | std::ios::binary | std::ios::ate);
            std::cerr << "Opening file: " << filename << " ... ";
            if (oneFile.is_open()) {
                std::cerr << "OK" << std::endl;

                // Calculate file size
                fileSize = oneFile.tellg();
                if (nBytes > fileSize) {
                    std::cerr 
                        << "ERROR: Cannot read more bytes than file size: "
                        << "Requested to read: " << nBytes << ", "
                        << "File size: " << fileSize
                        << std::endl;
                    return NULL;
                }

                // Get memory block for nBytes
                buffer = new char [nBytes];

                oneFile.seekg(0, std::ios::beg);
                oneFile.read(buffer, fileSize);
                std::cerr << "File fileSize: " << (fileSize) << " bytes." << std::endl;
                oneFile.close();

            } else {
                // Something wrong happened and file was not opened
                if (buffer != NULL) delete[] buffer;
                return NULL;
            }

            return buffer;
        }


        /**
         * @brief Prints out vector of bytes to cout
         * 
         * @tparam std::vector<uint8_t> &vec 
         * @param str 
         */
        const static void PrintToHex(const std::vector<uint8_t> &vec) {
            uint8_t counter = {0};
            const uint indentLeft = 0;

            for (auto &el: vec) {
                if ( ((counter++) % 16) == 0) {
                    std::cout << std::setfill(' ') << std::setw(indentLeft + 2) << std::endl;
                }
                std::cout << "0x" << std::setfill('0') << std::hex << std::setw(sizeof(char)*2) << (int)(unsigned char)el << " ";
            }
            std::cout << std::endl;
        }


        /**
         * @brief Prints bin file in hex mode
         * 
         * @param bytes 
         */
        void PrintToHex(const char *bytes, uint bytesNum) {
            for (uint  i = 0; i < bytesNum; ++i) {
                if ( i % 16 == 0) {
                    std::cout << std::setfill(' ') << std::setw(2) << std::endl;
                }
                std::cout << "0x" 
                            << std::setfill('0') 
                            << std::hex << std::setw(sizeof(char)*2) 
                            << (int)(unsigned char) bytes[i] 
                            << " ";
            }
            
            std::cout << std::endl;
        }
};