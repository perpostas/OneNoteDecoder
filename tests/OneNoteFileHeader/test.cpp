#include "../../common/FileStructure/Header.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <new>

using namespace std;
const uint HEADER_SIZE = 1024;

void printHex(char *bytes) {
    for (uint  i = 0; i < HEADER_SIZE; ++i) {
        if ( i % 16 == 0) {
            cout << setfill(' ') << setw(2) << endl;
        }
       cout << "0x" << setfill('0') << hex << setw(sizeof(char)*2) << (int)(unsigned char) bytes[i] << " ";
    };
    cout << endl;
}

char* readFile(string filename) {
    ifstream oneFile;
    streampos size;
    
    char *memblock = NULL;

    oneFile.open(filename, ios::in | ios::binary | ios::ate);
    cerr << "Opening file: " << filename << " ... ";
    if (oneFile.is_open()) {
        cerr << "OK" << endl;

        // Calculate file size
        size = oneFile.tellg();
        if (size != HEADER_SIZE) {
            // Header must be 1024
            cerr << "ERROR: Header must be 1024 in length" << endl;
            return NULL;
        }

        // Get memory block for whole file
        memblock = new char [size];

        oneFile.seekg(0, ios::beg);
        oneFile.read(memblock, size);
        cerr << "File size: " << (size) << " bytes." << endl;
        oneFile.close();

        printHex(memblock);

    } else {
        // Something wrong happened and file was not opened
        if (memblock != NULL) delete[] memblock;
        return NULL;
    }

    return memblock;
};

int main(int argc, char *argv[]) {
    cout << "Running test: " << argv[0] << endl;

    if (argc != 2) {
        cerr << "Error: Please provide a filename to read" << endl;
        exit(EXIT_FAILURE);
    }

    char *pBytesArray = readFile(argv[1]);
    if (pBytesArray == NULL) {
        cerr << "readFile returned null pointer" << endl;
        exit(EXIT_FAILURE);
    }
    OneNoteFileHeader header;
    auto len = header.Deserialize(pBytesArray);
    cout << "Header len: " << dec << len << endl;
    header.Print();

    delete [] pBytesArray;

    exit(EXIT_SUCCESS);
};