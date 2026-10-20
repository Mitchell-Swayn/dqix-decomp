#include <globaldefs.h>
ARM
// Original: arm9/main:020541a4; For a nonnull backing state, sets state bytes 0x56c/0x56d, invokes the resource handler, stores a timestamp at +0x480, and queues a type-seventeen record; caller is GameState_ApplyPartyFlagInEligibleZone.
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameResources_GetInstance();
extern "C" void Field_UpdateCombatantAppearanceFlags(int, int, int, int);
extern "C" unsigned long long _Z19GetCurrentTimestampv();
extern "C" void Network_QueueTypeSeventeenRecord(void*, short, short, unsigned short);
struct Obj { unsigned char pad0[4]; unsigned short id; unsigned char pad6[0x14a]; void* state; };
extern "C" void GameState_MarkObjectStateAndQueueTypeSeventeen(Obj* self, unsigned char option) {
    if (self->state == 0) return;
    _ZN9GameState11GetInstanceEv();
    void* resources = GameResources_GetInstance();
    ((unsigned char*)self->state)[0x56c] = 1;
    ((unsigned char*)self->state)[0x56d] = option;
    Field_UpdateCombatantAppearanceFlags((int)resources, 1, (short)self->id, 2);
    unsigned long long timestamp = _Z19GetCurrentTimestampv();
    *(unsigned long long*)((unsigned char*)self->state + 0x480) = timestamp;
    Network_QueueTypeSeventeenRecord(0, 1, 1, (unsigned short)self->id);
}
