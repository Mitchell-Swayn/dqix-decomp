#include <globaldefs.h>
ARM
extern "C" void func_ov031_022157f8(void *, unsigned int *);
extern "C" void MD5_ComputeDigestSegment13(unsigned int *, int);
// Original: arm9/ov031 @ 0x02215750; symbol: func_ov031_02215750; size: 0x28.
extern "C" void System_DecodeAndApplyInputRecord(void *input, int selector) {
    unsigned int fields[6];
    func_ov031_022157f8(input, fields);
    MD5_ComputeDigestSegment13(fields, selector);
}
