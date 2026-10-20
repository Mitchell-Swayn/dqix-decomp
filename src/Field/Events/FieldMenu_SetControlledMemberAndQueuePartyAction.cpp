#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void FieldScreen_QueueOverlayThreeSession(void*, int, int);
// Original: arm9/ov017 @ 0x021A4E0C; symbol: CopyGameStateHalfwordToNestedField22; size: 0x3C.
// Copies the game-state object signed halfword +4 to the nested object at self +0x371C, offset +0x22, then calls the update helper.
extern "C" void FieldMenu_SetControlledMemberAndQueuePartyAction(void* self) {
    void* game = _ZN9GameState11GetInstanceEv();
    void* object = _ZN9GameState20GetUnknownGameObjectEv(game);
    if (object == 0) return;
    short value = *(short*)((char*)object + 4);
    void* destination = *(void**)((char*)self + 0x371C);
    *(short*)((char*)destination + 0x22) = value;
    FieldScreen_QueueOverlayThreeSession(self, 1, 1);
}
