#include <globaldefs.h>
ARM
extern "C" unsigned data_ov031_022496fc;
extern "C" unsigned data_02111304;
extern "C" int _Z18GetContextPriorityP16ProcessorContext(void*);
extern "C" void _Z21ChangeContextPriorityP16ProcessorContextj(void*, unsigned);
// Original: arm9/ov031 @ 0x02207CF0; symbol: func_ov031_02207cf0; size: 0x4C.
extern "C" int ProcessorContext_UpdatePriorityFromSharedValue(void) {
    unsigned requested = *(unsigned*)((char*)&data_ov031_022496fc + 4);
    if (requested >= 0x20) return -1;
    void* context = *(void**)((char*)&data_02111304 + 4);
    int previous = _Z18GetContextPriorityP16ProcessorContext(context);
    _Z21ChangeContextPriorityP16ProcessorContextj(context, *(unsigned*)((char*)&data_ov031_022496fc + 4));
    return previous;
}
