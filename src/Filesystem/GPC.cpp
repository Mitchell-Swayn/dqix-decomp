#include "Filesystem/GPC.h"
#include "Filesystem/GPCImplementation.h"
#include <globaldefs.h>

#pragma dont_inline on

#if defined(jpn)
#define ReturnZero_Main02075090 func_0207621c
#define Memory_ClearAndCleanInvalidateRangeReturningLength func_020d9e5c
#define CopyRangeCleanCacheAndReturnLength func_020d9e88

#define data_020f27c0 data_020f297c
#define data_020f27e8 data_020f29a4
#define data_020f27f0 data_020f29ac
#define data_020f27f8 data_020f29b4
#endif

extern "C"
{
    // Calculate CRC for a null-terminated string
    unsigned int FileCache_CalculateStringCRC(const char*);

    // always zero. Based on where it is, and the fact that the argument
    // is a file path, maybe it used to check if the file was loaded into 
    // memory? But now it just says no
    int ReturnZero_Main02075090(const char*);

    // zero memory and flush
    unsigned int Memory_ClearAndCleanInvalidateRangeReturningLength(void*, unsigned int);
    // memcpy and flush
    unsigned int CopyRangeCleanCacheAndReturnLength(void*, const void*, unsigned int);
}

#if defined(usa)
#define data_020f27c0 gpcData.runtime
#define data_020f27e8 gpcData.signature0
#define data_020f27f0 gpcData.signature1
#define data_020f27f8 gpcData.signature2
#else
extern GPCImplementationData data_020f27c0;

// GPC0 signature
extern char data_020f27e8[8];
// GPC1 signature
extern char data_020f27f0[8];
// GPC2 signature
extern char data_020f27f8[8];
#endif

// Original: arm9/main @ 0x020D8FCC; symbol: GetUnknownGP2Data_020d8fcc; size: 0x44.
extern "C" bool GetUnknownGP2Data_020d8fcc(void** pOutPtr, unsigned int* pOutNumber, GPCFile* gpc, const GPCFile::FileEntry* file)
{
    if (file == NULL)
        return false;
    unsigned int offset = gpc->header.firstFileOffset * 4 + file->offset * 4;
    *pOutPtr = (unsigned char*)gpc + offset;
    *pOutNumber = file->compressedSizeBytes;
    return true;
}

// Original: arm9/main @ 0x020D9010; symbol: _ZN7GPCFile16GetMainDataStartEv; size: 0xC.
void* GPCFile::GetMainDataStart()
{
    unsigned int* ptr = (unsigned int*)this;
    return &ptr[header.headerLength];
}

// Original: arm9/main @ 0x020D901C; symbol: _ZN7GPCFile12GetFileByCRCEj; size: 0xB4.
GPCFile::FileEntry* GPCFile::GetFileByCRC(unsigned int crc)
{
    if (header.headerLength == 0)
        return NULL;
    if (crc == 0)
        return NULL;

    FileEntry* entryList = (FileEntry*)GetMainDataStart();
    
    unsigned int found = -1;
    unsigned int currentIdx = 0;
    
    int rightAddition = 1 << header.binarySearchStepCount;
    while (rightAddition > 0)
    {
        rightAddition >>= 1;
        unsigned int candidateRightIndex = currentIdx + rightAddition;
        if (candidateRightIndex < header.fileCount)
        {
            int result;
            if (crc == entryList[candidateRightIndex].crc)
                result = 0;
            else if (crc < entryList[candidateRightIndex].crc)
                result = -1;
            else
                result = 1;

            if (result == 0)
                found = candidateRightIndex;
            else if (result > 0)
                currentIdx += rightAddition;
        }
    }

    return &entryList[found];
}

// Original: arm9/main @ 0x020D90D0; symbol: GetUnknownGP2InnerFileDataByName; size: 0x30.
extern "C" bool GetUnknownGP2InnerFileDataByName(void** pOutPtr,
    unsigned int* pOutNumber, GPCFile* gpc, const char* name)
{
    unsigned int crc = FileCache_CalculateStringCRC(name);
    return GetUnknownGP2InnerFileDataByCRC(pOutPtr, pOutNumber, gpc, crc);
}

// Original: arm9/main @ 0x020D9100; symbol: GetUnknownGP2InnerFileDataByCRC; size: 0x64.
extern "C" bool GetUnknownGP2InnerFileDataByCRC(void** pOutPtr,
    unsigned int* pOutNumber, GPCFile* gpc, unsigned int crc)
{
    *pOutPtr = NULL;
    *pOutNumber = 0;
    if (gpc == NULL || gpc->header.signature != data_020f27c0.gpc1Signature)
        return false;

    GPCFile::FileEntry* entry = gpc->GetFileByCRC(crc);
    return GetUnknownGP2Data_020d8fcc(pOutPtr, pOutNumber, gpc, entry);
}

// Original: arm9/main @ 0x020D9164; symbol: _Z18ZeroInitGPCPointerPP7GPCFile; size: 0xC.
void ZeroInitGPCPointer(GPCFile** ppGPC)
{
    *ppGPC = NULL;
}

// Original: arm9/main @ 0x020D9170; symbol: _Z21ZeroDestroyGPCPointerPP7GPCFile; size: 0xC.
void ZeroDestroyGPCPointer(GPCFile** ppGPC)
{
    *ppGPC = NULL;
}

// Original: arm9/main @ 0x020D917C; symbol: CheckGPCPairValid_020d917c; size: 0x2C.
bool CheckGPCPairValid_020d917c(GPCFile* const& gpc, ExtendedNitroVM& machine)
{
    if (gpc != NULL && machine.IsInReadableState())
        return true;
    return false;
}

// Original: arm9/main @ 0x020D91A8; symbol: _Z12ResetGPCPairPP7GPCFileR15ExtendedNitroVM; size: 0x34.
bool ResetGPCPair(GPCFile **ppGPC, ExtendedNitroVM &machine)
{
    if (machine.IsInReadableState())
        machine.Close();
    *ppGPC = NULL;
    return true;
}

// Original: arm9/main @ 0x020D91DC; symbol: _Z42LoadAndDecompressGPCHeaderAndInnerFileInfoPP7GPCFileR15ExtendedNitroVMPKcPvRjjbPb; size: 0x178.
bool LoadAndDecompressGPCHeaderAndInnerFileInfo(GPCFile **ppGPC, ExtendedNitroVM &machine,
    const char *gpcFilePath, void *outputBuffer, unsigned int &outDecompressedLength,
    unsigned int outputCapacity, bool rightAlignOutput, bool *pOutReadSuccessful)
{
    

    if (pOutReadSuccessful != NULL)
        *pOutReadSuccessful = false;

    bool success = false;
    outDecompressedLength = 0;

    ResetGPCPair(ppGPC, machine);
    int unknownPurposeButAlwaysZero = ReturnZero_Main02075090(gpcFilePath);
    {
    if (!machine.Open(gpcFilePath, unknownPurposeButAlwaysZero != 0))
        goto end;

    if (pOutReadSuccessful != NULL)
        *pOutReadSuccessful = true;

    GPCFile::Header header;
    Memory_ClearAndCleanInvalidateRangeReturningLength(&header, sizeof(GPCFile::Header));
    unsigned int desiredSignature = data_020f27c0.gpc2Signature;
    header.signature = desiredSignature;
    if (!machine.Read(&header, sizeof(GPCFile::Header)))
        goto end;

    if (machine.isBadState != 0 || header.signature != desiredSignature)
        goto end;

    unsigned int totalLength = (header.headerLength + header.decompressedFileInfoLength) * 4;
    unsigned int longerLength = totalLength + 4;
    if (longerLength > outputCapacity)
        goto end;

    if (rightAlignOutput)
        outputBuffer = (void*)((((int)outputBuffer + outputCapacity) & ~3) - longerLength);
    CopyRangeCleanCacheAndReturnLength(outputBuffer, &header, sizeof(GPCFile::Header));
    ((GPCFile::Header*)outputBuffer)->headerLength = 0;
    ((GPCFile::Header*)outputBuffer)->fileInfoLength = 0;
    unsigned int decompressProcOutputLength = 0;

    if (!machine.DecompressBytes((unsigned char*)outputBuffer + sizeof(GPCFile::Header),
        decompressProcOutputLength,
        header.fileInfoLength * 4 - sizeof(GPCFile::Header),
        longerLength - sizeof(GPCFile::Header)))
        goto end;
    
    GPCFile::Header* outputBufferAsHeader = (GPCFile::Header*)outputBuffer; 
    // goofy way to write sizeof(GPCFile::Header) / 4 == 5
    outputBufferAsHeader->headerLength = ((unsigned int)(outputBufferAsHeader + 1) - (unsigned int)outputBufferAsHeader) / 4;
    *ppGPC = (GPCFile*)outputBuffer;
    outDecompressedLength = longerLength;
    success = true;
    }
end:
    if (!success)
        ResetGPCPair(ppGPC, machine);
    return success;
}

// Original: arm9/main @ 0x020D9354; symbol: _Z21GetGPCInnerFileLengthR15ExtendedNitroVMRKN7GPCFile6HeaderEPKNS1_9FileEntryE; size: 0x84.
unsigned int GetGPCInnerFileLength(ExtendedNitroVM& machine,
    const GPCFile::Header& header, const GPCFile::FileEntry* file)
{
    unsigned int length;

    if (file == NULL)
        length = 0;
    else
    {
        machine.Seek((header.firstFileOffset + file->offset) * 4);
        unsigned int prefixU32 = 0;
        machine.Read(&prefixU32, 4);
        if (machine.isBadState == 0 && header.isUncompressed)
            length = file->compressedSizeBytes;
        else
            length = ((CompressionPrefix*)&prefixU32)->GetDecompressedLength();
    }
    
    return length;
}

// Original: arm9/main @ 0x020D93D8; symbol: _Z27GetGPCInnerFileLengthByNameRKP7GPCFileR15ExtendedNitroVMPKc; size: 0x28.
unsigned int GetGPCInnerFileLengthByName(GPCFile* const& gpc, 
    ExtendedNitroVM& machine, const char* filename)
{
    unsigned int crc = FileCache_CalculateStringCRC(filename);
    return GetGPCInnerFileLengthByCRC(gpc, machine, crc);
}

// Original: arm9/main @ 0x020D9400; symbol: _Z26GetGPCInnerFileLengthByCRCRKP7GPCFileR15ExtendedNitroVMj; size: 0x58.
unsigned int GetGPCInnerFileLengthByCRC(GPCFile *const &gpc, 
    ExtendedNitroVM &machine, unsigned int crc)
{
    if (gpc == NULL || !machine.IsInReadableState())
        return 0;
    const GPCFile::Header& header = gpc->header;
    GPCFile::FileEntry* entry = gpc->GetFileByCRC(crc);
    return GetGPCInnerFileLength(machine, header, entry);
}

// Original: arm9/main @ 0x020D9458; symbol: _Z21DecompressFileFromGPCR15ExtendedNitroVMPvRjjRKN7GPCFile6HeaderEPKNS3_9FileEntryE; size: 0xE0.
bool DecompressFileFromGPC(ExtendedNitroVM &machine, void *outputBuffer,
    unsigned int &outDecompressedLength, unsigned int outputCapacity,
    const GPCFile::Header &gpcHeader, const GPCFile::FileEntry *file)
{
    if (file == NULL)
        return false;

    machine.Seek((gpcHeader.firstFileOffset + file->offset) * 4);
    if (gpcHeader.isUncompressed)
    {
        // note: compressedSizeBytes is actually the uncompressed size
        // (because we aren't compressed on this branch!)
        bool success;
        if (outputCapacity >= file->compressedSizeBytes && 
            machine.Read(outputBuffer, file->compressedSizeBytes) &&
            machine.isBadState == 0)
        {
            success = true;
            outDecompressedLength = file->compressedSizeBytes;
        }
        else
            success = false;
        
        return success;
    }
    else
    {
        return machine.DecompressBytes(outputBuffer, outDecompressedLength, 
            file->compressedSizeBytes, outputCapacity);
    }
}

// Original: arm9/main @ 0x020D9538; symbol: _Z27DecompressFileFromGPCByNameRKP7GPCFileR15ExtendedNitroVMPvRjjPKc; size: 0x48.
bool DecompressFileFromGPCByName(GPCFile* const& gpc, ExtendedNitroVM& machine,
    void* outputBuffer, unsigned int& outDecompressedLength,
    unsigned int outputCapacity, const char* filename)
{
    unsigned int crc = FileCache_CalculateStringCRC(filename);
    return DecompressFileFromGPCByCRC(gpc, machine, outputBuffer,
        outDecompressedLength, outputCapacity, crc);
}

// Original: arm9/main @ 0x020D9580; symbol: _Z26DecompressFileFromGPCByCRCRKP7GPCFileR15ExtendedNitroVMPvRjjj; size: 0x78.
bool DecompressFileFromGPCByCRC(GPCFile* const& gpc, ExtendedNitroVM& machine,
    void* outputBuffer, unsigned int& outDecompressedLength,
    unsigned int outputCapacity, unsigned int crc)
{
    outDecompressedLength = 0;
    if (gpc == NULL || !machine.IsInReadableState())
        return false;
    
    const GPCFile::Header& header = gpc->header;
    GPCFile::FileEntry* entry = gpc->GetFileByCRC(crc);
    return DecompressFileFromGPC(machine, outputBuffer,
        outDecompressedLength, outputCapacity, header, entry);
}

// Original: arm9/main @ 0x020D95F8; symbol: _ZN11GPCReadPair14ZeroInitializeEv; size: 0x14.
void GPCReadPair::ZeroInitialize()
{
    pGPCFile = NULL;
    machine.ZeroInitialize();
}

// Original: arm9/main @ 0x020D960C; symbol: _ZN11GPCReadPair21ZeroInitializeMachineEv; size: 0x10.
void GPCReadPair::ZeroInitializeMachine()
{
    machine.ZeroInitialize();
}

// Original: arm9/main @ 0x020D961C; symbol: _ZN11GPCReadPair5ResetEv; size: 0x10.
bool GPCReadPair::Reset()
{
    return ResetGPCPair(&pGPCFile, machine);
}

// Original: arm9/main @ 0x020D962C; symbol: _Z16CopyGPCSignaturePjS_; size: 0xC.
void CopyGPCSignature(unsigned int *dst, unsigned int *src)
{
    *dst = *src;
}

// Original: arm9/main @ 0x020D9638; symbol: _Z19SetGPCSignatureGPC0Pj; size: 0x1C.
unsigned int* SetGPCSignatureGPC0(unsigned int* dst)
{
    CopyGPCSignatureFromString(dst, data_020f27e8);
    return dst;
}

// Original: arm9/main @ 0x020D9654; symbol: _Z26CopyGPCSignatureFromStringPjPKc; size: 0x24.
void CopyGPCSignatureFromString(unsigned int* dst, const char* src)
{
    char* dstString = reinterpret_cast<char*>(dst);
    dstString[0] = src[0];
    dstString[1] = src[1];
    dstString[2] = src[2];
    dstString[3] = src[3];
}

// Original: arm9/main @ 0x020D9678; symbol: _Z19SetGPCSignatureGPC1Pj; size: 0x1C.
unsigned int* SetGPCSignatureGPC1(unsigned int* dst)
{
    CopyGPCSignatureFromString(dst, data_020f27f0);
    return dst;
}

// Original: arm9/main @ 0x020D9694; symbol: _Z19SetGPCSignatureGPC2Pj; size: 0x1C.
unsigned int* SetGPCSignatureGPC2(unsigned int* dst)
{
    CopyGPCSignatureFromString(dst, data_020f27f8);
    return dst;
}
