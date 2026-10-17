#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" unsigned int data_ov004_0217018c[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned int, unsigned int);
extern "C" void func_ov011_02184a24(void *, unsigned int, unsigned int);
struct TemplateBlob { unsigned int words[54]; };
// Original: arm9/ov004 @ 0x0216E9CC; symbol: func_ov004_0216e9cc; size: 0x6C.
extern "C" void AllocateAndConfigureTemplateBlob(unsigned int allocator, void *state) {
    struct TemplateBlob local = *(struct TemplateBlob *)data_ov004_0217018c;
    void *copy = _ZN13SafeAllocator8AllocateEj(allocator, 0xd8);
    memcpy(copy, &local, 0xd8);
    func_ov011_02184a24(state, (unsigned int)copy, 0x36);
}
