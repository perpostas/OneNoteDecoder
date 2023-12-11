#include <iostream>
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

    vector<uint8_t> binaryFileContent = binFile.ReadToContainer();
    binFile.PrintToHex(binaryFileContent);

    exit(EXIT_SUCCESS);
};
