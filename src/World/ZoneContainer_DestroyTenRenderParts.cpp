#include <globaldefs.h>
extern "C" void ZoneContainer_ResetTwoArraysOfFiveRenderParts(void*);
extern "C" void _ZN23ZoneContainerRenderPartD1Ev(void*);
extern "C" void __cxa_vec_cleanup(void*,unsigned,unsigned,void(*)(void*));
// Original: arm9/main @ 0x0203A8D4; symbol: func_0203a8d4; size: 0x40.
extern "C" void* ZoneContainer_DestroyTenRenderParts(char* p) {ZoneContainer_ResetTwoArraysOfFiveRenderParts(p);__cxa_vec_cleanup(p+0x2a8,5,0x88,_ZN23ZoneContainerRenderPartD1Ev);__cxa_vec_cleanup(p,5,0x88,_ZN23ZoneContainerRenderPartD1Ev);return p;}
