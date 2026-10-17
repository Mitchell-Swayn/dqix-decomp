#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
extern "C" void func_ov011_021848a0(void *, unsigned int);

// Original: arm9/ov004 @ 0x021652BC; symbol: func_ov004_021652bc; size: 0x2C.
extern "C" int Unclassified_SetStateValue65IfGlobalField998Zero(void *state) {
    unsigned char *global = (unsigned char *)ReadWordFieldAtOffset1C();
    if (*(unsigned int *)(global + 0x998) == 0)
        func_ov011_021848a0(state, 0x65);
    return 0;
}
