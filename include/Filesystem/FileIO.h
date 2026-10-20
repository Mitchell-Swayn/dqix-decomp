#pragma once

#include "Memory/SafeAllocator.h"

#ifdef jpn
#define Main_UnknownRoleZeroInitializedStorage_Variant6 data_0211fb64
#endif

// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant6[0x30000];

void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
void* LoadFileIntoNewAllocation(const char* path, SafeAllocator& alloc, unsigned int* outLength);
// Returns true if the file was found, in which case a pointer to it will be written
// to *pOutFilePtr, and the size to *pOutFileSize. If firstFileIdxSearch > 0, the first
// that many files will be skipped in the search. (I think it's always used as 0).
bool GetFileInNarc(const void* narcBuffer, const char* innerFilePath,
    const void** pOutFilePtr, unsigned int* pOutFileSize, unsigned int firstFileIdxSearch);
// Behaves like GetFileInNarc, but the file path isn't case sensitive and the
// extension is ignored
bool GetFileInNarcPermissive(const void* narcBuffer, const char* innerFilePath,
    const void** pOutFilePtr, unsigned int* pOutFileSize);

// Finds files whose name contains substr as a substring. Commonly used
// with substr = ".nsbmd" or similar to search by extension. Returns the
// number of files found.
unsigned int FindFilesInNarcBySubstring(const void* narcBuffer, const char* substr,
    const void** pOutFilePtrs, unsigned int* pOutFileSizes, unsigned int maxOutputs);

// Decompresses a file encoded as LZ77 into scratch space. The space at the end
// of the allocator will be used, but it *won't be allocated* - so future 
// allocations can overwrite it if there's not enough space! (Also means
// you don't have to free it)
void* DecompressLZ77FileIntoScratchSpace(SafeAllocator& allocator,
    const void* fileData, unsigned int& outDecompressedSize);

// The returned memory is allocated by the allocator, so you need to call
// allocator.Free() when done with it
void* DecompressLZ77FileIntoAllocatedSpace(SafeAllocator& allocator,
    const void* fileData, unsigned int& outDecompressedSize);

// Returns a pointer to the extracted file. The file will be extracted
// to the 'file scratch space' at 0x0211e33c (USA).
extern "C" void* Filesystem_ExtractLocalizedGp2FileToScratch(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);

char* StringReplaceLanguageTag(const char* input, char* output, int language);