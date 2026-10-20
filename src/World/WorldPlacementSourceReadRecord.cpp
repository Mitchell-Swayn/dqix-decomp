#include "World/WorldPlacementSource.h"
#include "Resource/GameResources.h"

extern "C" {
// Original data: arm9/main @ 0x2108fe4; symbol: data_02108fe4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern WorldPlacementSource WorldPlacementSourceInitializeSingleton_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x2108ff4; symbol: data_02108ff4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern WorldPlacementSource::Variant WorldPlacementSourceReadRecord_UnknownRoleZeroInitializedStorage[8];
}

// Original: arm9/main @ 0x0208E0C4; symbol: _ZN20WorldPlacementSource10ReadRecordEPN6Script9ParameterEi; size: 0x1FC.
int WorldPlacementSource::ReadRecord(Script::Parameter* parameters, int)
{
    Record* record = (Record*)GameResources_GetInstance()->allocator_array_1a0[0].Allocate(sizeof(Record));
    record->next = 0;
    record->index = (unsigned short)parameters[0].ToInt();
    record->value = (unsigned short)parameters[1].ToInt();
    record->type = (unsigned char)parameters[2].ToInt();
    record->kind = (unsigned char)parameters[4].ToInt();
    if (record->kind == 8)
    {
        record->parameter = (unsigned short)parameters[5].ToInt();
        record->unknown13 = (unsigned char)parameters[6].ToInt();
        Script::Parameter* last = parameters + 7;
        parameters += 8;
        record->slotCount = (unsigned char)last->ToInt();
    }
    else
    {
        Variant* variants = WorldPlacementSourceInitializeSingleton_UnknownRoleZeroInitializedStorage.variants;
        record->parameter = variants[record->kind].parameter;
        record->unknown13 = variants[record->kind].unknown2;
        record->slotCount = variants[record->kind].slotCount;
        parameters += 8;
    }
    for (int i = 0; i < 8; ++i) parameters = parameters->ToVec3fix(&record->positions[i]);
    record->state = 0;
    record->flags = 0;
    WorldPlacementSourceInitializeSingleton_UnknownRoleZeroInitializedStorage.AppendRecord(record);
    return 1;
}
