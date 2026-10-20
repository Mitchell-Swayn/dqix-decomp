#include <globaldefs.h>
ARM
extern "C" void _ZN23ZoneContainerRenderPart12ResetIfFlag0Ev(void*);
// Original: arm9/main @ 0x0203A54C; symbol: func_0203a54c; size: 0x3C.
extern "C" void ZoneContainer_ResetTwoArraysOfFiveRenderParts(unsigned char* p) { for(int i=0;i<5;++i) { unsigned int off=i*0x88;_ZN23ZoneContainerRenderPart12ResetIfFlag0Ev(p+off);_ZN23ZoneContainerRenderPart12ResetIfFlag0Ev(p+0x2a8+off); } }
