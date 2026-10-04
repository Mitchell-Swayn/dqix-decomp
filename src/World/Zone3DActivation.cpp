#include "World/Zone3D.h"
#include "World/ZonePredicates.h"
#include "GameState/GameState.h"

extern "C"
{
    void func_0201a600(Zone3D*);
    void func_020c5588(unsigned int, int, unsigned int, int, int);
    void func_0203b4d8(void*, int);
    void func_0203b4e8(void*, int);
    void func_020181fc(Zone3D*);
    void func_020100f8(GameState*);
}

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
    func_020c5588(backgroundColor, 16, 0x7fff, 0, 0);

    void* scene = func_ov017_0218b5b0();
    if (pUnknownStruct_8_->unknown_e_high_ == 0)
        func_0203b4d8(scene, 0x800);
    else
        func_0203b4e8(scene, 0x800);
    UpdateChestDiffuseColor();
    func_020181fc(this);
    func_020100f8(GameState::GetInstance());
    unk_830[1] = lightingManager->timeOfDayIndex_;
    unk_830[2] = 0;
    unknown_424_ = 0;
    unk_23bc[0] = 1;
    ApplyType2InstanceFlags();
    RestoreBMDJFlag4State();
    return true;
}
