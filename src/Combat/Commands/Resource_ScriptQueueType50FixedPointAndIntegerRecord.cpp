#include <globaldefs.h>
ARM
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" unsigned int _ZNK6Script9Parameter7ToFloatEv(void *);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(unsigned int);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov000 @ 0x0216BD9C; symbol: Resource_ScriptQueueType50FixedPointAndIntegerRecord; size: 0x64.
// Allocates a type-0x50 record, scales the script float by 4096 into a halfword, stores the next integer halfword, and dispatches the record.
extern "C" int Resource_ScriptQueueType50FixedPointAndIntegerRecord(void *parameter) {
    char *entry = _ZN13SafeAllocator8AllocateEj(*(unsigned int *)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8), 0xc);
    *(unsigned int *)entry = 0x50;
    unsigned int floatBits = _ZNK6Script9Parameter7ToFloatEv(parameter);
    *(unsigned short *)(entry + 0xa) = (unsigned short)_ffix(_fmul(0x45800000, floatBits));
    *(unsigned short *)(entry + 8) = (unsigned short)_ZNK6Script9Parameter5ToIntEv((char *)parameter + 8);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
