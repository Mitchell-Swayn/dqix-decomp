#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" unsigned _ZNK6Script9Parameter7ToFloatEv(const void*);
extern "C" unsigned _fmul(unsigned, unsigned);
extern "C" unsigned _fdiv(unsigned, unsigned);
extern "C" unsigned _fflt(int);
extern "C" int _ffix(unsigned);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original: arm9/ov000 @ 0x0216A9DC; symbol: Script_AllocateTaggedFixedPointEntry; size: 0xF8.
// Allocates a type-0x1A node and stores parameter-derived tag and fixed-point value fields.
extern "C" int Script_AllocateTaggedFixedPointEntry(const void* parameter, int count) {
    char* entry = _ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2], 12);
    *(unsigned*)entry = 0;
    *(unsigned*)(entry + 4) = 0;
    *(unsigned*)entry = 0x1A;
    int index = 1;
    if (*(unsigned*)parameter == 2) {
        entry[8] = 7;
        *(unsigned short*)(entry + 10) = 0x1000;
    } else if (*(unsigned*)parameter == 1) {
        entry[8] = (char)_ZNK6Script9Parameter5ToIntEv(parameter);
        *(unsigned short*)(entry + 10) = 0x1000;
        parameter = (const char*)parameter + 8;
        index = 2;
    }
    if (index <= count) {
        unsigned kind = *(const unsigned*)parameter;
        if (kind == 2) {
            unsigned bits = _ZNK6Script9Parameter7ToFloatEv(parameter);
            *(unsigned short*)(entry + 10) = (unsigned short)_ffix(_fmul(0x45800000, bits));
        } else if (kind == 1) {
            int value = _ZNK6Script9Parameter5ToIntEv(parameter);
            unsigned scaled = _fdiv(_fflt(value), 0x447A0000);
            *(unsigned short*)(entry + 10) = (unsigned short)_ffix(_fmul(0x45800000, scaled));
        }
    }
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
