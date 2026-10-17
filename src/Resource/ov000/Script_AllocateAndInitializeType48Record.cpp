#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
extern "C" unsigned data_ov000_02184264[];
// Original: arm9/ov000 @ 0x0216BB70; symbol: func_ov000_0216bb70; size: 0x54.
extern "C" int Script_AllocateAndInitializeType48Record(const void* parameter) {
    char* record = _ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2], 0xc);
    if (record == 0) return 0;
    *(unsigned*)record = 0;
    *(unsigned*)(record + 4) = 0;
    *(unsigned*)record = 0x48;
    *(int*)(record + 8) = _ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(record);
    return 1;
}
