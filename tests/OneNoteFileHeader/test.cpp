#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <new>
#include "../../FileStructure/Header.hpp"
#include "../../Helpers/BinFile.hpp"

using namespace std;

const uint HEADER_SIZE = 1024;

int main(int argc, char *argv[]) {
    cout << "Running test: " << argv[0] << endl;

    if (argc != 2) {
        cerr << "Error: Please provide a filename to read" << endl;
        exit(EXIT_FAILURE);
    }

    string filename = argv[1];
    BinFile binFile(filename);

    char *pBytesArray = binFile.Read(HEADER_SIZE);
    if (pBytesArray == NULL) {
        cerr << "BinFile::Read returned null pointer" << endl;
        exit(EXIT_FAILURE);
    }
    binFile.printHex(pBytesArray);

    OneNoteFileHeader header;
    auto len = header.Deserialize(pBytesArray);
    
    cout << "Header length: " << dec << len << endl;
    header.Print();

    delete [] pBytesArray;

    exit(EXIT_SUCCESS);
};