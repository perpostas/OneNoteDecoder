

OneNote file structure:

 Notebook
    SectionGroup
        SectionGroup
        Section
    Section
        Page
            OEChildren

OneNote file (.one) consists of:

1.  Header
    guidFileType (16 bytes) must be {7B5C52E4-D88C-4DA7-AEB1-5378D02996D3} for .one
    guidFile     (16 bytes) uniqually defined for each file  
    guidLegacyFileVersion: 00000000-0000-0000-0000-000000000000
    
    int index = startIndex;
    this.guidFileType = AdapterHelper.ReadGuid(byteArray, index);
    index += 16;
    this.guidFile = AdapterHelper.ReadGuid(byteArray, index);
    index += 16;
    this.guidLegacyFileVersion = AdapterHelper.ReadGuid(byteArray, index);
    index += 16;
    this.guidFileFormat = AdapterHelper.ReadGuid(byteArray, index);
    index += 16;
    this.ffvLastCodeThatWroteToThisFile = BitConverter.ToUInt32(byteArray, index);
    index += 4;
    this.ffvOldestCodeThatHasWrittenToThisFile = BitConverter.ToUInt32(byteArray, index);
    index += 4;
    this.ffvNewestCodeThatHasWrittenToThisFile = BitConverter.ToUInt32(byteArray, index);
    index += 4;
    this.ffvOldestCodeThatMayReadThisFile = BitConverter.ToUInt32(byteArray, index);
    index += 4;
    this.fcrLegacyFreeChunkList = new FileChunkReference32();
    int len = this.fcrLegacyFreeChunkList.DoDeserializeFromByteArray(byteArray, index);
    index += len;
    this.fcrLegacyTransactionLog = new FileChunkReference32();
    len = this.fcrLegacyTransactionLog.DoDeserializeFromByteArray(byteArray, index);
    index += len;
    this.cTransactionsInLog = BitConverter.ToUInt32(byteArray, index);
    index += 4;
    this.cbLegacyExpectedFileLength = BitConverter.ToUInt32(byteArray, index);
    index += 4;
    this.rgbPlaceholder = BitConverter.ToUInt64(byteArray, index);
    index += 8;
    this.fcrLegacyFileNodeListRoot = new FileChunkReference32();
    len = this.fcrLegacyFileNodeListRoot.DoDeserializeFromByteArray(byteArray, index);
    index += len;
    this.cbLegacyFreeSpaceInFreeChunkList = BitConverter.ToUInt32(byteArray, index);
    index += 4;
    this.fNeedsDefrag = byteArray[index];
    index += 1;
    this.fRepairedFile= byteArray[index];
    index += 1;
    this.fNeedsGarbageCollect = byteArray[index];
    index += 1;
    this.fHasNoEmbeddedFileObjects = byteArray[index];
    index += 1;
    this.guidAncestor = AdapterHelper.ReadGuid(byteArray, index);
    index += 16;
    this.crcName = BitConverter.ToUInt32(byteArray, index);
    index += 4;
    this.fcrHashedChunkList = new FileChunkReference64x32();
    len=this.fcrHashedChunkList.DoDeserializeFromByteArray(byteArray, index);
    index += len;
    this.fcrTransactionLog = new FileChunkReference64x32();
    len = this.fcrTransactionLog.DoDeserializeFromByteArray(byteArray, index);
    index += len;
    this.fcrFileNodeListRoot = new FileChunkReference64x32();
    len=this.fcrFileNodeListRoot.DoDeserializeFromByteArray(byteArray, index);
    index += len;
    this.fcrFreeChunkList = new FileChunkReference64x32();
    len=this.fcrFreeChunkList.DoDeserializeFromByteArray(byteArray, index);
    index += len;
    this.cbExpectedFileLength = BitConverter.ToUInt64(byteArray, index);
    index += 8;
    this.cbFreeSpaceInFreeChunkList = BitConverter.ToUInt64(byteArray, index);
    index += 8;
    this.guidFileVersion = AdapterHelper.ReadGuid(byteArray, index);
    index += 16;
    this.nFileVersionGeneration = BitConverter.ToUInt64(byteArray, index);
    index += 8;
    this.guidDenyReadFileVersion = AdapterHelper.ReadGuid(byteArray, index);
    index += 16;
    this.grfDebugLogFlags = BitConverter.ToUInt32(byteArray, index);
    index += 4;
    this.fcrDebugLog = new FileChunkReference64x32();
    len = this.fcrDebugLog.DoDeserializeFromByteArray(byteArray, index);
    index += len;
    this.fcrAllocVerificationFreeChunkList = new FileChunkReference64x32();
    len = this.fcrAllocVerificationFreeChunkList.DoDeserializeFromByteArray(byteArray, index);
    index += len;
    this.bnCreated = BitConverter.ToUInt32(byteArray, index);
    index += 4;
    this.bnLastWroteToThisFile = BitConverter.ToUInt32(byteArray, index);
    index += 4;
    this.bnOldestWritten = BitConverter.ToUInt32(byteArray, index);
    index += 4;
    this.bnNewestWritten = BitConverter.ToUInt32(byteArray, index);
    index += 4;
    this.rgbReserved = new byte[728];
    Array.Copy(byteArray, index, this.rgbReserved, 0, 728);
    index += 728;                           
    