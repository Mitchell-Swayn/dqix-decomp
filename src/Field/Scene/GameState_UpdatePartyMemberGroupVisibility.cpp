#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
extern "C" void* Zone3D_GetMainInstance();
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" int FieldEvent_IsQueuedOrSynchronizing(unsigned char*);
extern "C" void GameState_CopyPartyMemberGroup(int, signed char*, signed char*);
extern "C" void _ZN8Object3D11MakeVisibleEv(void*);
extern "C" void _ZN8Object3D10MakeHiddenEv(void*);
// Original: arm9/ov017 @ 0x021BD4D0; symbol: GameState_UpdatePartyMemberGroupVisibility; size: 0x100.
// Updates visibility for a party-member group after checking the selected member and state flags.
extern "C" ARM void GameState_UpdatePartyMemberGroupVisibility(unsigned char* self, int index, int mode, int updateAllowed) {
    void* gameState = _ZN9GameState11GetInstanceEv();
    void* selected = _ZN9GameState21GetPartyMemberByIndexEi(gameState, index);
    if (!selected) return;

    int shouldUpdate = 1;
    unsigned short current = *(unsigned short*)Zone3D_GetMainInstance();
    unsigned int selectedField = (unsigned int)_ZNK8Object3D10GetField06Ev(selected);
    if (selectedField != (unsigned int)current && mode == 0) shouldUpdate = 0;

    if (FieldEvent_IsQueuedOrSynchronizing(self)) {
        if (*(unsigned short*)(self + 0x16) == 0x2972 || self[0x101] == 0) updateAllowed = 0;
    }
    if (!shouldUpdate) return;
    if (updateAllowed && FieldEvent_IsQueuedOrSynchronizing(self)) return;

    struct Group { signed char count; signed char members[7]; } group;
    GameState_CopyPartyMemberGroup((signed char)index, group.members, &group.count);
    for (int i = 0; i < group.count; ++i) {
        void* member = _ZN9GameState21GetPartyMemberByIndexEi(gameState, group.members[i]);
        if (!member) continue;
        if (mode) _ZN8Object3D11MakeVisibleEv(member);
        else _ZN8Object3D10MakeHiddenEv(member);
    }
}
