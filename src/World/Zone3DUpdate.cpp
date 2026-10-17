#include "World/Zone3D.h"
#include "GameState/GameState.h"

extern "C"
{
    int ReadIndirectByteOrMinusOne(void*);
    void SetByteFieldAtOffset253ToOne(GameObject*);
    void Object_AdvanceFallingFourPartEntries(Zone3D*);
    void ZoneFeatures_UpdateOpcode6aStateForPartyAndZone();
}

// Original: arm9/main @ 0x02015438; symbol: _ZN6Zone3D6UpdateEv; size: 0xE0.
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
                if (ReadIndirectByteOrMinusOne(GameResources_GetInstance()->unknown_ptr_array_36fc[0]) != 4)
                    SetByteFieldAtOffset253ToOne(protagonist);
            }
            unk_830[0] = 0;
        }
    }
    Object_AdvanceFallingFourPartEntries(this);
    DrawChestModels();
    LightingManager::GetInstance()->RecomputeAdvancedLighting();
    ZoneFeatures_UpdateOpcode6aStateForPartyAndZone();
    RecordCurrentZoneFlag();
    ProcessTransitionRequests();
    ResetGrottoStateOutsideGrotto();
}

// Original: arm9/main @ 0x02015518; symbol: _ZN6Zone3D19UpdateBMDJInstancesEP17Zone3D_BMDJStruct; size: 0x3C.
void Zone3D::UpdateBMDJInstances(Zone3D_BMDJStruct* group)
{
    int count = group->scriptData_.counter_10;
    for (int i = 0; i < count; ++i)
        UpdateBMDJInstance(&group->ptr_44[i]);
}
