#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
extern "C" void Object_ConfigureTextCountThroughEmbeddedHandler(void *object, int count);
extern "C" void func_020439b0(void *object, int value);
// Original: arm9/ov017 @ 0x021ACD00; symbol: func_ov017_021acd00; size: 0x24.
extern "C" void ConfigureGlobalTextObjectCountTwoAndReset(void) {
    unsigned int object = ReadWordFieldAtOffset1C();
    Object_ConfigureTextCountThroughEmbeddedHandler((void *)object, 2);
    func_020439b0((void *)object, 0);
}
