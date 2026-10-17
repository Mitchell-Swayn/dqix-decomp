#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov000_02184264[];
extern "C" unsigned char *_ZN13SafeAllocator8AllocateEj(void *, unsigned);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void *);
extern "C" float _fmul(float, float);
extern "C" int _ffix(float);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x02169FA4; symbol: func_ov000_02169fa4; size: 0x74.
extern "C" int Script_AllocateTypeSixEntryFromFloats(void *script) {
    unsigned char *entry = _ZN13SafeAllocator8AllocateEj(*(void **)(data_ov000_02184264 + 8), 12);
    *(unsigned int *)entry = 6;
    *(unsigned short *)(entry + 8) = (unsigned short)_ffix(_fmul(4096.0f, _ZNK6Script9Parameter7ToFloatEv(script)));
    *(unsigned short *)(entry + 10) = (unsigned short)_ffix(_fmul(4096.0f, _ZNK6Script9Parameter7ToFloatEv((unsigned char *)script + 8)));
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
