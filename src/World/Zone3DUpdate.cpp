#include "World/Zone3D.h"
#include "GameState/GameState.h"

extern "C"
{
    int func_02046b24(void*);
    void func_020397c0(GameObject*);
    void func_02017208(Zone3D*);
    void func_020a84e0();
}

void Zone3D::Update()
{
    GameState* game = GameState::GetInstance();
    if (!unknown_428_) return;
    if (unknown_424_)
    {
        ProcessPendingLoads();
        return;
    }
    for (Zone3D_BMDJStruct* group = firstBMDJStruct_41c_; group; group = group->pNext_)
        UpdateBMDJInstances(group);
    if (unk_830[0])
    {
        if (--unk_830[0] == 0)
        {
            GameObject* protagonist = game->GetProtagonist();
            if (protagonist)
            {
                if (func_02046b24(func_ov017_0218b5b0()->unknown_ptr_array_36fc[0]) != 4)
                    func_020397c0(protagonist);
            }
            unk_830[0] = 0;
        }
    }
    func_02017208(this);
    DrawChestModels();
    LightingManager::GetInstance()->RecomputeAdvancedLighting();
    func_020a84e0();
    RecordCurrentZoneFlag();
    ProcessTransitionRequests();
    ResetGrottoStateOutsideGrotto();
}

void Zone3D::UpdateBMDJInstances(Zone3D_BMDJStruct* group)
{
    int count = group->scriptData_.counter_10;
    for (int i = 0; i < count; ++i)
        UpdateBMDJInstance(&group->ptr_44[i]);
}
