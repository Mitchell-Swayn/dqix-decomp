#include <globaldefs.h>
ARM
struct ScriptParameter;
extern "C" char *_ZN13SafeAllocator8AllocateEj(void *allocator, unsigned int size);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const ScriptParameter *parameter);
extern "C" void Overlay_EnqueueLinkedNode(void *record);
extern "C" unsigned char data_ov000_02184264[];
// Original: arm9/ov000 @ 0x0216BA14; symbol: func_ov000_0216ba14; size: 0x54.
extern "C" int Resource_AllocateScriptType44Entry(const ScriptParameter *parameter) {
    void *allocator = *(void **)(data_ov000_02184264 + 8);
    unsigned char *record = (unsigned char *)_ZN13SafeAllocator8AllocateEj(allocator, 0xC);
    if (record == 0) {
        return 0;
    }
    *(unsigned int *)record = 0;
    *(unsigned int *)(record + 4) = 0;
    *(unsigned int *)record = 0x44;
    *(int *)(record + 8) = _ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(record);
    return 1;
}
