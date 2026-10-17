#include <globaldefs.h>
#pragma always_inline on
struct Tail24 { unsigned char bytes[24]; };

struct LoadedModelHeader {
    unsigned int words[15];
};

struct LoadedModelResult {
    unsigned int words[15];
    unsigned char tail[24];
};

struct FiveWordBlock {
    unsigned int words[5];
};

struct ParsedModel {
    LoadedModelHeader header;
    unsigned char tail[24];
};

struct OverlayMetadata;

namespace BackgroundLoader {
void AddLockGlobal(void);
void RemoveLockGlobal(void);
}

extern "C" {
extern const char data_020f1019[];
extern unsigned char data_0211e33c[];
int ClearMemoryRange84(LoadedModelHeader *);
int Script_ExecuteInterpolationRecordAndComputeDeltas(LoadedModelHeader *, int, unsigned int, unsigned short, int);
void Object_CopyThreeVectorsAndTwentyTwoWeights(void *, const LoadedModelHeader *, unsigned char *);
void func_02083e28(void *, int);
}

int LoadFileIntoMemory(const char *, void *, unsigned int *);
extern "C" int sprintf(char *, const char *, ...);

// Original: arm9/main @ 0x02082FC4; symbol: func_02082fc4; size: 0x108.
extern "C" ARM void LoadAndParseFormattedModelFile(void *self, LoadedModelResult *result) {
    char filename[24];
    ParsedModel parsed;
    unsigned int file_size;
    int file;

    sprintf(filename, data_020f1019, *(unsigned int *)((unsigned char *)self + 0x950));
    BackgroundLoader::AddLockGlobal();
    file = LoadFileIntoMemory(filename, data_0211e33c, &file_size);
    if (file != 0) {
        ClearMemoryRange84(&parsed.header);
        Script_ExecuteInterpolationRecordAndComputeDeltas(&parsed.header, file, file_size,
                      *(unsigned short *)((unsigned char *)self +
                          *(unsigned int *)((unsigned char *)self + 0x950) * 2 + 0x16c),
                      0);
        Object_CopyThreeVectorsAndTwentyTwoWeights(self, &parsed.header, parsed.tail);
        func_02083e28(self, 0);
        if (result != 0) {
            *(FiveWordBlock *)(result->words + 0) =
                *(FiveWordBlock *)(parsed.header.words + 0);
            *(FiveWordBlock *)(result->words + 5) =
                *(FiveWordBlock *)(parsed.header.words + 5);
            *(FiveWordBlock *)(result->words + 10) =
                *(FiveWordBlock *)(parsed.header.words + 10);
            *(Tail24*)((char*)result+0x3c)=*(Tail24*)((char*)&parsed+0x3c);
        }
    }
    BackgroundLoader::RemoveLockGlobal();
}
