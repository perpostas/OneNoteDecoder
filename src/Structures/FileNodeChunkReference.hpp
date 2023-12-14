

#include <cstdint>
#include <vector>
#include "FileChunkReference.hpp"

class FileNodeChunkReference : public FileChunkReference {
    private:
        uint32_t stpFormat;
        uint32_t cbFormat;

    public:
        FileNodeChunkReference(uint32_t stpFmt, uint32_t cbFmt) {
            stpFormat = stpFmt;
            cbFormat = cbFmt;
        }

        size_t Deserialize(char *byteArray, int startIndex)
        {
            int index = startIndex;
            int stpLen = 0;
            switch(stpFormat)
            {
                case 0:
                    stpLen = 8;
                    Stp.resize(stpLen);
                    Array.Copy(byteArray, index, this.Stp, 0, stpLen);
                    this.StpValue = BitConverter.ToUInt64(this.Stp, 0);
                    break;
                case 1:
                    stpLen = 4;
                    this.Stp = new byte[stpLen];
                    Array.Copy(byteArray, index, this.Stp, 0, stpLen);
                    this.StpValue = (ulong)BitConverter.ToUInt32(this.Stp, 0);
                    break;
                case 3:
                    stpLen = 4;
                    this.Stp = new byte[stpLen];
                    Array.Copy(byteArray, index, this.Stp, 0, stpLen);
                    this.StpValue = (ulong)(BitConverter.ToUInt32(this.Stp, 0) * 8);
                    break;
                case 2:
                    stpLen = 2;
                    this.Stp = new byte[stpLen];
                    Array.Copy(byteArray, index, this.Stp, 0, stpLen);
                    this.StpValue = (ulong)(BitConverter.ToUInt16(this.Stp, 0) * 8);
                    break;
            }
            this.Stp = new byte[stpLen];
            Array.Copy(byteArray, index, this.Stp, 0, stpLen);
            index += stpLen;
            int cbLen = 0;
            switch(cbFormat)
            {
                case 0:
                    cbLen = 4;
                    this.Cb = new byte[4];
                    Array.Copy(byteArray, index, this.Cb, 0, 4);
                    this.CbValue = (ulong)BitConverter.ToUInt32(this.Cb, 0);
                    break;
                case 1:
                    cbLen = 8;
                    this.Cb = new byte[8];
                    Array.Copy(byteArray, index, this.Cb, 0, 8);
                    this.CbValue = (ulong)BitConverter.ToUInt64(this.Cb, 0);
                    break;
                case 2:
                    cbLen = 1;
                    this.Cb = new byte[1];
                    Array.Copy(byteArray, index, this.Cb, 0, 1);
                    this.CbValue = (ulong)(this.Cb[0] * 8);
                    break;
                case 3:
                    cbLen = 2;
                    this.Cb = new byte[2];
                    Array.Copy(byteArray, index, this.Cb, 0, 2);
                    this.CbValue = (ulong)(BitConverter.ToUInt16(this.Cb, 0) * 8);
                    break;
            }

            index += cbLen;

            return index - startIndex;
        }

        bool IsfcrNil()
        {
            foreach(byte b in this.Stp)
            {
                if(b!=byte.MaxValue)
                {
                    return false;
                }
            }
            foreach(byte b in this.Cb)
            {
                if (b != 0)
                {
                    return false;
                }
            }

            return true;
        }
        /// <summary>
        /// This method is used the check the instance whether is fcrZero.
        /// </summary>
        /// <returns>return the whether the instance is fcrZero.</returns>
        bool IsfcrZero()
        {
            foreach (byte b in this.Stp)
            {
                if (b != byte.MinValue)
                {
                    return false;
                }
            }
            foreach (byte b in this.Cb)
            {
                if (b != byte.MinValue)
                {
                    return false;
                }
            }

            return true;
        }

        std::vector <uint8_t> Stp;
        std::vector <uint8_t> Cb;
        uint64_t CbValue;
        uint64_t StpValue;
};