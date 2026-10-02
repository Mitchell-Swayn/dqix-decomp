#include "World/Zone3D.h"
#include "GameState/GameState.h"

extern "C" {
    Zone3D* func_02012fe4();
    void func_0202ae18(void*);
    extern const Vector3i gGrottoEntranceUpdateScale;
    extern const Vector3i gGrottoEntranceShowScale;
}

void ZoneState2664::UpdateEntranceObject()
{
    if (unknown_b4)
    {
        GameState* game = GameState::GetInstance();
        unsigned short zone = func_02012fe4()->currentZoneID_;
        GrottoStruct* grotto = game->GetGrottoStruct();
        Vector3i scale = gGrottoEntranceUpdateScale;
        Vector3i position = *(Vector3i*)&grotto->entranceX;
        if (grotto->entranceZoneId && grotto->unknown_0[0])
        {
            if (grotto->entranceZoneId == zone)
            {
                object.position_ = position;
                object.SetScale(&scale);
                object.MaybeSetBCFGAnimation(0, 0);
                object.MakeVisible();
                unknown_b6 = 1;
            }
            unknown_b5 = 0;
        }
    }
}

bool ZoneState2664::ShowEntranceObject()
{
    if (func_02012fe4()->pUnknownStruct_8_->unknown_c_low_) return false;
    GameState* game = GameState::GetInstance();
    game->GetProtagonist();
    func_0202ae18(func_ov017_0218b5b0());
    GrottoStruct* grotto = game->GetGrottoStruct();
    Vector3i position;
    position = *(Vector3i*)&grotto->entranceX;
    Vector3i scale = gGrottoEntranceShowScale;
    object.position_ = position;
    object.SetScale(&scale);
    object.MaybeSetBCFGAnimation(0, 0);
    object.MakeVisible();
    unknown_b6 = 1;
    return true;
}

