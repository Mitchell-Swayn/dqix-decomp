#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
struct Overlay10State {
    unsigned char phase, flag;
    unsigned short value;
    int handle;
    unsigned int auxiliary;
    unsigned char records[8];
    SafeAllocator resource;
};
extern "C" {
void* Object_GetGlobalSixteenEntryDisplayState();
void RemoveMatchingNodeAndResetMatchingObjectSlots(void*, int);
void Memory_FreeThroughAllocatorUnion(void*, void*);
void GameObject_RequestMovementInputEnable(void*);
void Pitfall_ResetPlacementSequence(Overlay10State*);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
}
// Original: arm9/ov010 @ 0x021842D8; symbol: func_ov010_021842d8; size: 0x7C.
extern "C" void Pitfall_ReleasePlacementSequence(Overlay10State* state) {
    RemoveMatchingNodeAndResetMatchingObjectSlots(Object_GetGlobalSixteenEntryDisplayState(), 17);
    void* allocation = state->resource.GetSignedAllocator();
    if (allocation) {
        state->resource.Destroy();
        Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3, allocation);
    }
    if (state->handle >= 0) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        loader->RemoveTask(state->handle);
        state->handle = -1;
    }
    void* active = GameState::GetInstance()->GetUnknownGameObject();
    if (active) GameObject_RequestMovementInputEnable(active);
    Pitfall_ResetPlacementSequence(state);
}
