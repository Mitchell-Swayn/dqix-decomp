#include <globaldefs.h>
#include <std_library_functions.h>
#include <System/Cache.h>
ARM
#pragma optimization_level 4
extern "C" void GameObject_InitializeCombatStateLinks(void);
// Original: arm9/main @ 0x02048614; symbol: func_02048614; size: 0x7C.
extern "C" void InitializeFlag400ObjectAndEmbeddedFields(unsigned short *state) {
    GameObject_InitializeCombatStateLinks();
    unsigned short flags = *state;
    unsigned int zero = 0;
    *state = flags | 0x400;
    *(unsigned int *)((char *)state + 0x148) = zero;
    *(unsigned int *)((char *)state + 0x144) = zero;
    ((unsigned char *)state)[0x17c] = 0;
    ((unsigned char *)state)[0x17d] = 0;
    ((unsigned char *)state)[0x17e] = 0;
    ((unsigned char *)state)[0x17f] = 0;
    ((unsigned char *)state)[0x180] = 0;
    ((unsigned char *)state)[0x181] = 0;
    ((unsigned char *)state)[0x182] = 0;
    ((unsigned char *)state)[0x183] = 0;
    unsigned char *bytes = (unsigned char *)state;
    bytes[0x184] = 0;
    memset(bytes + 0x14c, zero, 0x30);
    *(unsigned short *)(bytes + 0x186) = 0;
    *(unsigned short *)(bytes + 0x188) = 0;
    *(unsigned short *)(bytes + 0x18a) = 0;
    bytes[0x18c] = 0;
    bytes[0x18d] = 0;
    *(unsigned short *)(bytes + 0x18e) = 0x1000;
}
