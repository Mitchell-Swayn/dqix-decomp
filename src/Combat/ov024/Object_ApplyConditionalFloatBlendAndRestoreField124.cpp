#include <globaldefs.h>
extern "C" unsigned _fadd(unsigned, unsigned);
extern "C" int func_ov024_021fc498(void*);
extern "C" void func_ov024_021fb91c(void*);
// Original: arm9/ov024 @ 0x021FCB60; symbol: func_ov024_021fcb60; size: 0x68.
extern "C" void Object_ApplyConditionalFloatBlendAndRestoreField124(void* object) {
    unsigned* field = (unsigned*)((char*)object + 0x124);
    unsigned saved = *field;
    *field = 0x3f19999a;
    if (*(unsigned char*)((char*)object + 6) == 3) *field = 0x3f266666;
    int count = func_ov024_021fc498(*(void**)((char*)object + 8));
    if (!(count > 2 && *(int*)((char*)object + 0xc) > 2))
        *field = _fadd(*field, 0x3e4ccccd);
    func_ov024_021fb91c(object);
    *field = saved;
}
