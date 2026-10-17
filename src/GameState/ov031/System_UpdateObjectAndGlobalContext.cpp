#include <globaldefs.h>
ARM
extern "C" void Unclassified_FreeArgumentAndUpdateGlobalOwner(unsigned int value);
extern "C" void func_ov031_0223bf48(void *context, void *object);
extern "C" unsigned char *data_ov031_02290c40[];
// Original: arm9/ov031 @ 0x02227688; symbol: func_ov031_02227688; size: 0x2C.
extern "C" void System_UpdateObjectAndGlobalContext(void *object) {
    Unclassified_FreeArgumentAndUpdateGlobalOwner(*(unsigned int *)((char *)object + 8));
    void *context = *(void **)((char *)data_ov031_02290c40[0] + 0x60);
    func_ov031_0223bf48(context, object);
}
