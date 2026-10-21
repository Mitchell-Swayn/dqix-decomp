#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct Record {
    unsigned char first;
    unsigned char pad;
    unsigned short middle;
    unsigned char last;
};
extern "C" {
void* GameState_GetIndexList(GameState* state);
void* Network_GetConnectionManager();
bool Network_IsSessionActive(int* param_1);
int PartyRoster_ContainsActiveObjectIndex(unsigned char* p, unsigned int value);
void PartyMenu_ClearTargetActionResult(Record* p);
int PartyMenu_ClearTargetStatusMask(void*, int key, unsigned mask, unsigned char* result);
int GameState_HasFlaggedObjectValue(void* unused, int key);
int GameState_TestMatchingOrCompatibleObjectIdentifiers(int unused, int first, int second);
bool PartyMenu_HasTargetActionBlocker(int ignored, int value);
void Network_QueueCurrentPartyMemberState(int index, int a, int b, int c);
}
// Original: arm9/ov002 @ 0x02153EA4; symbol: func_ov002_02153ea4; size: 0x17c.
// Clears one four-record result bank, removes poison on eligible targets, and queues connection notifications.
extern "C" int PartyMenu_RemovePoisonFromTargets(char* self, char* action, char* record, int secondBank) {
    if (!action) return 0;
    if (!record) return 0;
    unsigned char* list = (unsigned char*)GameState_GetIndexList(GameState::GetInstance());
    int* connection = (int*)Network_GetConnectionManager();
    register int changed;
    register Record* results;
    results = (Record*)(action + 8);
    changed = 0;
    if (secondBank) results = (Record*)(action + 0x20);
    for (int i = 0; i < 4; i++)
        PartyMenu_ClearTargetActionResult(results + i);
    for (int i = 0; i < *(unsigned char*)(action + 3); i++) {
        Record* result = results + i;
        int target = *(signed char*)(action + 4 + i);
        if (!PartyRoster_ContainsActiveObjectIndex(list, target))
            result->last = 1;
        if (!GameState_TestMatchingOrCompatibleObjectIdentifiers((int)self, target, *(signed char*)(action + 2)))
            result->first = 1;
        else if (PartyMenu_HasTargetActionBlocker((int)self, target))
            result->first = 2;
        else if (GameState_HasFlaggedObjectValue(self, target)) {
            if (result->last) {
                result->middle = 1;
                result->first = 3;
            } else
                result->middle = (unsigned short)PartyMenu_ClearTargetStatusMask(self, target, 2, (unsigned char*)result);
            if (result->first) {
                if (Network_IsSessionActive(connection) && PartyRoster_ContainsActiveObjectIndex(list, target))
                    Network_QueueCurrentPartyMemberState(target, 0, 0, 1);
                changed = 1;
            }
        }
    }
    return changed;
}
