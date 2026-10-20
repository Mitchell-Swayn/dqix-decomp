#include <globaldefs.h>
ARM
extern "C" void* memset(void*, int, unsigned int);
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*, unsigned int);
struct State;
extern "C" void BattleMenu_ResetListedPartyCommands(void*);
extern "C" void BattleMenu_UpdateMemberRowPositions(void*);
extern "C" void BattleMenu_RepositionCommandWindowsAroundActor(void*);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
extern "C" void Window_ClearResourceBuffers(unsigned char*);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(unsigned char*);
extern "C" void Window_ResetResourceTransfers(void*);
extern "C" void Window_PopCanvasesAndResetSelection(State*, int);
// Original: arm9/ov000 @ 0x0217E46C; symbol: ResetObjectResourcesIfTriggered; size: 0xEC.
extern "C" void BattleMenu_ResetCommandsOnReviewCancel(void* object) {
    if (Input_IsKeyMaskNewlyPressed((unsigned short*)KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x802) == 0 && Main_UnknownRoleZeroInitializedStorage_Variant4[0x55] == 0) return;
    BattleMenu_ResetListedPartyCommands(object);
    BattleMenu_UpdateMemberRowPositions(object);
    BattleMenu_RepositionCommandWindowsAroundActor(object);
    *(unsigned*)((char*)object + 0x920) = 0x100;
    *(unsigned*)((char*)object + 0x92c) = 8;
    *(unsigned*)((char*)object + 0x924) = 0x100;
    *(unsigned*)((char*)object + 0x928) = 0x100;
    unsigned short* state = (unsigned short*)((char*)object + 0x1d72);
    *state &= ~0x38;
    BattleMenu_UpdateMemberRowPositions(object);
    memset((char*)object + 0x1d60, 0, 8);
    *((unsigned char*)object + 0x1d68) = 0;
    int index = *(signed char*)((char*)object + 0x1d68);
    *((unsigned char*)object + 0x1d60 + index) = 1;
    Window_ClearResourceBuffers((unsigned char*)object + 0x188);
    Graphics_ResetCountedThirtyTwoByteTransfers((unsigned char*)object + 0x188);
    Window_ResetResourceTransfers((char*)object + 0x188);
    Window_PopCanvasesAndResetSelection((State*)((char*)object + 0x188), 1);
    *state |= 2;
}
