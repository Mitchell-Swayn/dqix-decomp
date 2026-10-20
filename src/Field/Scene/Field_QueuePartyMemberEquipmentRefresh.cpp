#include <globaldefs.h>
ARM
#include "GameState/GameState.h"
extern "C" void* Network_GetConnectionManager();
extern "C" int Field_IsClientPartyTransitionRestricted();
struct RestoreState;
extern "C" void GameState_RestoreMaskedPartyMemberTransform(RestoreState*, int);
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*, int);
typedef unsigned int undefined4;
extern "C" ARM undefined4 GameObject_GetLinkedIndexedState(int);
extern "C" int GameObject_HasLinkedStatusNibble(char*);
extern "C" ARM void GameState_BuildEquipmentObjectIdsAndDefaultValues(int, int*, short*);
struct Record { unsigned short field0; unsigned char active, busy; unsigned unknown; short id; unsigned char tail[0x3e]; };
struct Owner { unsigned char pad[0x373c]; Record entries[12]; };
extern "C" Record* Util_FindMatchingRecordOrInitializeFreeSlot(Owner*, int);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned int*, unsigned int);
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*, int);
// Original: arm9/ov017 @ 0x0218F5A4; symbol: func_ov017_0218f5a4; size: 0x1B4.
// Updates a party member's owner record when the recorded equipment state differs.
extern "C" int Field_QueuePartyMemberEquipmentRefresh(unsigned char* owner, int index, int restoreFlag, int markFlag, int deferredFlag) {
    GameState* game = GameState::GetInstance();
    void* globalState = Network_GetConnectionManager();
    RestoreState* restoreState = (RestoreState*)*(unsigned char**)(owner + 0x3734);
    if (Field_IsClientPartyTransitionRestricted()) {
        void* member = game->GetPartyMemberByIndex(index);
        if (member && (*(unsigned short*)member & 0x1000)) {
            GameState_RestoreMaskedPartyMemberTransform(restoreState, index & 0xff);
            return 0;
        }
    }

    GameObject* object = GameState_GetObjectWithFlag100(game, index);
    if (!object) return 0;
    undefined4 field150Result = GameObject_GetLinkedIndexedState((int)object);
    if (!field150Result) return 0;

    if (deferredFlag) goto update_record;
    void* field150 = *(void**)((unsigned char*)object + 0x150);
    int field150Flag = field150 ? *((unsigned char*)field150 + 0x56e) : 0;
    if (field150Flag != 0 || restoreFlag != 0) goto update_record;
    if (GameObject_HasLinkedStatusNibble((char*)object)) goto update_record;

    int ids[11];
    short values[11];
    GameState_BuildEquipmentObjectIdsAndDefaultValues(index, ids, values);
    int differs = 0;
    for (int i = 0; i < 11; ++i) {
        if (i != 10) {
            GameObject* member = game->GetGameObjectByIndex(ids[i]);
            if (member) {
                short expectedValue = values[i];
                short currentValue = *(short*)((unsigned char*)member + 2);
                if (expectedValue != currentValue) differs = 1;
            }
        }
    }
    if (!differs) return 0;

update_record:
    Record* record = Util_FindMatchingRecordOrInitializeFreeSlot((Owner*)owner, index);
    if (!record) goto success;
    unsigned char* recordBytes = (unsigned char*)record;
    *(unsigned short*)(recordBytes + 8) = (unsigned short)index;
    if (restoreFlag) recordBytes[0xb] |= 2;
    if (markFlag || (*(unsigned*)((unsigned char*)object + 0x18c) & 0x40)) recordBytes[0xb] |= 4;
    if (deferredFlag) recordBytes[0xb] |= 1;
    if (recordBytes[2] == 0) LinkedQueue_AppendAndMarkActive(*(unsigned int**)(owner + 0x3700), (unsigned int)record);
success:
    return 1;
}
