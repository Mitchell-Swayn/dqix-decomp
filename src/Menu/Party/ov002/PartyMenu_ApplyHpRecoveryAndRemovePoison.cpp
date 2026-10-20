#include <globaldefs.h>
#include "GameState/GameState.h"
struct Record { unsigned char first; unsigned char pad; unsigned short middle; unsigned char last; };
struct ActionAmountRecord;
struct AmountParameters;
struct IndexedActionSearch { unsigned low:14; unsigned key:8; unsigned high:10; };
extern "C" void* GameState_GetIndexList(GameState* state);
extern "C" void *Network_GetConnectionManager();
extern "C" bool Network_IsSessionActive(int *param_1);
extern "C" int PartyRoster_ContainsActiveObjectIndex(unsigned char* p,unsigned int value);
extern "C" void PartyMenu_ClearTargetActionResult(Record* p);
extern "C" int GameState_TestMatchingOrCompatibleObjectIdentifiers(int unused,int first,int second);
extern "C" bool PartyMenu_HasTargetActionBlocker(int ignored, int value);
extern "C" int GameState_HasFlaggedObjectValue(void* unused, int key);
extern "C" int ActionData_FindDamageInPrimaryOrSecondaryTable(char* p,unsigned value);
extern "C" int PartyMenu_ComputeRandomizedRecoveryAmount(void* unused,ActionAmountRecord* action,AmountParameters* parameters,int memberIndex);
extern "C" short Combat_AddCappedValue(void* unused,int index,int amount,unsigned char* status);
extern "C" int PartyMenu_ClearTargetStatusMask(void*,int key,unsigned mask,unsigned char* result);
extern "C" void Network_QueueCurrentPartyMemberState(int index,int a,int b,int c);
// Original: arm9/ov002 @ 0x02154020; symbol: PartyMenu_ApplyHpRecoveryAndRemovePoison; size: 0x210.
// Populates paired six-byte records for each requested identifier and queues qualifying state packets.
extern "C" int PartyMenu_ApplyHpRecoveryAndRemovePoison(void* owner, unsigned char* request, ActionAmountRecord* actionRecord, int unused) {
    (void)unused;
    if (!request) return 0;
    if (!actionRecord) return 0;
    GameState* gameState = GameState::GetInstance();
    unsigned char* indexList = (unsigned char*)GameState_GetIndexList(gameState);
    int* connection = (int*)Network_GetConnectionManager();
    int processed = 0;
    Record* firstRecords = (Record*)(request + 8);
    Record* secondRecords = (Record*)(request + 0x20);
    for (int i = 0; i < 4; ++i) {
        PartyMenu_ClearTargetActionResult(firstRecords + i);
        PartyMenu_ClearTargetActionResult(secondRecords + i);
    }
    for (int i = 0; i < request[3]; ++i) {
        unsigned char* first = (unsigned char*)(firstRecords + i);
        unsigned char* second = (unsigned char*)(secondRecords + i);
        signed char id = *(signed char*)(request + 4 + i);
        if (!PartyRoster_ContainsActiveObjectIndex(indexList, id)) {
            first[4] = 1;
            second[4] = 1;
        }
        if (!GameState_TestMatchingOrCompatibleObjectIdentifiers((int)owner, id, (signed char)request[2])) {
            first[0] = 1;
            goto next;
        }
        if (PartyMenu_HasTargetActionBlocker((int)owner, id)) {
            first[0] = 2;
            goto next;
        }
        if (!GameState_HasFlaggedObjectValue(owner, id)) goto next;
        unsigned value = ((IndexedActionSearch*)((unsigned char*)actionRecord + 8))->key;
        AmountParameters* parameters = (AmountParameters*)ActionData_FindDamageInPrimaryOrSecondaryTable(*(char**)owner, value);
        if (!parameters) goto next;
        int amount = PartyMenu_ComputeRandomizedRecoveryAmount(owner, actionRecord, parameters, (signed char)request[2]);
        if (first[4]) {
            *(unsigned short*)(first + 2) = (unsigned short)amount;
            first[0] = 3;
        } else {
            *(unsigned short*)(first + 2) = (unsigned short)Combat_AddCappedValue(owner, id, amount, first);
        }
        if (second[4]) {
            *(unsigned short*)(second + 2) = 1;
            second[0] = 3;
        } else {
            *(unsigned short*)(second + 2) = (unsigned short)PartyMenu_ClearTargetStatusMask(owner, id, 2, second);
        }
        if (!first[0] && !second[0]) goto next;
        if (Network_IsSessionActive(connection) && PartyRoster_ContainsActiveObjectIndex(indexList, id))
            Network_QueueCurrentPartyMemberState(id, 0, 0, 1);
        processed = 1;
    next:
        ;
    }
    return processed;
}
