#include <globaldefs.h>
ARM
struct GameResources;
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
extern "C" void ResetGlobalOwnerAndEmbeddedSelectionState(void*);
extern "C" void ClearAndStageSharedGraphicsBuffers(char*);
extern "C" void* ReadGlobalValueAt02108D5C(void);
extern "C" void SetTickDurationMillisecondsAndActiveFlags(void*, unsigned);
extern "C" GameResources* GameResources_GetInstance(void);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*, int, int);
// Original: arm9/ov001 @ 0x02154DA0; symbol: func_ov001_02154da0; size: 0x44.
extern "C" void Graphics_ResetSharedSceneState(void) {
    unsigned char* owner = (unsigned char*)ReadWordFieldAtOffset1C();
    ResetGlobalOwnerAndEmbeddedSelectionState(owner);
    ClearAndStageSharedGraphicsBuffers((char*)owner);
    owner[0x19be] = 0;
    SetTickDurationMillisecondsAndActiveFlags(ReadGlobalValueAt02108D5C(), 0);
    _Z13SetBrightnessP13GameResourcesii(GameResources_GetInstance(), -16, 0);
}
