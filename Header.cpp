#include "./common/FileStructure/Header.hpp"
#include "./common/Structures/Primitive.hpp"

using namespace std;

OneNoteFileHeader::OneNoteFileHeader() noexcept {};

/**
 * @brief Deserialize char[] to OneNoteFileHeader class
 * 
 * @param pstart 
 */
size_t OneNoteFileHeader::Deserialize(char *pStart) {
    char *byteIdx = pStart;

    byteIdx += guidFileType.Deserialize(byteIdx);
    byteIdx += guidFile.Deserialize(byteIdx);
    byteIdx += guidLegacyFileVersion.Deserialize(byteIdx);
    byteIdx += guidFileFormat.Deserialize(byteIdx);

    byteIdx += Primitive::Deserialize(ffvLastCodeThatWroteToThisFile, byteIdx);
    byteIdx += Primitive::Deserialize(ffvOldestCodeThatHasWrittenToThisFile, byteIdx);
    byteIdx += Primitive::Deserialize(ffvNewestCodeThatHasWrittenToThisFile, byteIdx);
    byteIdx += Primitive::Deserialize(ffvOldestCodeThatMayReadThisFile, byteIdx);

    byteIdx += FileChunkReference32::Deserialize(fcrLegacyFreeChunkList, byteIdx);
    byteIdx += FileChunkReference32::Deserialize(fcrLegacyTransactionLog, byteIdx);

    byteIdx += Primitive::Deserialize(cTransactionsInLog, byteIdx);
    byteIdx += Primitive::Deserialize(cbLegacyExpectedFileLength, byteIdx);
    byteIdx += Primitive::Deserialize(rgbPlaceholder, byteIdx);

    byteIdx += FileChunkReference32::Deserialize(fcrLegacyFileNodeListRoot, byteIdx);

    byteIdx += Primitive::Deserialize(cbLegacyFreeSpaceInFreeChunkList, byteIdx);

    byteIdx += Primitive::Deserialize(fNeedsDefrag, byteIdx);
    byteIdx += Primitive::Deserialize(fRepairedFile, byteIdx);
    byteIdx += Primitive::Deserialize(fNeedsGarbageCollect, byteIdx);
    byteIdx += Primitive::Deserialize(fHasNoEmbeddedFileObjects, byteIdx);

    byteIdx += guidAncestor.Deserialize(byteIdx);

    byteIdx += Primitive::Deserialize(crcName, byteIdx);
    
    byteIdx += FileChunkReference64x32::Deserialize(fcrHashedChunkList, byteIdx);
    byteIdx += FileChunkReference64x32::Deserialize(fcrTransactionLog, byteIdx);
    byteIdx += FileChunkReference64x32::Deserialize(fcrFileNodeListRoot, byteIdx);
    byteIdx += FileChunkReference64x32::Deserialize(fcrFreeChunkList, byteIdx);

    byteIdx += Primitive::Deserialize(cbExpectedFileLength, byteIdx);
    byteIdx += Primitive::Deserialize(cbFreeSpaceInFreeChunkList, byteIdx);

    byteIdx += guidFileVersion.Deserialize(byteIdx);

    byteIdx += Primitive::Deserialize(nFileVersionGeneration, byteIdx);

    byteIdx += guidDenyReadFileVersion.Deserialize(byteIdx);
    byteIdx += Primitive::Deserialize(grfDebugLogFlags, byteIdx);

    byteIdx += FileChunkReference64x32::Deserialize(fcrDebugLog, byteIdx);
    byteIdx += FileChunkReference64x32::Deserialize(fcrAllocVerificationFreeChunkList, byteIdx);

    byteIdx += Primitive::Deserialize(bnCreated, byteIdx);
    byteIdx += Primitive::Deserialize(bnLastWroteToThisFile, byteIdx);
    byteIdx += Primitive::Deserialize(bnOldestWritten, byteIdx);
    byteIdx += Primitive::Deserialize(bnNewestWritten, byteIdx);
    byteIdx += Primitive::Deserialize(rgbReserved, byteIdx);

    return static_cast<size_t>(byteIdx - pStart);;
};

/**
* @brief Prints out OneNote file header
*
*/
void OneNoteFileHeader::Print() {
    uint8_t wide = 42;

    cout << setfill(' ') << setw(wide) << "guidFileType: " << guidFileType << endl;
    cout << setfill(' ') << setw(wide) << "guidFile: " << guidFile << endl;
    cout << setfill(' ') << setw(wide) << "guidLegacyFileVersion: " << guidLegacyFileVersion << endl;
    cout << setfill(' ') << setw(wide) << "guidFileFormat: " << guidFileFormat << endl;

    cout << setfill(' ') << setw(wide) << "ffvLastCodeThatWroteToThisFile: " 
        << setfill('0')<< "0x" << setw(sizeof(ffvLastCodeThatWroteToThisFile)*2) << ffvLastCodeThatWroteToThisFile << endl;

    cout << setfill(' ') << setw(wide) << "ffvOldestCodeThatHasWrittenToThisFile: " 
        << setfill('0')<< "0x" << setw(sizeof(ffvOldestCodeThatHasWrittenToThisFile)*2) << ffvOldestCodeThatHasWrittenToThisFile << endl;

    cout << setfill(' ') << setw(wide) << "ffvNewestCodeThatHasWrittenToThisFile: " 
        << setfill('0')<< "0x" << setw(sizeof(ffvNewestCodeThatHasWrittenToThisFile)*2) << ffvNewestCodeThatHasWrittenToThisFile << endl;

    cout << setfill(' ') << setw(wide) << "ffvOldestCodeThatMayReadThisFile: " 
        << setfill('0')<< "0x" << setw(sizeof(ffvOldestCodeThatMayReadThisFile)*2) << ffvOldestCodeThatMayReadThisFile << endl;

    cout << setfill(' ') << setw(wide) << "fcrLegacyFreeChunkList: " 
        << setfill('0')<< "0x" << fcrLegacyFreeChunkList << endl;

    cout << setfill(' ') << setw(wide) << "fcrLegacyTransactionLog: " 
        << setfill('0')<< "0x" << fcrLegacyTransactionLog << endl;

    cout << setfill(' ') << setw(wide) << "cTransactionsInLog: " 
        << setfill('0')<< "0x" << setw(sizeof(cTransactionsInLog)*2) << cTransactionsInLog << endl;

    cout << setfill(' ') << setw(wide) << "cbLegacyExpectedFileLength: " 
        << setfill('0')<< "0x" << setw(sizeof(cbLegacyExpectedFileLength)*2) << cbLegacyExpectedFileLength << endl;

    cout << setfill(' ') << setw(wide) << "rgbPlaceholder: " 
        << setfill('0')<< "0x" << setw(sizeof(rgbPlaceholder)*2) << rgbPlaceholder << endl;

    cout << setfill(' ') << setw(wide) << "fcrLegacyFileNodeListRoot: " 
        << setfill('0')<< "0x" << fcrLegacyFileNodeListRoot << endl;

    cout << setfill(' ') << setw(wide) << "cbLegacyFreeSpaceInFreeChunkList: " 
        << setfill('0')<< "0x" << setw(sizeof(cbLegacyFreeSpaceInFreeChunkList)*2) << cbLegacyFreeSpaceInFreeChunkList << endl;

    cout << setfill(' ') << setw(wide) << "fNeedsDefrag: " 
        << setfill('0')<< "0x" << setw(sizeof(fNeedsDefrag)*2) << fNeedsDefrag << endl;
    cout << setfill(' ') << setw(wide) << "fRepairedFile: " 
        << setfill('0')<< "0x" << setw(sizeof(fRepairedFile)*2) << fRepairedFile << endl;
    cout << setfill(' ') << setw(wide) << "fNeedsGarbageCollect: " 
        << setfill('0')<< "0x" << setw(sizeof(fNeedsGarbageCollect)*2) << fNeedsGarbageCollect << endl;
    cout << setfill(' ') << setw(wide) << "fHasNoEmbeddedFileObjects: " 
        << setfill('0')<< "0x" << setw(sizeof(fHasNoEmbeddedFileObjects)*2) << fHasNoEmbeddedFileObjects << endl;

    cout << setfill(' ') << setw(wide) << "guidAncestor: " << guidAncestor << endl;
    cout << setfill(' ') << setw(wide) << "crcName: " 
        << setfill('0')<< "0x" << setw(sizeof(crcName)*2) << crcName << endl;

    cout << setfill(' ') << setw(wide) << "fcrHashedChunkList: " 
        << setfill('0')<< "0x" << fcrHashedChunkList << endl;
    cout << setfill(' ') << setw(wide) << "fcrTransactionLog: " 
        << setfill('0')<< "0x" << fcrTransactionLog << endl;
    cout << setfill(' ') << setw(wide) << "fcrFileNodeListRoot: " 
        << setfill('0')<< "0x" << fcrFileNodeListRoot << endl;
    cout << setfill(' ') << setw(wide) << "fcrFreeChunkList: " 
        << setfill('0')<< "0x" << fcrFreeChunkList << endl;
    
    cout << setfill(' ') << setw(wide) << "cbExpectedFileLength: " 
        << setfill('0')<< "0x" << setw(sizeof(cbExpectedFileLength)*2) << cbExpectedFileLength << endl;
    cout << setfill(' ') << setw(wide) << "cbFreeSpaceInFreeChunkList: " 
        << setfill('0')<< "0x" << setw(sizeof(cbFreeSpaceInFreeChunkList)*2) << cbFreeSpaceInFreeChunkList << endl;
    cout << setfill(' ') << setw(wide) << "guidFileVersion: " << guidFileVersion << endl;

    cout << setfill(' ') << setw(wide) << "nFileVersionGeneration: " 
        << setfill('0')<< "0x" << setw(sizeof(nFileVersionGeneration)*2) << nFileVersionGeneration << endl;
    cout << setfill(' ') << setw(wide) << "guidDenyReadFileVersion: " << guidDenyReadFileVersion << endl;

    cout << setfill(' ') << setw(wide) << "grfDebugLogFlags: " 
        << setfill('0')<< "0x" << setw(sizeof(grfDebugLogFlags)*2) << grfDebugLogFlags << endl;

    cout << setfill(' ') << setw(wide) << "fcrDebugLog: " 
        << setfill('0')<< "0x" << setw(sizeof(fcrDebugLog)*2) << fcrDebugLog << endl;

    cout << setfill(' ') << setw(wide) << "fcrAllocVerificationFreeChunkList: " 
        << setfill('0')<< "0x" << setw(sizeof(fcrAllocVerificationFreeChunkList)*2) << fcrAllocVerificationFreeChunkList << endl;

    cout << setfill(' ') << setw(wide) << "bnCreated: " 
        << setfill('0')<< "0x" << setw(sizeof(bnCreated)*2) << bnCreated << endl;

    cout << setfill(' ') << setw(wide) << "bnLastWroteToThisFile: " 
        << setfill('0')<< "0x" << setw(sizeof(bnLastWroteToThisFile)*2) << bnLastWroteToThisFile << endl;

    cout << setfill(' ') << setw(wide) << "bnOldestWritten: " 
        << setfill('0')<< "0x" << setw(sizeof(bnOldestWritten)*2) << bnOldestWritten << endl;

    cout << setfill(' ') << setw(wide) << "bnNewestWritten: " 
        << setfill('0')<< "0x" << setw(sizeof(bnNewestWritten)*2) << bnNewestWritten << endl;

    cout << setfill(' ') << setw(wide) << "rgbReserved: "; 
     
    uint8_t counter = {0};
    for (auto el: rgbReserved) {
        if ( ((counter++) % 16) == 0) {
            cout << setfill(' ') << setw(wide + 2) << endl;
        }
       cout << "0x" << setfill('0') << hex << setw(sizeof(char)*2) << (int)(unsigned char)el << " ";
    };

    cout << endl;
};
