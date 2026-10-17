#include <globaldefs.h>
ARM

extern "C" unsigned int OV017_ReadWordField04(void *);
extern "C" void func_ov001_0215ec94(unsigned, unsigned);
extern "C" unsigned char data_ov001_021658b8[];

// Original: arm9/ov001 @ 0x0215ED74; symbol: func_ov001_0215ed74; size: 0x44.
extern "C" int Unclassified_ApplyIndexedActionToObjectSequence(void *objects, int endIndex) {
    int index = *(int *)(data_ov001_021658b8 + 0x88);
    unsigned char *object = (unsigned char *)objects;
    while (index < endIndex) {
        unsigned int value = OV017_ReadWordField04(object);
        object += 8;
        func_ov001_0215ec94(value, (unsigned)index);
        index++;
    }
    return 1;
}
