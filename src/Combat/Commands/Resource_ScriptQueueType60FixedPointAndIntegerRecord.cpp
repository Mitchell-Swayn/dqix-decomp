#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" unsigned int _fmul(unsigned int, float);
extern "C" int _ffix(unsigned int);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned int CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov000 @ 0x0216C314; symbol: Resource_ScriptQueueType60FixedPointAndIntegerRecord; size: 0x70.
// Allocates a type-0x60 record, scales the script float by 4096 into a halfword, stores the next integer halfword, and dispatches the record.
extern "C" int Resource_ScriptQueueType60FixedPointAndIntegerRecord(void* param) {
    char* record = _ZN13SafeAllocator8AllocateEj(*((unsigned int*)((char*)&CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8)), 0xC);
    *(unsigned int*)record = 0;
    *(unsigned int*)(record + 4) = 0;
    *(unsigned int*)record = 0x60;
    float value = _ZNK6Script9Parameter7ToFloatEv(param);
    unsigned int scaled = _fmul(0x45800000, value);
    *(short*)(record + 8) = (short)_ffix(scaled);
    *(short*)(record + 0xA) = (short)_ZNK6Script9Parameter5ToIntEv((char*)param + 8);
    Overlay_EnqueueLinkedNode(record);
    return 1;
}
