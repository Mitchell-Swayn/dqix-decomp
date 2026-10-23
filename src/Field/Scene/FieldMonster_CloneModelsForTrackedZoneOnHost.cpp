#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct TrackedZone { unsigned short identifier; unsigned short group:2; unsigned short rest:14; };
extern "C" void* ZoneState_GetTrackedZoneCache();
extern "C" TrackedZone* ZoneState_FindTrackedZoneByIdentifier(void*, int);
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsSessionActive(void*);
extern "C" int Network_GetLocalMemberId(void*);
extern "C" Object3D* Ov017_FindGameObjectByHalfwordId(void*,int);
// Original: arm9/ov017 @ 0x0219E180; symbol: func_ov017_0219e180; size: 0xB4.
// Clones displayed monster models into the tracked zone group on the host or offline.
extern "C" void FieldMonster_CloneModelsForTrackedZoneOnHost(void* self, int identifier) {
    GameState* game = GameState::GetInstance();
    void* cache = ZoneState_GetTrackedZoneCache();
    void* connection = Network_GetConnectionManager();
    if (Network_IsSessionActive(connection) && Network_GetLocalMemberId(connection)) return;
    TrackedZone* zone = ZoneState_FindTrackedZoneByIdentifier(cache, identifier);
    if (!zone) return;
    int group = zone->group;
    for (int i = 0; i < 12; ++i) {
        GameObject* monster = game->GetMaybeFieldMonsterByIndex(i + (group * 12 + 0x70));
        if (!monster) continue;
        Object3D* model = Ov017_FindGameObjectByHalfwordId(self, *(short*)((char*)monster + 2));
        if (model) model->ShallowCloneModelAndAnimationsTo((Object3D*)monster);
    }
}
