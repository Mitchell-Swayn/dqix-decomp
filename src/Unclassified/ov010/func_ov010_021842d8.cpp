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
void SetByteFieldAtOffset253ToOne(void*);
void func_ov010_021842a0(Overlay10State*);
extern unsigned char data_02114e20[];
}
// Original: arm9/ov010 @ 0x021842D8; symbol: func_ov010_021842d8; size: 0x7C.
extern "C" void func_ov010_021842d8(Overlay10State* state) {
    RemoveMatchingNodeAndResetMatchingObjectSlots(Object_GetGlobalSixteenEntryDisplayState(), 17);
    void* allocation = state->resource.GetSignedAllocator();
    if (allocation) {
        state->resource.Destroy();
        Memory_FreeThroughAllocatorUnion(data_02114e20, allocation);
    }
    if (state->handle >= 0) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        loader->RemoveTask(state->handle);
        state->handle = -1;
    }
    void* active = GameState::GetInstance()->GetUnknownGameObject();
    if (active) SetByteFieldAtOffset253ToOne(active);
    func_ov010_021842a0(state);
}
