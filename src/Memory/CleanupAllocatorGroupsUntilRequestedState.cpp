#include "Memory/HMRFAllocator.h"
struct StateOwner { HMRFAllocator* arena; SignedAllocatorList states; };
struct CleanupEntry {
    unsigned int links[2];
    unsigned int argument;
    void (*cleanup)(void*, unsigned int, unsigned int, unsigned int);
    unsigned int secondArgument, thirdArgument;
    unsigned int reserved[2];
    char payload[1];
};
extern "C" void RunReverseCleanupCallbacksAndRemoveGroups(StateOwner*);
extern "C" bool AllocateTwentyByteNodeAndAppendToAllocatorList(StateOwner*);
extern "C" void System_SubmitCommandOneAtomically();
#pragma optimize_for_size off
// Original: arm9/main @ 0x020BDB0C; symbol: func_020bdb0c; size: 0xD4.
extern "C" void CleanupAllocatorGroupsUntilRequestedState(StateOwner* owner, int state)
{
    SignedAllocatorList* group;
    bool cleaned;
    CleanupEntry* entry;
    entry = 0;
    cleaned = false;
    if (!state) { RunReverseCleanupCallbacksAndRemoveGroups(owner); return; }
    if (state < owner->states.numElements) { do {
        group = (SignedAllocatorList*)owner->states.ElementBefore(0);
        entry = (CleanupEntry*)group->ElementBefore((SignedAllocatorHeader*)entry);
        if (entry) { do {
            if (entry->cleanup) {
                entry->cleanup(entry->payload, entry->argument, entry->secondArgument, entry->thirdArgument);
                cleaned = true;
            }
            entry = (CleanupEntry*)group->ElementBefore((SignedAllocatorHeader*)entry);
        } while (entry); }
        owner->states.Remove((SignedAllocatorHeader*)group);
    } while (state < owner->states.numElements); }
    owner->arena->RestoreState(state);
    if (cleaned) System_SubmitCommandOneAtomically();
    owner->arena->SaveCurrentState(owner->states.numElements);
    AllocateTwentyByteNodeAndAppendToAllocatorList(owner);
}
