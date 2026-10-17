#include "World/Zone3D.h"
#include "World/ZonePredicates.h"
#include "GameState/GameState.h"

extern "C"
{
    void func_0201a600(Zone3D*);
    void WriteCaptureControlRegisterPair(unsigned int, int, unsigned int, int, int);
    void Object_SetUnsignedIntAtOffset4(void*, int);
    void ClearWordAtOffset4MaskedBits(void*, int);
    void func_020181fc(Zone3D*);
    void GameState_GetField3B0ObjectWithFlag4(GameState*);
}

// Original: arm9/main @ 0x02013E18; symbol: _ZN6Zone3D19ProcessPendingLoadsEv; size: 0x19C.
bool Zone3D::ProcessPendingLoads()
{
    if (!unknown_424_)
        return true;
    if (!ProcessMaplist9()) return false;
    if (!UnpackMapAMBL()) return false;
    if (!UnpackATS_AMBL()) return false;
    if (!UnpackMapAMDJ()) return false;
    if (!ProcessAtmosphericEffects()) return false;

    int zoneID = pUnknownStruct_8_->unknown_0_;
    if (IsMainGrottoFloorZone(zoneID))
    {
        ComputeGrottoTileTypes(zoneID % 20, NULL, NULL, NULL);
        func_0201a600(this);
    }
    else if (IsGrottoBossFloorZone(zoneID))
        func_0201a600(this);

    LightingManager* lightingManager = LightingManager::GetInstance();
    lightingManager->ProcessZoneChange(this);
    int index = lightingManager->lightingIndexOverride_;
    int timeOfDay = lightingManager->timeOfDayIndex_;
    if (index) timeOfDay = index;
    unsigned int backgroundColor = lighting_.maybeMode_ == 1
        ? lighting_.basic_.backgroundColor[timeOfDay]
        : lighting_.advanced_.backgroundColor[timeOfDay];
    WriteCaptureControlRegisterPair(backgroundColor, 16, 0x7fff, 0, 0);

    void* scene = GameResources_GetInstance();
    if (pUnknownStruct_8_->unknown_e_high_ == 0)
        Object_SetUnsignedIntAtOffset4(scene, 0x800);
    else
        ClearWordAtOffset4MaskedBits(scene, 0x800);
    UpdateChestDiffuseColor();
    func_020181fc(this);
    GameState_GetField3B0ObjectWithFlag4(GameState::GetInstance());
    unk_830[1] = lightingManager->timeOfDayIndex_;
    unk_830[2] = 0;
    unknown_424_ = 0;
    unk_23bc[0] = 1;
    ApplyType2InstanceFlags();
    RestoreBMDJFlag4State();
    return true;
}
