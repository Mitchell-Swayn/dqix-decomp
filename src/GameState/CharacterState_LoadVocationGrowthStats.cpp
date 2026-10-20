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
extern const char CharacterState_LoadVocationGrowthStats_PathDataPrmLevelDBin[];
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant6[];
int CharacterGrowth_ClearEvaluationResult(LoadedModelHeader *);
int CharacterGrowth_EvaluateScriptAndComputeDeltas(LoadedModelHeader *, int, unsigned int, unsigned short, int);
void CharacterState_SetBaseStatsAndAttributePercentages(void *, const LoadedModelHeader *, unsigned char *);
void CharacterState_RecalculateOrPreviewDerivedStats(void *, int);
}

int LoadFileIntoMemory(const char *, void *, unsigned int *);
extern "C" int sprintf(char *, const char *, ...);

// Original: arm9/main @ 0x02082FC4; symbol: func_02082fc4; size: 0x108.
extern "C" ARM void CharacterState_LoadVocationGrowthStats(void *self, LoadedModelResult *result) {
    char filename[24];
    ParsedModel parsed;
    unsigned int file_size;
    int file;

    sprintf(filename, CharacterState_LoadVocationGrowthStats_PathDataPrmLevelDBin, *(unsigned int *)((unsigned char *)self + 0x950));
    BackgroundLoader::AddLockGlobal();
    file = LoadFileIntoMemory(filename, Main_UnknownRoleZeroInitializedStorage_Variant6, &file_size);
    if (file != 0) {
        CharacterGrowth_ClearEvaluationResult(&parsed.header);
        CharacterGrowth_EvaluateScriptAndComputeDeltas(&parsed.header, file, file_size,
                      *(unsigned short *)((unsigned char *)self +
                          *(unsigned int *)((unsigned char *)self + 0x950) * 2 + 0x16c),
                      0);
        CharacterState_SetBaseStatsAndAttributePercentages(self, &parsed.header, parsed.tail);
        CharacterState_RecalculateOrPreviewDerivedStats(self, 0);
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
