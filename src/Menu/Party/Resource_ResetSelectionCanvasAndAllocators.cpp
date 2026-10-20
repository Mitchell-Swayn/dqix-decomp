#include <globaldefs.h>
ARM
struct State;
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void Window_PopCanvasesAndResetSelection(State* p,int flag);
extern "C" int PartyMenu_GetSelectableMemberIndex(void*,int);
extern "C" void Resource_CopySignedHalfwordsToSharedObject(void* object);
extern "C" void GameState_ResetNestedAllocatorState(void*);
extern "C" void SafeAllocator_CreateFiveTypedRecords(void*,void*);
extern "C" void Graphics_InitializeCanvasAndDisplaySnapshot(void*,int);
// Original: arm9/ov002 @ 0x021682C0; symbol: func_ov002_021682c0; size: 0x94.
extern "C" void Resource_ResetSelectionCanvasAndAllocators(unsigned char *self) {
    *(unsigned*)(self+0x247c) &= ~4;
    Resource_CopySignedHalfwordsToSharedObject(self);
    Window_PopCanvasesAndResetSelection((State*)(self+0xec8),1);
    self[0x2454]=0;
    self[0x2455]=0;
    GameState_ResetNestedAllocatorState(self);
    _ZN13SafeAllocator5ResetEv(self+0x850);
    Graphics_InitializeCanvasAndDisplaySnapshot(self+0x1d04,1);
    SafeAllocator_CreateFiveTypedRecords(self+0x1d04,self+0x850);
    self[0x1d6b]=PartyMenu_GetSelectableMemberIndex(self,*(short*)(self+0x1c08));
    ++*(int*)(self+0x1bc0);
}
