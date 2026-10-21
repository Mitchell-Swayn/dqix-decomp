#include <globaldefs.h>
ARM
#pragma opt_propagation off
#include "GameState/GameState.h"
#include "World/Zone3D.h"

struct Entry {
    unsigned head;
    short x, y, z;
    short pad[3];
};
struct List {
    unsigned char pad[2], count, reserved;
    Entry* entries;
};
struct Placement {
    int x, y, z;
};

extern "C" GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
extern "C" int FindNearestEntryToFixedPointPosition(List* list, const Vector3fix* point);
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsParentOrOffline(unsigned* p);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void FieldMonster_SpawnFromTrackedZoneRecord(GameResources* resources, int monsterId, int count, int unused, Placement* offset, int a, int b, int flags);
extern "C" unsigned ZoneEncounterLoaderFinalizeNavigationAndEncounterData_UnknownRoleInitializedBytes[];

// Original: arm9/ov017 @ 0x021B5648; symbol: func_ov017_021b5648; size: 0x1b4.
// Snaps party objects to the nearest navigation entry for the tracked zone record,
// then parent/offline hosts spawn the tracked encounter using grotto-environ placement.
extern "C" void ZoneEncounterLoader_FinalizeNavigationAndEncounterData(unsigned char* self) {
    GameState* game = GameState::GetInstance();
    unsigned* connection = (unsigned*)Network_GetConnectionManager();
    for (int i = 0; i < 4; ++i) {
        GameObject* object = GameState_GetObjectWithFlag100(game, i);
        if (object) {
            unsigned char* tracked = *(unsigned char**)(self + 8);
            if (((Object3D*)object)->GetField06() == *(unsigned short*)tracked) {
                *(short*)((unsigned char*)object + 0xb8) = (short)FindNearestEntryToFixedPointPosition(
                    (List*)(tracked + 0x18),
                    &((Object3D*)object)->position_);
                ((unsigned char*)object)[0xc2] |= 0x40;
            }
        }
    }
    if (Network_IsParentOrOffline(connection) && *(unsigned short*)(self + 0x12)) {
        game = GameState::GetInstance();
        GameResources* resources = GameResources_GetInstance();
        game->GetGrottoStruct();
        unsigned char* zone = (unsigned char*)Zone3D_GetMainInstance();
        int environ = ((ActiveGrottoClass*)(zone + 0x3ec + 0x2000))->GetActiveGrottoEnviron() & 0xff;
        Placement placement = *(const Placement*)ZoneEncounterLoaderFinalizeNavigationAndEncounterData_UnknownRoleInitializedBytes;
        switch (environ) {
        case 1:
            placement.z = 0xfffecccd;
            break;
        case 2:
            placement.z = 0xffff019a;
            break;
        case 3:
            placement.z = -0x13800;
            break;
        case 4:
            placement.z = 0xfffecccd;
            break;
        case 5:
            placement.z = 0xfffebb34;
            break;
        default:
            placement.z = 0xfffecccd;
            break;
        }
        unsigned char flags = 0;
        unsigned char kind = self[0x11];
        if (kind == 1) {
            flags = (unsigned char)(flags | 2);
        } else if (kind == 2) {
            flags = (unsigned char)(flags | 4);
        }
        FieldMonster_SpawnFromTrackedZoneRecord(
            resources,
            *(unsigned short*)(*(unsigned char**)(self + 8)),
            *(unsigned short*)(self + 0x12),
            -1,
            &placement,
            0,
            0,
            flags);
    }
    unsigned short* marker = (unsigned short*)(*(unsigned char**)(self + 8) + 2);
    *marker = (unsigned short)(*marker | 8);
    self[1] = 1;
}
