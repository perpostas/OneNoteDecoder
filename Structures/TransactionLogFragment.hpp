/**
 * @file TransactionLogFragment.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-04
 * 
 * @copyright Copyright (c) 2023
 * 

 namespace Microsoft.Protocols.TestSuites.MS_ONESTORE
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;


    /// <summary>
    /// This class is used to represent the TransactionLogFragment structure.
    /// </summary>
    public class TransactionLogFragment
    {
        private uint size = 0;

        public TransactionLogFragment(uint size)
        {
            this.size = size;
        }
        /// <summary>
        /// Gets or sets the value of sizeTable field.
        /// </summary>
        public TransactionEntry[] sizeTable { get; set; }
        /// <summary>
        /// Gets or sets the value of nextFragment field.
        /// </summary>
        public FileChunkReference64x32 nextFragment { get; set; }

        /// <summary>
        /// This method is used to convert the element of TransactionLogFragment object into a byte List.
        /// </summary>
        /// <returns>Return the byte list which store the byte information of TransactionLogFragment</returns>
        public List<byte> SerializeToByteList()
        {
            List<byte> byteList = new List<byte>();

            foreach(TransactionEntry entry in this.sizeTable)
            {
                byteList.AddRange(entry.SerializeToByteList());
            }

            byteList.AddRange(this.nextFragment.SerializeToByteList());

            return byteList;
        }

        /// <summary>
        /// This method is used to deserialize the TransactionLogFragment object from the specified byte array and start index.
        /// </summary>
        /// <param name="byteArray">Specify the byte array.</param>
        /// <param name="startIndex">Specify the start index from the byte array.</param>
        /// <returns>Return the length in byte of the TransactionLogFragment object.</returns>
        public int DoDeserializeFromByteArray(byte[] byteArray, int startIndex)
        {
            int index = startIndex;
            uint count = ((this.size - 12) / 8);
            this.sizeTable = new TransactionEntry[count];
            int len = 0;
            for (int i = 0; i < count; i++)
            {
                this.sizeTable[i] = new TransactionEntry();
                len = this.sizeTable[i].DoDeserializeFromByteArray(byteArray, index);
                index += len;
            }

            this.nextFragment = new FileChunkReference64x32();
            len = this.nextFragment.DoDeserializeFromByteArray(byteArray, index);
            index += len;
            return index - startIndex;
        }
    }
}
 */


#include <cstddef>
#include <cstdint>
#include <vector>
#include "FileChunkReference64x32.hpp"
#include "FileChunkReference64.hpp"
#include "Primitive.hpp"
#include "TransactionEntry.hpp"

#ifndef TransactionLogFragment_H
#define TransactionLogFragment_H

/**
 * @brief 
 *      vector<TransactionEntry> sizeTable;
 *      FileChunkReference64x32 nextFragment;
 * 
 */
class TransactionLogFragment {
    size_t size = 0;
    public:
        TransactionLogFragment(uint32_t len);
        size_t Deserialize(char *pStart, size_t iOffset);

        vector<TransactionEntry> sizeTable;
        FileChunkReference64x32 nextFragment;
};

inline TransactionLogFragment::TransactionLogFragment(uint32_t len) {
    size = len;
    
    nextFragment = {};
};

inline size_t TransactionLogFragment::Deserialize(char *pStart, size_t iOffset) {
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

#endif