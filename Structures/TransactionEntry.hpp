/**
 * @file TransactionEntry.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-04
 * 
 * @copyright Copyright (c) 2023
 * 

 ﻿namespace Microsoft.Protocols.TestSuites.MS_ONESTORE
{
    using System;
    using System.Collections.Generic;

    /// <summary>
    /// This class is used to represent the TransactionEntry structure.
    /// </summary>
    public class TransactionEntry
    {
        /// <summary>
        /// Gets or sets the value of srcID field.
        /// </summary>
        public uint srcID { get; set; }
        /// <summary>
        /// Gets or sets the value of TransactionEntrySwitch field.
        /// </summary>
        public uint TransactionEntrySwitch { get; set; }

        /// <summary>
        /// This method is used to convert the element of TransactionEntry object into a byte List.
        /// </summary>
        /// <returns>Return the byte list which store the byte information of TransactionEntry</returns>
        public List<byte> SerializeToByteList()
        {
            List<byte> byteList = new List<byte>();
            byteList.AddRange(BitConverter.GetBytes(this.srcID));
            byteList.AddRange(BitConverter.GetBytes(this.TransactionEntrySwitch));

            return byteList;
        }

        /// <summary>
        /// This method is used to deserialize the TransactionEntry object from the specified byte array and start index.
        /// </summary>
        /// <param name="byteArray">Specify the byte array.</param>
        /// <param name="startIndex">Specify the start index from the byte array.</param>
        /// <returns>Return the length in byte of the TransactionEntry object.</returns>
        public int DoDeserializeFromByteArray(byte[] byteArray, int startIndex)
        {
            int index = startIndex;
            this.srcID = BitConverter.ToUInt32(byteArray, index);
            index += 4;
            this.TransactionEntrySwitch = BitConverter.ToUInt32(byteArray, index);
            index += 4;

            return index - startIndex;
        }
    }
}
 */

#include <cstddef>
#include <cstdint>
#include "Primitive.hpp"

#ifndef TransactionEntry_H
#define TransactionEntry_H

/**
 * @brief
 *  uint32_t srcID;
    uint32_t TransactionEntrySwitch;
 */
class TransactionEntry {
    public:
        size_t Deserialize(char *pStart, size_t iOffset)
        {
            char *index = pStart + iOffset;
            index += Primitive::Deserialize(srcID, index);
            index += Primitive::Deserialize(TransactionEntrySwitch, index);

            return static_cast<size_t>(index - pStart);
        };

        uint32_t srcID;
        uint32_t TransactionEntrySwitch;
 };

 #endif