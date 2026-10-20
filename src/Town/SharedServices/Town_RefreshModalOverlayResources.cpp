#include <globaldefs.h>
ARM
extern "C" void CharacterCreation_RefreshScreenTransfersAndText(void*);
// Original: arm9/ov003 @ 0x0217EEF4; symbol: func_ov003_0217eef4; size: 0x18.
extern "C" void Town_RefreshModalOverlayResources(void* p) { void* state = *(void**)((char*)p + 0x1c); if (state) CharacterCreation_RefreshScreenTransfersAndText(state); }
