#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned int, unsigned int);
extern "C" void Overlay_EnqueueLinkedNode(void*);
extern "C" unsigned int data_ov000_02184264[];
// Original: arm9/ov000 @ 0x02169E54; symbol: func_ov000_02169e54; size: 0x2C.
extern "C" int Resource_AllocateAndInitializeLinkedCoordinateEntry(void) { char* p = _ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2], 8); *(unsigned int*)p = 4; Overlay_EnqueueLinkedNode(p); return 1; }
