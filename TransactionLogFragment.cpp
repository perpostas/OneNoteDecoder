#include <cstddef>
#include <cstdint>
#include "./common/Structures/TransactionLogFragment.hpp"


TransactionLogFragment::TransactionLogFragment(uint32_t len) {
    size = len;
    
    nextFragment = {};
};

size_t TransactionLogFragment::Deserialize(char *pStart, size_t iOffset) {
    char *pIndex = pStart + iOffset;
    auto count = (size - 12) / 8;    

    for (size_t i = 0; i < count; ++i) {
        TransactionEntry transactionEntry;
        pIndex += transactionEntry.Deserialize(pStart, iOffset);
        sizeTable.push_back(transactionEntry);
    };

    pIndex += FileChunkReference64x32::Deserialize(nextFragment, pStart);
    
    return static_cast<size_t>(pIndex - pStart);    
};
