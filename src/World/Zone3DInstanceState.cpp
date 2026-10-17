#include "World/Zone3D.h"
#include "GameState/GameState.h"

extern "C" void* GameState_ReadUnkF8(GameState*);
extern "C" void* ReadGlobalValueAt02108844();
extern "C" void InvokeHandlerForHalfwordIndexRange(void*, unsigned char, int, int);
extern "C" void SetBankedReverseBitFlag(void*, unsigned char, short, bool);

// The receiving state store and the gameplay meaning of flag 4 are unresolved.
// The two 128-entry ranges encode clear and set states separately.
// Original: arm9/main @ 0x02017C58; symbol: _ZN6Zone3D20RecordBMDJFlag4StateEv; size: 0x110.
void Zone3D::RecordBMDJFlag4State()
{
    GameState* game = GameState::GetInstance();
    if (!game) return;
    if (!GameState_ReadUnkF8(game)) return;
    void* state = ReadGlobalValueAt02108844();
    if (!state) return;
    for (int i = 0; i < 2; ++i)
    {
        InvokeHandlerForHalfwordIndexRange(state, i, 0, 0x7f);
        InvokeHandlerForHalfwordIndexRange(state, i, 0x80, 0xff);
    }
    int count;
    for (Zone3D_BMDJStruct* group = firstBMDJStruct_41c_; group; group = group->pNext_)
    {
        int groupID = group->unknown_0_;
        count = group->scriptData_.counter_10;
        for (int i = 0; i < count; ++i)
        {
            Zone3D_BMDJStruct::InstanceEntry* instance = &group->ptr_44[i];
            if (instance && (instance->flags & 4))
                SetBankedReverseBitFlag(state, groupID, instance->id + 0x80, true);
            else
                SetBankedReverseBitFlag(state, groupID, instance->id, true);
        }
    }
}

// These paired request bytes are consumed by zone-state processing.
// Original: arm9/main @ 0x02017D68; symbol: _ZN6Zone3D20SetBMDJStateRequestsEv; size: 0x14.
void Zone3D::SetBMDJStateRequests()
{
    unknown_281d_ = 1;
    unknown_281e_ = 1;
}

// Original: arm9/main @ 0x02017D7C; symbol: _ZN6Zone3D22ClearBMDJStateRequestsEv; size: 0x14.
void Zone3D::ClearBMDJStateRequests()
{
    unknown_281d_ = 0;
    unknown_281e_ = 0;
}
