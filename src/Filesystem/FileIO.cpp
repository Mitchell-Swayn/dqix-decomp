// Original data alias: arm9/main @ 0x20f0dc2; symbol: data_020f0dc2.
// Language placeholder: "<LG>" followed by two zero bytes; aliases gFileIOConfiguration.languageTag.
// Initial values (hex for initialized storage): 3c4c473e0000.
// Original data alias: arm9/main @ 0x20f0dbc; symbol: data_020f0dbc.
// Archive root: "arc:/" followed by NUL; aliases gFileIOConfiguration.archiveRoot.
// Initial values (hex for initialized storage): 6172633a2f00.
// Original data alias: arm9/main @ 0x20f0db8; symbol: data_020f0db8.
// Archive signature: "ARC" followed by NUL; aliases gFileIOConfiguration.archiveSignature.
// Initial values (hex for initialized storage): 41524300.
// Original data alias: arm9/main @ 0x20f0da0; symbol: data_020f0da0.
// Language pointer order: Japanese, English, French, German, Italian, Spanish. Aliases gFileIOConfiguration.languages.
// Initial values (hex for initialized storage): 7f0d0f027c0d0f02760d0f02700d0f02730d0f02790d0f02.
#include "Filesystem/FileIO.h"
#include "Filesystem/FileIOConfiguration.h"
#include "Filesystem/ExtendedNitroVM.h"
#include "Filesystem/NitroVM.h"
#include "Filesystem/LowNitroHandle.h"
#include "Filesystem/FileAccessor.h"
#include "Filesystem/GPC.h"
#include "GameState/GameState.h"
#include "Filesystem/NarcHandle.h"
#include "Filesystem/BackgroundLoader.h"
#include "System/Memory.h"
#include "Resource/ResourceMutex.h"
#include "std_library_functions.h"
#include <globaldefs.h>
#include <asmhacks.h>

#ifdef jpn
#define FileIO_LanguageNamePointers data_020f0da0
#define FileIO_LanguageTag data_020f0dc2

#define MakeCharUpperCase_UnknownRoleInitializedBytes data_020e71d4

#define FileIO_ArchiveSignature data_020f0e84
#define FileIO_ArchiveRoot data_020f0e88
#endif

extern "C"
{
    // some sort of bit test of a struct member at offset 0
    bool SystemState_TestAnyFlags(void*, unsigned int);
    // returns pointer to some unknown struct (at 02114e04)
    void* SystemState_GetGlobalFlags();

    // get system language?
    int GameState_ReadSupportedFirmwareLanguage(GameState*);

    // Looks like a custom implementation of strstr
    char* String_FindFirstSubstring(char* searchString, const char* targetString);
    // Custom implementation of strlen
    int String_CountBytesUntilTerminator(const char* str);

    void LZ77UnCompReadNormalWrite8bit(const void* src, void* dst);
}

int MakeCharUpperCase(char ch);

// character to upper case lookup table
// Original data: arm9/main @ 0x20e692c; symbol: data_020e692c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const char MakeCharUpperCase_UnknownRoleInitializedBytes[];

// USA language order: Japanese, English, French, German, Italian, Spanish.
#if defined(usa)
#define FileIO_LanguageNamePointers gFileIOConfiguration.languages
#define FileIO_ArchiveSignature gFileIOConfiguration.archiveSignature
#define FileIO_ArchiveRoot gFileIOConfiguration.archiveRoot
#define FileIO_LanguageTag gFileIOConfiguration.languageTag
#else
extern char* FileIO_LanguageNamePointers[];

// "ARC"
extern char FileIO_ArchiveSignature[];
// "arc:/"
extern char FileIO_ArchiveRoot[];

extern char FileIO_LanguageTag[]; // "<LG>" (USA only)
#endif

// JPN: func_02076224
// Original: arm9/main @ 0x02075098; symbol: _Z18LoadFileIntoMemoryPKcPvPj; size: 0xE4.
void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength)
{
    if (outLength != NULL)
        *outLength = 0;

#if defined(usa)
    GameState* gameState = GameState::GetInstance();
    
    char replacedPath[128] = { 0 };
    int language = GameState_ReadSupportedFirmwareLanguage(gameState);
    StringReplaceLanguageTag(path, replacedPath, language);
#elif defined(jpn)
    const char* replacedPath = path;
#endif

    void* alwaysNull = NULL;
    
    if (buffer >= Main_UnknownRoleZeroInitializedStorage_Variant6 && buffer < &Main_UnknownRoleZeroInitializedStorage_Variant6[0x30000])
        BackgroundLoader::FreeAllocationsGlobal();

    ExtendedNitroVM reader;
    reader.ZeroInitialize();
    
    void* output = NULL;
    bool alwaysFalse = alwaysNull != NULL;
    DECLARE_ASM_NOP();

    if (reader.Open(replacedPath, alwaysFalse))
    {
        output = buffer;
        unsigned int fileSize = reader.Read(buffer, reader.GetFileSize());
        if (outLength != NULL)
            *(unsigned int*)outLength = fileSize;

        reader.Close();
        if (fileSize == 0)
            return NULL;
    }

    return output;
}

// Original: arm9/main @ 0x0207517C; symbol: _Z25LoadFileIntoNewAllocationPKcR13SafeAllocatorPj; size: 0xCC.
void* LoadFileIntoNewAllocation(const char* path, SafeAllocator& alloc, unsigned int* outLength)
{
#if defined(usa)
    GameState* gameState = GameState::GetInstance();

    char replacedPath[128] = { 0 };

    int language = GameState_ReadSupportedFirmwareLanguage(gameState);
    StringReplaceLanguageTag(path, replacedPath, language);
#elif defined(jpn)
    const char* replacedPath = path;
#endif

    if (outLength != NULL)
        *outLength = 0;

    ExtendedNitroVM reader;
    reader.ZeroInitialize();

    void* copyDst = NULL;
    if (reader.Open(replacedPath, 0))
    {
        unsigned int size = reader.GetFileSize();
        copyDst = alloc.Allocate(size);
        if (copyDst != NULL)
        {
            size = reader.Read(copyDst, size);
            if (outLength != NULL)
                *outLength = size;
        }
        reader.Close();
        if (size == 0)
            return NULL;
    }

    return copyDst;
}

// Original: arm9/main @ 0x02075248; symbol: _Z13GetFileInNarcPKvPKcPS0_Pjj; size: 0xFC.
bool GetFileInNarc(const void *narcBuffer, const char *targetFilePath,
    const void **pOutFilePtr, unsigned int *pOutFileSize, unsigned int firstFileIdx)
{
    bool success = false;
    LockResourceMutex();
    NarcHandle handle;
    if (handle.Initialize(FileIO_ArchiveSignature, (const unsigned char*)narcBuffer))
    {
        NitroVM machine;
        NitroVM_Initialize(&machine);
        unsigned int idx = firstFileIdx;
        unsigned int prefixLength = strlen(FileIO_ArchiveRoot);
        while (PrepareReadFileInNARCByID(&machine, &handle, idx))
        {
            char currentFilePath[80];
            NitroVM_WriteOutFilePath(&machine, currentFilePath, sizeof(currentFilePath));
            if (strcmp(currentFilePath + prefixLength, targetFilePath) == 0)
            {
                const void* pFile = handle.GetFileByIndex(idx);
                unsigned int endOffset = machine.fileInfo.endOffset;
                unsigned int startOffset = machine.fileInfo.startOffset;
                *pOutFilePtr = pFile;
                *pOutFileSize = endOffset - startOffset;
                strrchr(targetFilePath, '/');
                success = true;
            }
            NitroVM_FinishRead(&machine);
            if ((int)success > 0)
                break;
            idx++;
        }
        handle.Destroy();
    }
    UnlockResourceMutex();
    return success;
}

// Original: arm9/main @ 0x02075344; symbol: _Z23GetFileInNarcPermissivePKvPKcPS0_Pj; size: 0x1A8.
bool GetFileInNarcPermissive(const void *narcBuffer, const char *targetFilePath,
    const void **pOutFilePtr, unsigned int *pOutFileSize)
{
    bool success = false;
    LockResourceMutex();
    NarcHandle handle;
    if (handle.Initialize(FileIO_ArchiveSignature, (const unsigned char*)narcBuffer))
    {
        NitroVM machine;
        char loopFilePathOutput[80];
        char loopFilePathUpperCase[80];
        char targetUpperCase[80];
        NitroVM_Initialize(&machine);

        int fileSearchMinIdx = 0;
        int fileSearchMaxIdx = 1000;
        if (handle.pFATBSection != NULL)
            fileSearchMaxIdx = handle.pFATBSection->numFiles - 1;
        
        
        VectorizedMemset(targetUpperCase, 0, 80);
        for (int i = 0; i < 80 && targetFilePath[i] != '.' && targetFilePath[i] != '\0'; i++)
        {
            targetUpperCase[i] = MakeCharUpperCase(targetFilePath[i]);
        }
        unsigned int prefixLength = strlen(FileIO_ArchiveRoot);
        while (fileSearchMinIdx <= fileSearchMaxIdx)
        {
            int i = 0;
            unsigned int midpoint = (fileSearchMinIdx + fileSearchMaxIdx) / 2;
            if (PrepareReadFileInNARCByID(&machine, &handle, midpoint))
            {
                NitroVM_WriteOutFilePath(&machine, loopFilePathOutput, 80);
                VectorizedMemset(loopFilePathUpperCase, 0, 80);
                for (i = 0; i < 80 && loopFilePathOutput[i] != '.' && loopFilePathOutput[i] != '\0'; i++)
                    loopFilePathUpperCase[i] = MakeCharUpperCase(loopFilePathOutput[i]);
                
                int comparison = strcmp(loopFilePathUpperCase + prefixLength, targetUpperCase);
                if (comparison == 0)
                {
                    const void* pFile = handle.GetFileByIndex(midpoint);
                    unsigned int endOffset = machine.fileInfo.endOffset;
                    unsigned int startOffset = machine.fileInfo.startOffset;
                    success = true;
                    *pOutFilePtr = pFile;
                    *pOutFileSize = endOffset - startOffset;
                }
                else if (comparison < 0)
                    fileSearchMinIdx = midpoint + 1;
                else
                    fileSearchMaxIdx = midpoint - 1;
                
                NitroVM_FinishRead(&machine);
            }
            else
                fileSearchMaxIdx = midpoint - 1;

            if ((int)success > 0)
                break;
        }

        handle.Destroy();
    }
    UnlockResourceMutex();
    return success;
}

// Original: arm9/main @ 0x020754EC; symbol: _Z17MakeCharUpperCasec; size: 0x20.
int MakeCharUpperCase(char ch)
{
    if (ch < 0 || ch >= 0x80)
        return ch;
    return (unsigned char)MakeCharUpperCase_UnknownRoleInitializedBytes[ch];
}

// Original: arm9/main @ 0x0207550C; symbol: _Z26FindFilesInNarcBySubstringPKvPKcPS0_Pjj; size: 0xFC.
unsigned int FindFilesInNarcBySubstring(const void* narcBuffer, const char* substr,
    const void** pOutFilePtrs, unsigned int* pOutFileSizes, unsigned int maxOut)
{
    int maxOutputs;
    char* pLoopFilename;
    NitroVM* pMachine; // will point to a stack variable created shortly
    int numFound = 0;

    LockResourceMutex();

    NarcHandle handle;
    if (handle.Initialize(FileIO_ArchiveSignature, (const unsigned char*)narcBuffer))
    {
        NitroVM machine;
        char loopFilename[80];
        NitroVM_Initialize(&machine);
        unsigned int idx = numFound; // 0
        DECLARE_ASM_NOP();
        maxOutputs = maxOut;
        pLoopFilename = loopFilename;  
        pMachine = &machine;
        
        while (PrepareReadFileInNARCByID(pMachine, &handle, idx))
        {
            NitroVM_WriteOutFilePath(pMachine, pLoopFilename, 80);
            if (strstr(pLoopFilename, substr))
            {
                const void* pFile = handle.GetFileByIndex(idx);
                unsigned int endOffset = machine.fileInfo.endOffset;
                unsigned int startOffset = machine.fileInfo.startOffset;
                pOutFilePtrs[numFound] = pFile;
                pOutFileSizes[numFound] = endOffset - startOffset;
                // unused?
                strrchr(loopFilename, '/');
                numFound++;
                if (maxOutputs <= numFound)
                {
                    NitroVM_FinishRead(&machine);
                    break;
                }
            }
            NitroVM_FinishRead(&machine);
            idx++;
        }
        handle.Destroy();
    }
    UnlockResourceMutex();
    return numFound;
}

// Original: arm9/main @ 0x02075608; symbol: _Z34DecompressLZ77FileIntoScratchSpaceR13SafeAllocatorPKvRj; size: 0x4C.
void* DecompressLZ77FileIntoScratchSpace(SafeAllocator& allocator,
    const void* fileData, unsigned int& outDecompressedSize)
{
    // First 4 bytes of fileData are a uint32, whose upper 24 bits
    // store the file size
    outDecompressedSize = *(const unsigned int*)fileData >> 8;
    unsigned char* pAllocatorStart = reinterpret_cast<unsigned char*>(allocator.GetSignedAllocator());
    unsigned int allocBufferSize = allocator.GetSize();

    unsigned char* writeDst = pAllocatorStart + allocBufferSize - outDecompressedSize;
    LZ77UnCompReadNormalWrite8bit(fileData, writeDst);
    return writeDst;
}

// Original: arm9/main @ 0x02075654; symbol: _Z36DecompressLZ77FileIntoAllocatedSpaceR13SafeAllocatorPKvRj; size: 0x38.
void* DecompressLZ77FileIntoAllocatedSpace(SafeAllocator& allocator,
    const void* fileData, unsigned int& outDecompressedSize)
{
    outDecompressedSize = *(const unsigned int*)fileData >> 8;
    void* writeDst = allocator.Allocate(outDecompressedSize);
    if (!writeDst)
        return NULL;
    LZ77UnCompReadNormalWrite8bit(fileData, writeDst);
    return writeDst;
}

/*
// Doesn't quite work, parameters passed to 8-parameter function in the wrong
// order.
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize)
{
    if (outSize != NULL)
        *outSize = 0;

    func_0202f7a8();
    GameState* battle = GameState::GetInstance();
    char innerFileReplacedPath[128] = { 0 };

    int language = func_0200fb08(battle);
    StringReplaceLanguageTag(innerFilePath, innerFileReplacedPath, language);

    unsigned int metadataLength = 0;
    unsigned int metadataLengthCopy;
    
    unsigned char* storageSpace = data_0211e33c;
    unsigned int storageCapacity = 0x30000;  
    
    
    if (func_02046708(func_020d6c00(), 0x02000000))
        storageCapacity -= 0x8000;
    DECLARE_ASM_NOP();
    GPCReadPair readPair;
    GPCFile** ppGPC = &readPair.pGPCFile;
    ZeroInitGPCPointer(&readPair.pGPCFile);
    readPair.ZeroInitializeMachine();

    void* output;

    bool successHeader = LoadAndDecompressGPCHeaderAndInnerFileInfo(ppGPC, readPair.machine,
        gp2Path, storageSpace, metadataLength, storageCapacity, false, NULL);

    if (successHeader)
    {
        //DECLARE_ASM_NOP();
        unsigned int fileSize = 0;
        metadataLengthCopy = metadataLength;
        DecompressFileFromGPCByName(readPair.pGPCFile, readPair.machine, (unsigned char*)storageSpace + metadataLengthCopy, fileSize, storageCapacity - metadataLengthCopy, innerFileReplacedPath);
        *outSize = fileSize;
        readPair.Reset();
        ZeroDestroyGPCPointer(&readPair.pGPCFile);
        return (unsigned char*)storageSpace + metadataLengthCopy;
    }
    else
    {
        output = NULL;
        readPair.Reset();
        ZeroDestroyGPCPointer(&readPair.pGPCFile);
    }
    
    return output;
}

// This function is properly matched, the above function is the issue
char* StringReplaceLanguageTag(const char* input, char* output, int language)
{
    if (input == NULL || output == NULL)
        return output;

    const char* searchTag = data_020f0dc2;
    
    char *copyOfOutputPtr;
    __asm("mov copyOfOutputPtr, output");

    strcpy(copyOfOutputPtr, input);

    __asm("mov copyOfOutputPtr, output");
    DECLARE_ASM_NOP();
    char* firstTagOccurrence = func_020d2f88(copyOfOutputPtr, searchTag);
    
    const char* replacement = data_020f0da0[language];

    int replacementStringLength = func_020d2ff0(replacement);
    // difference between length of e.g. "en" and "<LG>" (in practice always -2)
    int lengthDifference = func_020d2ff0(replacement) - func_020d2ff0(searchTag);
    while (firstTagOccurrence != NULL)
    {
        if (lengthDifference > 0)
        {
            int lengthRemaining = func_020d2ff0(firstTagOccurrence);
            // difference > 0: replacing with a longer substring. Move everything
            // to the right of the tag to the right. For convenience, we can also
            // move the tag itself
            memmove(firstTagOccurrence + lengthDifference, firstTagOccurrence, lengthRemaining + 1);
        }
        else if (lengthDifference < 0)
        {
            int lengthRemaining = func_020d2ff0(firstTagOccurrence);
            // difference < 0: replacing with a shorter substring. Move everything
            // to the left (including the later part of the tag)
            memmove(firstTagOccurrence, firstTagOccurrence - lengthDifference, lengthDifference + lengthRemaining + 1);
        }

        memmove(firstTagOccurrence, replacement, replacementStringLength);
        firstTagOccurrence = func_020d2f88(output, searchTag);
    }
    return output;
}*/
