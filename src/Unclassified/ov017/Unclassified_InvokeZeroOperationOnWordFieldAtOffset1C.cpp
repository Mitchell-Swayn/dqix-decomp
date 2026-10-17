#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
extern "C" void func_020439b0(unsigned int *, int);
// Original: arm9/ov017 @ 0x021ADC44; symbol: func_ov017_021adc44; size: 0x14.
extern "C" void Unclassified_InvokeZeroOperationOnWordFieldAtOffset1C(void) {
    unsigned int *field = (unsigned int *)ReadWordFieldAtOffset1C();
    func_020439b0(field, 0);
}
