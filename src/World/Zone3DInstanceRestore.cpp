#include "World/Zone3D.h"
#include "GameState/GameState.h"
#include "World/BMDJStateNotification.h"

extern "C" void* GameState_ReadUnkF8(GameState*);
extern "C" void* ReadGlobalValueAt02108844();
extern "C" bool BitMap_ReadReversedColumnBit(void*, unsigned char, short);

// Only the zone ID field is initialized for these two state notifications.
// Remaining payload fields and the event numbers are not yet understood.
extern "C" void LinkedList_TestPredicateForMatchingGroupId(void*, int, int, BMDJStateNotification*);

// Original: arm9/main @ 0x02017A94; symbol: _ZN6Zone3D21RestoreBMDJFlag4StateEv; size: 0x1C4.
void Zone3D::RestoreBMDJFlag4State()
{
    GameState* game = GameState::GetInstance();
    if (!game) return;
    if (!GameState_ReadUnkF8(game)) return;
    void* state = ReadGlobalValueAt02108844();
    if (!state || !unknown_281d_) return;
    for (int groupID = 0; groupID < 2; ++groupID)
    {
        for (int i = 0; i < 0x7f; ++i)
        {
            if (BitMap_ReadReversedColumnBit(state, groupID, i))
            {
                Zone3D_BMDJStruct::InstanceEntry* instance = FindBMDJInstance(groupID, i);
                if (instance) instance->flags &= ~4;
            }
        }
        for (int i = 0x80; i < 0xff; ++i)
        {
            if (BitMap_ReadReversedColumnBit(state, groupID, i))
            {
                Zone3D_BMDJStruct::InstanceEntry* instance = FindBMDJInstance(groupID, i - 0x80);
                if (!instance) continue;
                instance->flags |= 4;
                if (!(instance->flags & 8)) continue;
                instance->flags |= 1;
                ZoneFeatures::Opcode6aEntry* feature = bFeatures_.GetTypeEntries(2);
                for (; feature; feature = feature->pNext)
                {
                    if (feature->unk_2c.type2.unk_1 == instance->id)
                    {
                        feature->unk_2c.type2.unk_2_high |= 1;
                        break;
                    }
                }
            }
        }
    }
    BMDJStateNotification notification;
    notification.zoneID = currentZoneID_;
    LinkedList_TestPredicateForMatchingGroupId(state, 3, 0x6c, &notification);
    LinkedList_TestPredicateForMatchingGroupId(state, 0x14, 0x6c, &notification);
    unknown_281d_ = 0;
}
