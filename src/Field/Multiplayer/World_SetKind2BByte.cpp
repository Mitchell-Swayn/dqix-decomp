#include <globaldefs.h>
ARM
extern "C" void Field_InitializeOverlayTransitionTask(unsigned char* p);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned int *p, unsigned int n);
// Original: arm9/ov017 @ 0x021B146C; symbol: func_ov017_021b146c; size: 0x34.
extern "C" void World_SetKind2BByte(unsigned char* world, unsigned char value) {
    Field_InitializeOverlayTransitionTask(*(unsigned char**)(world + 0x3b44));
    *(unsigned char*)(*(unsigned char**)(world + 0x3b44) + 0x49) = value;
    LinkedQueue_AppendAndMarkActive(*(unsigned int**)(world + 0x36fc), (unsigned int)*(unsigned char**)(world + 0x3b44));
}
