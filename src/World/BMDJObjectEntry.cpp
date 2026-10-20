#include "World/BMDJ.h"

// Original: arm9/main @ 0x02012FF0; symbol: _Z20ResetBMDJObjectEntryPN17Zone3D_BMDJStruct11ObjectEntryE; size: 0x28.
void ResetBMDJObjectEntry(Zone3D_BMDJStruct::ObjectEntry* entry)
{
    entry->kind = -1;
    entry->flags = 0;
    entry->unknown_4 = NULL;
    entry->patternAnimation = NULL;
    entry->textureAnimation = NULL;
    entry->materialAnimation = NULL;
    entry->skeletalAnimation = NULL;
}
