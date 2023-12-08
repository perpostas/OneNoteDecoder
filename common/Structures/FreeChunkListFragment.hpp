/**
 * @file FreeChunkListFragment.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-03
 * 
 * @copyright Copyright (c) 2023
 * 


 namespace Microsoft.Protocols.TestSuites.MS_ONESTORE
{
    using System;
    using System.Collections.Generic;

    /// <summary>
    /// This class is used to represent the FreeChunkListFragment structure.
    /// </summary>
    public class FreeChunkListFragment
    {
        private ulong size = 0;

        public FreeChunkListFragment(ulong size)
        {
            this.size = size;
        }
        /// <summary>
        /// Gets or sets the value of crc field.
        /// </summary>
        public uint crc { get; set; }

        /// <summary>
        /// Gets or sets the value of fcrNextChunk field.
        /// </summary>
        public FileChunkReference64x32 fcrNextChunk { get; set; }
        /// <summary>
        /// Gets or sets the value of fcrFreeChunk field.
        /// </summary>
        public FileChunkReference64[] fcrFreeChunk { get; set; }

        /// <summary>
        /// This method is used to convert the element of FreeChunkListFragment object into a byte List.
        /// </summary>
        /// <returns>Return the byte list which store the byte information of FreeChunkListFragment</returns>
        public List<byte> SerializeToByteList()
        {
            List<byte> byteList = new List<byte>();
            byteList.AddRange(BitConverter.GetBytes(this.crc));
            byteList.AddRange(this.fcrNextChunk.SerializeToByteList());

            foreach(FileChunkReference64 f in this.fcrFreeChunk)
            {
                byteList.AddRange(f.SerializeToByteList());
            }

            return byteList;
        }

        /// <summary>
        /// This method is used to deserialize the FreeChunkListFragment object from the specified byte array and start index.
        /// </summary>
        /// <param name="byteArray">Specify the byte array.</param>
        /// <param name="startIndex">Specify the start index from the byte array.</param>
        /// <returns>Return the length in byte of the FreeChunkListFragment object.</returns>
        public int DoDeserializeFromByteArray(byte[] byteArray, int startIndex)
        {
            int index = startIndex;
            this.crc = BitConverter.ToUInt32(byteArray, index);
            index += 4;
            this.fcrNextChunk = new FileChunkReference64x32();
            int len = this.fcrNextChunk.DoDeserializeFromByteArray(byteArray, index);
            index += len;
            ulong count = (this.size - 16) / 16;
            this.fcrFreeChunk = new FileChunkReference64[count];
            for (ulong i = 0; i < count; i++)
            {
                this.fcrFreeChunk[i] = new FileChunkReference64();
                len = this.fcrFreeChunk[i].DoDeserializeFromByteArray(byteArray, index);
                index += len;
            }

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


#ifndef FreeChunkListFragment_H
#define FreeChunkListFragment_H

/**
 * @brief 
 *  uint32_t crc;
    FileChunkReference64x32 fcrNextChunk;
    vector<FileChunkReference64> fcrFreeChunk;
 */
class FreeChunkListFragment {
    size_t size = 0;
    public:
        FreeChunkListFragment(size_t len);

        size_t Deserialize(char *pStart, size_t offset);

        uint32_t crc;
        FileChunkReference64x32 fcrNextChunk;
        vector<FileChunkReference64> fcrFreeChunk;
};

/**
 * @brief Construct a new Free Chunk List Fragment:: Free Chunk List Fragment object
 * 
 * @param len 
 */
inline FreeChunkListFragment::FreeChunkListFragment(size_t len) {
    size = len;
};

/**
 * @brief 
 * 
 * @param pStart 
 * @param offset 
 * @return size_t 
 */
inline size_t FreeChunkListFragment::Deserialize(char *pStart, size_t offset) {
    char *pIndex = pStart + offset;
   
    pIndex += Primitive::Deserialize(crc, pIndex);
    pIndex += FileChunkReference64x32::Deserialize(fcrNextChunk, pIndex);
    size_t count  = (sizeof(FreeChunkListFragment) - 16) / 16;
    for ( size_t i = 0; i < count; ++i) {
        FileChunkReference64 item;
        pIndex += item.Deserialize(pIndex);
        fcrFreeChunk.push_back(item);
    };

    return static_cast<size_t>(pIndex - pStart - offset);
};

#endif