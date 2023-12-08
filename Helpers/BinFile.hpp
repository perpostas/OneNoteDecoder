#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


/**
 * @brief Helper class for unit tests
 * - Opens a file in bin mode
 * - Reads N bytes from file
 * - Prints out bytes
 */
class BinFile {
    private:
        std::string fileName;
        uint bytesNum;

    public:
        /**
        * @brief Construct a new Bin File object
        * 
        * @param name 
        */
        BinFile(std::string name) {
            fileName = name;
        };

        /**
         * @brief Reads N bytes from bin file
         * 
         * @param nBytes 
         * @return char* 
         */
        char* Read(uint nBytes) {
            std::ifstream oneFile;
            std::streampos fileSize;
            
            // Unit bytesNum private variable
            bytesNum = nBytes;
            
            // Pointer to buffer
            char *buffer = NULL;

            oneFile.open(fileName, std::ios::in | std::ios::binary | std::ios::ate);
            std::cerr << "Opening file: " << fileName << " ... ";
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
        };

        /**
         * @brief Prints bin file in hex mode
         * 
         * @param bytes 
         */
        void printHex(char *bytes) {
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