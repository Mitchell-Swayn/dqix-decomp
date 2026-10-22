#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Zone3D.h"
ARM

// Serialized progress state (GameState_GetSerializedProgressState); complete type in
// Script_SetPackedEntryStateAndNotifyPeers.cpp.
struct PackedEntryStateOwner;

// Quest order node allocated by Script_AllocatePackedConditionalListNode and linked at
// order state +0xA0 by Quest_PrependOrderCondition.
struct QuestOrderNode {
    unsigned short id;
    unsigned short entryIndex : 9;                 // packed progress entry index
    unsigned short allowsCompletedOrNonzeroMember : 1;  // completed entries; nonzero local member in a session
    unsigned short requiresEntryHighFlag : 1;      // also required for progress-threshold activation
    unsigned short reactivatesWhenEligible : 1;    // completed entries may become active again
    unsigned short unknownFlags : 4;
    unsigned int actorTrigger : 8;
    unsigned int minimumProgressMajor : 6;         // compared with category 0 progress triple
    unsigned int minimumProgressMinor : 5;
    unsigned int unknownBits : 13;
    unsigned char* conditions;                     // trigger condition list, linked at +0xC
    QuestOrderNode* next;
};

// Global quest order state (Quest_GetGlobalOrderState).
struct QuestOrderState {
    unsigned char unknown[0xa0];
    QuestOrderNode* orders;
};

// Trigger condition evaluation context; callers initialize only the fields they use.
struct TriggerConditionContext {
    unsigned trigger;
    unsigned char unknown4[8];
    unsigned zoneId;
    unsigned char unknown10[0x24];
};

extern "C" void* GameState_GetSerializedProgressState();
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsSessionActive(int*);
extern "C" int Network_GetLocalMemberId(char*);
extern "C" void Script_GetCategoryProgressTriple(unsigned char*, int, unsigned char*, unsigned char*, unsigned char*);
extern "C" void* Zone3D_GetMainInstance();
extern "C" int LinkedList_TestEveryNodeWithPredicate(int, unsigned char*, int);
extern "C" int Script_GetPackedEntryState(volatile unsigned char*, int);
extern "C" unsigned int Script_GetEntryHighFlagMask(unsigned char*, int);
extern "C" int Quest_IsOrderStatusZeroOrOne(void*, int);
extern "C" void Script_SetPackedEntryStateAndNotifyPeers(PackedEntryStateOwner*, int, int);

static inline bool IsEntryState(unsigned char* progress, int index, int state)
{
    return Script_GetPackedEntryState(progress, index) == state;
}

// Original: arm9/main @ 0x02095B30; symbol: func_02095b30; size: 0x1CC.
// Activates (state 1) every quest order whose gates and trigger conditions pass in the current
// zone and whose entry is unset or active, or completed with reactivation allowed. With a
// progress threshold, only high-flag orders whose minimum category 0 progress is reached qualify.
extern "C" void Quest_ActivateEligibleOrders(void* orderState, bool applyProgressThreshold)
{
    GameState::GetInstance();
    unsigned char* progress = (unsigned char*)GameState_GetSerializedProgressState();
    void* connection = Network_GetConnectionManager();
    for (QuestOrderNode* node = ((QuestOrderState*)orderState)->orders; node != 0; node = node->next) {
        if (node->requiresEntryHighFlag && !Script_GetEntryHighFlagMask(progress, node->entryIndex))
            continue;
        if (Network_IsSessionActive((int*)connection) && Network_GetLocalMemberId((char*)connection) != 0
            && !node->allowsCompletedOrNonzeroMember)
            continue;
        if (applyProgressThreshold) {
            unsigned char major, minor, step;
            Script_GetCategoryProgressTriple(progress, 0, &major, &minor, &step);
            if (!node->requiresEntryHighFlag)
                continue;
            if (node->minimumProgressMajor * 100 + node->minimumProgressMinor > major * 100 + minor)
                continue;
        }
        TriggerConditionContext context;
        context.zoneId = ((Zone3D*)Zone3D_GetMainInstance())->currentZoneID_;
        if (!LinkedList_TestEveryNodeWithPredicate((int)progress, node->conditions, (int)&context))
            continue;
        if (IsEntryState(progress, node->entryIndex, 3) && !node->allowsCompletedOrNonzeroMember)
            continue;
        if (!Quest_IsOrderStatusZeroOrOne(progress, node->entryIndex)) {
            if (!IsEntryState(progress, node->entryIndex, 3))
                continue;
            if (!node->reactivatesWhenEligible)
                continue;
        }
        Script_SetPackedEntryStateAndNotifyPeers((PackedEntryStateOwner*)progress, node->entryIndex, 1);
    }
}
