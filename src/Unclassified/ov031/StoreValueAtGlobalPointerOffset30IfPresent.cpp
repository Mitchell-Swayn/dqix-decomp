#include <globaldefs.h>
ARM
extern "C" void *data_ov031_0224e588;
// Original: arm9/ov031 @ 0x022101AC; symbol: func_ov031_022101ac; size: 0x18.
extern "C" void StoreValueAtGlobalPointerOffset30IfPresent(unsigned int value) {
    void *object = data_ov031_0224e588;
    if (object)
        *(unsigned int *)((char *)object + 0x30) = value;
}
