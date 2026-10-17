#include <globaldefs.h>
ARM
extern "C" void InitializeType42Record(unsigned char* object);
extern "C" void AppendLinkedNodeAndMarkActive(unsigned int *p, unsigned int n);
// Original: arm9/ov017 @ 0x0218D77C; symbol: func_ov017_0218d77c; size: 0x34.
extern "C" void World_SetIndexedByteValue(unsigned char* world, unsigned int value) {
    InitializeType42Record(*(unsigned char**)(world + 0x3b40));
    *(unsigned int*)(*(unsigned char**)(world + 0x3b40) + 8) = value;
    AppendLinkedNodeAndMarkActive(*(unsigned int**)(world + 0x36fc), (unsigned int)*(unsigned char**)(world + 0x3b40));
}
