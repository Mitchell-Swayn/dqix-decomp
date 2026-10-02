#include "World/WorldPlacementSource.h"
#include "Resource/GameResources.h"
#include "GameState/GameState.h"

extern "C" {
    extern WorldPlacementSource data_02108fe4;
    // Observed alias of the variant subobject at data_02108fe4 + 0x10.
    extern WorldPlacementSource::Variant data_02108ff4[8];
}

int WorldPlacementSource::ReadVariantTable(Script::Parameter* parameters, int)
{
    GameState* game = GameState::GetInstance();
    Variant* variants = data_02108ff4;
    unsigned char index = (unsigned char)(parameters++)->ToInt();
    for (int i = 0; i < 8; ++i)
    {
        unsigned short parameter = (unsigned short)(parameters++)->ToInt();
        unsigned char unknown = (unsigned char)(parameters++)->ToInt();
        unsigned char count = (unsigned char)(parameters++)->ToInt();
        if (i == game->unknownPlacementByte_5cda_)
        {
            variants[index].parameter = parameter;
            variants[index].unknown2 = unknown;
            variants[index].slotCount = count;
            return 1;
        }
    }
    return 0;
}

int WorldPlacementSource::ReadSpecialRecord(Script::Parameter* parameters, int)
{
    Record* record = (Record*)func_ov017_0218b5b0()->allocator_array_1a0[0].Allocate(sizeof(Record));
    record->next = 0;
    record->index = parameters->ToInt();
    record->slotCount = 8;
    record->type = 1;
    record->kind = 9;
    record->value = 0;
    ++parameters;
    for (int i = 0; i < 7; ++i) parameters = parameters->ToVec3fix(&record->positions[i]);
    record->state = 0;
    record->flags = 0;
    data_02108fe4.AppendRecord(record);
    return 1;
}

