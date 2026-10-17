#include <globaldefs.h>
extern "C" {
void ClearHalfwords0And8AndBytes5Through7(void *);void _ZN23ZoneContainerRenderPart5ResetEv(void *);
// Original: arm9/main @ 0x02039E7C; symbol: func_02039e7c; size: 0x6C.
void ResetSixteenEntriesAndTenRenderParts(char *p){for(int i=0;i<16;i++)ClearHalfwords0And8AndBytes5Through7(p+0x550+i*24);for(int i=0;i<5;i++){_ZN23ZoneContainerRenderPart5ResetEv(p+i*136);_ZN23ZoneContainerRenderPart5ResetEv(p+0x2a8+i*136);}*(int *)(p+0x6d0)=0;*(int *)(p+0x6d4)=0;}
}
