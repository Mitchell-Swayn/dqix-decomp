#include "World/Zone3D.h"
#include "GameState/GameState.h"

extern "C" void* func_0200fd0c(GameState*);
extern "C" void* func_0205ec34();
extern "C" void func_0206eb20(void*, unsigned char, int, int);
extern "C" void func_0206ea8c(void*, unsigned char, short, bool);

// The receiving state store and the gameplay meaning of flag 4 are unresolved.
// The two 128-entry ranges encode clear and set states separately.
void Zone3D::RecordBMDJFlag4State()
{
    GameState* game = GameState::GetInstance();
    if (!game) return;
    if (!func_0200fd0c(game)) return;
    void* state = func_0205ec34();
    if (!state) return;
    for (int i = 0; i < 2; ++i)
    {
        func_0206eb20(state, i, 0, 0x7f);
        func_0206eb20(state, i, 0x80, 0xff);
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
                func_0206ea8c(state, groupID, instance->id + 0x80, true);
            else
                func_0206ea8c(state, groupID, instance->id, true);
        }
    }
}

// These paired request bytes are consumed by zone-state processing.
void Zone3D::SetBMDJStateRequests()
{
    unknown_281d_ = 1;
    unknown_281e_ = 1;
}

void Zone3D::ClearBMDJStateRequests()
{
    unknown_281d_ = 0;
    unknown_281e_ = 0;
}
