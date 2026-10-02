#include "World/Zone3D.h"
#include "GameState/GameState.h"

extern "C" void* func_0200fd0c(GameState*);
extern "C" void* func_0205ec34();
extern "C" bool func_0206eaec(void*, unsigned char, short);

// Only the zone ID field is initialized for these two state notifications.
// Remaining payload fields and the event numbers are not yet understood.
struct BMDJStateNotification
{
    int unknown_0[3];
    int zoneID;
    int unknown_10[9];
};
extern "C" void func_02064b24(void*, int, int, BMDJStateNotification*);

void Zone3D::RestoreBMDJFlag4State()
{
    GameState* game = GameState::GetInstance();
    if (!game) return;
    if (!func_0200fd0c(game)) return;
    void* state = func_0205ec34();
    if (!state || !unknown_281d_) return;
    for (int groupID = 0; groupID < 2; ++groupID)
    {
        for (int i = 0; i < 0x7f; ++i)
        {
            if (func_0206eaec(state, groupID, i))
            {
                Zone3D_BMDJStruct::InstanceEntry* instance = FindBMDJInstance(groupID, i);
                if (instance) instance->flags &= ~4;
            }
        }
        for (int i = 0x80; i < 0xff; ++i)
        {
            if (func_0206eaec(state, groupID, i))
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
    func_02064b24(state, 3, 0x6c, &notification);
    func_02064b24(state, 0x14, 0x6c, &notification);
    unknown_281d_ = 0;
}
