#include <cstdint>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sys/types.h>

#include "../Structures/FileChunkReference32.hpp"
#include "../Structures/FileChunkReference64x32.hpp"
#include "../Structures/Guid.hpp"

using namespace std;

/**
 * @brief 
 * 
 */
class OneNoteFileHeader {
  public:
    OneNoteFileHeader() noexcept;

    /**
    * @brief Deserialize bytes from char[] to OneNoteFileHeader struct
    * 
    * @param pstart 
    * @return size_t 
    */
    size_t Deserialize(char *pstart);
    void Print();

    Guid guidFileType;
    Guid guidFile;
    Guid guidLegacyFileVersion;
    Guid guidFileFormat;
    uint32_t ffvLastCodeThatWroteToThisFile;
    uint32_t ffvOldestCodeThatHasWrittenToThisFile;
    uint32_t ffvNewestCodeThatHasWrittenToThisFile;
    uint32_t ffvOldestCodeThatMayReadThisFile;
    FileChunkReference32 fcrLegacyFreeChunkList;
    FileChunkReference32 fcrLegacyTransactionLog;
    uint32_t cTransactionsInLog;
    uint32_t cbLegacyExpectedFileLength;
    uint64_t rgbPlaceholder;
    FileChunkReference32 fcrLegacyFileNodeListRoot;
    uint32_t cbLegacyFreeSpaceInFreeChunkList;

    uint8_t fNeedsDefrag;
    uint8_t fRepairedFile;
    uint8_t fNeedsGarbageCollect;
    uint8_t fHasNoEmbeddedFileObjects;

    Guid guidAncestor;
    uint32_t crcName;
    FileChunkReference64x32 fcrHashedChunkList;
    FileChunkReference64x32 fcrTransactionLog;
    FileChunkReference64x32 fcrFileNodeListRoot;
    FileChunkReference64x32 fcrFreeChunkList;

    uint64_t cbExpectedFileLength;
    uint64_t cbFreeSpaceInFreeChunkList;
    Guid guidFileVersion;

    uint64_t nFileVersionGeneration;
    Guid guidDenyReadFileVersion;

    uint32_t grfDebugLogFlags;
    FileChunkReference64x32 fcrDebugLog;

    FileChunkReference64x32 fcrAllocVerificationFreeChunkList;
    uint32_t bnCreated;
    uint32_t bnLastWroteToThisFile;
    uint32_t bnOldestWritten;
    uint32_t bnNewestWritten;

    char rgbReserved[728];
};