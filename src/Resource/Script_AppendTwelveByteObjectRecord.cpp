#include <globaldefs.h>
#include "Resource/Script.h"
#pragma thumb off
struct ObjectScriptContext {
    unsigned reserved[4];
    unsigned char* object;
};
extern "C" {
void* Zone3D_GetMainInstance();
void WorldMap_AppendTaggedMarkerCoordinates(unsigned char*,unsigned short,unsigned char,unsigned int,unsigned int);
// Original data: arm9/main @ 0x20fdc4c; symbol: data_020fdc4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern ObjectScriptContext PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage;
}
// Original: arm9/main @ 0x0201F3B4; symbol: func_0201f3b4; size: 0x118.
// Script arguments supply a hundred-scaled key, record tag, and two rounded
// 20.12 values. A zero tag skips insertion; the command always returns success.
extern "C" int Script_AppendTwelveByteObjectRecord(Script::Parameter* params, int /* numParams */)
{
    float first;
    int key = params[0].ToInt();
    int tag = params[1].ToInt();
    first = params[2].ToFloat();
    float second = params[3].ToFloat();
    Zone3D_GetMainInstance();
    if (!tag) return 1;
    float roundedSecond = second > 0.0f ? 0.5f + 4096.0f * second : 4096.0f * second - 0.5f;
    float roundedFirst = first > 0.0f ? 0.5f + 4096.0f * first : 4096.0f * first - 0.5f;
    int recordKey = key / 100;
    WorldMap_AppendTaggedMarkerCoordinates(PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage.object,(unsigned short)recordKey,
        (unsigned char)tag,(int)roundedFirst,(int)roundedSecond);
    return 1;
}
