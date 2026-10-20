#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char *p);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" ARM void QuestMessagePanel_Initialize(unsigned char*,unsigned char);
extern "C" ARM void FieldDialogue_ResetPeerResponseTracking(void*);
// Original: arm9/ov017 @ 0x021B8D1C; symbol: func_ov017_021b8d1c; size: 0x64.
// Initializes type 5, two allocator fields, embedded graphics and state flags.
extern "C" void InitializeType5GraphicsRecord(unsigned char *p) {
 LinkedQueue_InitializeNodeStatus((signed char *)p);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+8);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x1c);
 QuestMessagePanel_Initialize(p+0x30,0);
 p[0]=5;
 *(int *)(p+0x11c)=0; *(int *)(p+0x124)=0; *(int *)(p+0x114)=0; *(int *)(p+0x118)=0;
 p[0x128]=0;p[0x129]=0;p[0x137]=0;p[0x138]=0;p[0x139]=0;
 FieldDialogue_ResetPeerResponseTracking(p);
}
