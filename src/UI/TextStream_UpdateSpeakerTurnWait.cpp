#include <globaldefs.h>
ARM
extern "C" void* ActorPool_GetGlobalInstance(void);
extern "C" unsigned int* ActorPool_GetActiveSlot(unsigned int**, unsigned int);
extern "C" void* Actor_GetRepresentationTargetYawOrZero(unsigned char*);
extern "C" int Actor_GetRepresentationCurrentYawOrZero(void*);
extern "C" void Actor_SetRepresentationTargetYaw(void*, unsigned int);
// Original: arm9/main @ 0x020656E4; symbol: func_020656e4; size: 0x74.
extern "C" int TextStream_UpdateSpeakerTurnWait(unsigned char* object) {
    if (object[0x1000 + 0x9b6] == 0) return 0;
    unsigned int** container = (unsigned int**)ActorPool_GetGlobalInstance();
    unsigned int* slot = ActorPool_GetActiveSlot(container, *(unsigned int*)(object + 0x1000 + 0x838));
    if (slot == 0) return 0;
    unsigned char result = 1;
    Actor_SetRepresentationTargetYaw(slot, *(unsigned int*)(object + 0x1000 + 0x844));
    void* data = Actor_GetRepresentationTargetYawOrZero((unsigned char*)slot);
    int coordinate = Actor_GetRepresentationCurrentYawOrZero(slot);
    if (data == (void*)coordinate) {
        object[0x1000 + 0x9b6] = 0;
        result = 0;
    }
    return result;
}
