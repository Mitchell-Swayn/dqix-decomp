#include "World/BMDJ.h"

void ResetBMDJObjectEntry(Zone3D_BMDJStruct::ObjectEntry* entry)
{
    entry->id = -1;
    entry->flags = 0;
    entry->unknown_4 = NULL;
    entry->unknown_8 = NULL;
    entry->unknown_c = NULL;
    entry->unknown_10 = NULL;
    entry->unknown_14 = NULL;
}
