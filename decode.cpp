#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <unistd.h>

#include "FileStructure/OneNoteRevisionStore.hpp"
#include "Helpers/LogDuration.hpp"

#define DEBUG false

using namespace std;

int ReadFile(string filename) {
  std::ifstream oneFile;
  streampos size;
  //OneNoteFileHeader memblock;
  char *memblock;

  cout << "Header class size: " << sizeof(OneNoteFileHeader) << endl;
  LogDuration ld("Decode:");

  oneFile.open(filename, ios::in | ios::binary | ios::ate);
  cerr << "Opening file: " << filename << " ... ";
  if (oneFile.is_open()) {
    cerr << "OK" << endl;

    // Calculate file size
    size = oneFile.tellg();
    // Get memory block for whole file
    memblock = new char [size];
    oneFile.seekg(0, ios::beg);
    oneFile.read(memblock, sizeof(OneNoteFileHeader));
  
    OneNoteRevisionStoreFile storeFile;  
    storeFile.Deserialize(memblock);
    storeFile.Header.Print();

    //OneNoteFileHeader header;
    //header.Deserialize(memblock);
    //header.Print();

    // (0xff & (unsigned int)memblock[i]);

    cerr << "File size: " << (size) << " bytes." << endl;
    oneFile.close();
    cerr << "File is closed." << endl;
    delete [] memblock;

  } else {
    cerr << "NOK" << endl;
    return 1;
  }

  return 0;
}

int main(int argc, char *argv[]) {
  int opt;
  std::string oneFileName = {};
  std::ifstream oneFile;

  while ((opt = getopt(argc, argv, "f:")) != -1) {
    switch (opt) {
    case 'f':
      oneFileName = optarg;
      if (DEBUG == true) cout << "Infile: " << oneFileName << endl;
      ReadFile(oneFileName);
      break;
    default: /* '?' */
      cout << "Usage: " << argv[0] << " -f input.one" << endl;
      exit(EXIT_FAILURE);
    }
  }

  if (argc == 0) {
    cerr << "Usage: " << argv[0] << " -f input.one" << endl;
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}