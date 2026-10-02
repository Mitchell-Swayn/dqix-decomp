#include "World/WorldScriptZoneRecord.h"
#include "Resource/Script.h"

typedef char WorldScriptZoneNameOffsetCheck[
    offsetof(WorldScriptZoneRecord, name) == 4 ? 1 : -1];
typedef char WorldScriptZoneFlagOffsetCheck[
    offsetof(WorldScriptZoneRecord, unknown14) == 0x14 ? 1 : -1];
typedef char WorldScriptZoneFloatOffsetCheck[
    offsetof(WorldScriptZoneRecord, unknown18) == 0x18 ? 1 : -1];
typedef char WorldScriptZoneVectorOffsetCheck[
    offsetof(WorldScriptZoneRecord, vector) == 0x1c ? 1 : -1];
typedef char WorldScriptZoneFixedOffsetCheck[
    offsetof(WorldScriptZoneRecord, unknown28) == 0x28 ? 1 : -1];
typedef char WorldScriptZoneSelectorOffsetCheck[
    offsetof(WorldScriptZoneRecord, selector1) == 0x2a ? 1 : -1];

extern "C" {
    int func_0208daf4(Script::Parameter*, int);
    WorldScriptZoneLoadingState data_02108fc8;
    Script::OpcodeLookupEntry data_020f1248[2] = {
        {102, func_0208daf4}, {0, 0}
    };
}
