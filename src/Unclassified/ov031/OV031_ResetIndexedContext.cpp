#include <globaldefs.h>
extern "C" void VectorizedMemset(void *, int, unsigned);
extern "C" void func_ov031_02236570(unsigned);
extern "C" unsigned char data_ov031_02290cfc[];
// Original: arm9/ov031 @ 0x02236484; symbol: func_ov031_02236484; size: 0x3C.
extern "C" void OV031_ResetIndexedContext(unsigned index) {
    unsigned char *context = *(unsigned char **)data_ov031_02290cfc + index * 0x100;
    VectorizedMemset(context, 0, 0xef);
    context[0xe7] = 0xff;
    func_ov031_02236570(index);
}
