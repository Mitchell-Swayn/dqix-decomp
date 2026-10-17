#include <globaldefs.h>
ARM
extern "C" void DecodePackedGlobalIdentifierFields(unsigned int *);
extern "C" void func_ov031_02217604(void *, unsigned int *);
// Original: arm9/ov031 @ 0x022175DC; symbol: func_ov031_022175dc; size: 0x28.
extern "C" void System_ProcessDecodedGlobalIdentifierForObject(void *object) {
    unsigned int fields[5];
    DecodePackedGlobalIdentifierFields(fields);
    func_ov031_02217604(object, fields);
}
