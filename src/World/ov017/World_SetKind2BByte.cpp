#include <globaldefs.h>
ARM
extern "C" void InitializeKind2BObjectAndClearFields(unsigned char* p);
extern "C" void AppendLinkedNodeAndMarkActive(unsigned int *p, unsigned int n);
// Original: arm9/ov017 @ 0x021B146C; symbol: func_ov017_021b146c; size: 0x34.
extern "C" void World_SetKind2BByte(unsigned char* world, unsigned char value) {
    InitializeKind2BObjectAndClearFields(*(unsigned char**)(world + 0x3b44));
    *(unsigned char*)(*(unsigned char**)(world + 0x3b44) + 0x49) = value;
    AppendLinkedNodeAndMarkActive(*(unsigned int**)(world + 0x36fc), (unsigned int)*(unsigned char**)(world + 0x3b44));
}
