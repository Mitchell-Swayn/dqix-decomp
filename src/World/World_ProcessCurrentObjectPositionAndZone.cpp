#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>
#include <std_library_functions.h>


extern "C" void Network_GetConnectionManager(void);
extern "C" int GameState_GetProgressChapter(void*);
extern "C" int GameResources_GetMaskedSecondaryFlags(int, int);
extern "C" void Object3D_SetPositionComponents(void*, int, int, int);

// Original: arm9/main @ 0x020AD1F8; symbol: func_020ad1f8; size: 0x2CC.
extern "C" void World_ProcessCurrentObjectPositionAndZone(Zone3D* zone, int arg1, int arg2, int arg3)
{
    GameState* game = GameState::GetInstance();
    GameResources_GetInstance();
    Network_GetConnectionManager();
    game->GetPartyMemberByIndex(0);
    void* object = (void*)game->GetUnknownGameObject();
    Vector3i position = *(Vector3i*)((unsigned char*)object + 0x44);
    unsigned short zoneId = *(unsigned short*)zone;
    if (zoneId == 0x1198) {
        if (*(unsigned short*)((unsigned char*)zone + 0x27b4) == 1) {
            zone->ClearInstanceFlag4(7, 0);
            zone->ClearInstanceFlag4(8, 0);
            zone->ClearInstanceFlag4(6, 0);
            zone->SetInstanceFlag4(5, 0);
        } else {
            zone->SetInstanceFlag4(7, 0);
            zone->SetInstanceFlag4(8, 0);
            zone->SetInstanceFlag4(6, 0);
            zone->ClearInstanceFlag4(5, 0);
            if (position.x < -0xc400 && position.z < (int)0xffff0b34)
                Object3D_SetPositionComponents(object, (int)0xffff0b34 + 0x3000, 0x42b8, (int)0xffff1c7b);
        }
    } else if (zoneId == (unsigned short)(0x1198 - 0xcb)) {
        if (*(unsigned short*)((unsigned char*)zone + 0x27b4) == 3) {
            zone->ClearInstanceFlag4(2, 0);
            zone->ClearInstanceFlag4(1, 0);
            zone->SetInstanceFlag4(10, 0);
        } else {
            zone->SetInstanceFlag4(2, 0);
            zone->SetInstanceFlag4(1, 0);
            zone->ClearInstanceFlag4(10, 0);
            int x = position.x;
            if (x > (int)0xfffff59a && x < 0x999 && position.z > 0x999 + 0x2000)
                Object3D_SetPositionComponents(object, 0, (int)0xffffa334, 0x2000);
        }
    } else if (zoneId == (unsigned short)(0x1198 - 0x68)) {
        int value = GameState_GetProgressChapter(game);
        if (*(unsigned short*)((unsigned char*)zone + 0x27b4) == 5 || value >= 0x13) {
            zone->ClearInstanceFlag4(0x17, 0);
            zone->ClearInstanceFlag4(1, 0);
            zone->SetInstanceFlag4(0x19, 0);
        } else {
            zone->SetInstanceFlag4(0x17, 0);
            zone->SetInstanceFlag4(1, 0);
            zone->ClearInstanceFlag4(0x19, 0);
            if (position.x > -0x2800 && position.x < (int)0xffffeccd && position.z > 0x2800)
                Object3D_SetPositionComponents(object, (int)0xffffe19a, (int)0xffffa334, 0x1ccc);
        }
    }
}
