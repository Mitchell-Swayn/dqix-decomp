#include <globaldefs.h>
ARM
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void**, unsigned short);
extern "C" void func_ov023_021f98e0(void*, void*);
extern "C" unsigned short data_ov004_02171034;
// Original: arm9/ov004 @ 0x0216E984; symbol: func_ov004_0216e984; size: 0x48.
extern "C" int Resource_MarkFoundNodeAndApplyContext(void* context) {
    void* head = func_ov011_021849c8(context);
    if (head != 0) {
        void* node = func_ov023_021f6880((void**)head, *(unsigned short*)((char*)&data_ov004_02171034 + 0xa));
        if (node != 0) {
            *(unsigned char*)((char*)node + 0xc) |= 0x10;
            func_ov023_021f98e0(node, context);
        }
    }
    return 0;
}
