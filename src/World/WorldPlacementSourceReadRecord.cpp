#include "World/WorldPlacementSource.h"
#include "Resource/GameResources.h"

extern "C" {
    extern WorldPlacementSource data_02108fe4;
    extern WorldPlacementSource::Variant data_02108ff4[8];
}

int WorldPlacementSource::ReadRecord(Script::Parameter* parameters, int)
{
    Record* record = (Record*)func_ov017_0218b5b0()->allocator_array_1a0[0].Allocate(sizeof(Record));
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
        Variant* variants = data_02108fe4.variants;
        record->parameter = variants[record->kind].parameter;
        record->unknown13 = variants[record->kind].unknown2;
        record->slotCount = variants[record->kind].slotCount;
        parameters += 8;
    }
    for (int i = 0; i < 8; ++i) parameters = parameters->ToVec3fix(&record->positions[i]);
    record->state = 0;
    record->flags = 0;
    data_02108fe4.AppendRecord(record);
    return 1;
}
