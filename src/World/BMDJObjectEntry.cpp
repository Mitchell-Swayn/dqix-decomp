#include "World/BMDJ.h"

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
