#include <globaldefs.h>
ARM
typedef void (*Ctor)(void*);extern "C" void _ZN23ZoneContainerRenderPartC1Ev(void*);extern "C" void _ZN23ZoneContainerRenderPartD1Ev(void*);extern "C" void func_0200ee94(void*,int,int,Ctor,Ctor);extern "C" void ResetSixteenEntriesAndTenRenderParts(void*);
// Original: arm9/main @ 0x0203A878; symbol: func_0203a878; size: 0x5C.
extern "C" void* ZoneContainer_ConstructTwoArraysOfFiveRenderParts(char* p){func_0200ee94(p,5,136,_ZN23ZoneContainerRenderPartC1Ev,_ZN23ZoneContainerRenderPartD1Ev);func_0200ee94(p+680,5,136,_ZN23ZoneContainerRenderPartC1Ev,_ZN23ZoneContainerRenderPartD1Ev);ResetSixteenEntriesAndTenRenderParts(p);return p;}
