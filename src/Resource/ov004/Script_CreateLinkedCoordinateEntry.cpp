#include <globaldefs.h>
ARM
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" void func_ov011_02184a24(void *, unsigned, unsigned);
extern "C" unsigned char data_ov004_02170360[];
// Original: arm9/ov004 @ 0x021560B0; symbol: func_ov004_021560b0; size: 0x38.
extern "C" void Script_CreateLinkedCoordinateEntry(unsigned allocatorArg, void *state) {
    char *entry = _ZN13SafeAllocator8AllocateEj(allocatorArg, 0x38);
    memcpy(entry, data_ov004_02170360, 0x38);
    func_ov011_02184a24(state, (unsigned)entry, 0xe);
}
