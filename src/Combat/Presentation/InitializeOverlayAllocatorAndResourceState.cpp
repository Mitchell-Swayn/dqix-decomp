#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef990; symbol: data_ov025_021ef990.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" {extern unsigned SceneCancelLoadsAndRestoreObjects_UnknownRoleZeroInitializedStorage;void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);void BattleText_ResetSelectiveStringLoader(void*);void Memory_InitializeRecordSentinel(void*);void Resource_InitializeOverlayRecordSet(void*);void Combat_ResetActionMessageQueue(char*);}
#define W(o) (*(unsigned*)(p+(o)))
#define H(o) (*(unsigned short*)(p+(o)))
#define B(o) (*(unsigned char*)(p+(o)))
// Original: arm9/ov025 @ 0x021E88D8; symbol: func_ov025_021e88d8; size: 0x148.
// Resets allocator pointer tables, embedded resource records and selection sentinels.
extern "C" void InitializeOverlayAllocatorAndResourceState(char* p) {
 W(0)=0;W(4)=0;SceneCancelLoadsAndRestoreObjects_UnknownRoleZeroInitializedStorage=0;
 for(int i=0;i<4;i++){((unsigned*)(p+0x10))[i]=0;((unsigned*)(p+0x20))[i]=0;}
 for(int i=0;i<3;i++){void* allocator=p+0x34+i*20;_ZN13SafeAllocator21ResetAllocatorPointerEv(allocator);((unsigned*)(p+0x10))[i+1]=(unsigned)allocator;((unsigned*)(p+0x20))[i+1]=(unsigned)(p+0x70+i*0x70);}
 B(0x30)=0;W(0x1d8)=0;H(0x21c)=1;H(0x21e)=0;W(0x224)=0;
 Resource_InitializeOverlayRecordSet(p+0x22c);
 Combat_ResetActionMessageQueue(p+0x5e8);
 BattleText_ResetSelectiveStringLoader(p+0x798);
 B(0x83c)=0;B(0x87c)=0;W(0x880)=-1;W(0x884)=0;
 H(0x57c)=0;H(0x57e)=0;H(0x580)=0x333;B(0x582)=0;
 char* record=p+0x594;for(unsigned char i=0;i<4;i++,record+=12)Memory_InitializeRecordSentinel(record);
 B(0x5c5)=0;B(0x5c6)=0;W(0xc)=0;W(0x228)=0;H(0x5c8)=255;H(0x5ce)=0;
}
