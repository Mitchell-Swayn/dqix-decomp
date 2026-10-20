#include <globaldefs.h>
ARM
typedef void (*Ctor)(void*);extern "C" void _ZN23ZoneContainerRenderPartC1Ev(void*);extern "C" void _ZN23ZoneContainerRenderPartD1Ev(void*);extern "C" void RuntimeArrays_ConstructElementsWithRollback(void*,int,int,Ctor,Ctor);extern "C" void FloatingNumber_ResetDisplay(void*);
// Original: arm9/main @ 0x0203A878; symbol: func_0203a878; size: 0x5C.
extern "C" void* ZoneContainer_ConstructTwoArraysOfFiveRenderParts(char* p){RuntimeArrays_ConstructElementsWithRollback(p,5,136,_ZN23ZoneContainerRenderPartC1Ev,_ZN23ZoneContainerRenderPartD1Ev);RuntimeArrays_ConstructElementsWithRollback(p+680,5,136,_ZN23ZoneContainerRenderPartC1Ev,_ZN23ZoneContainerRenderPartD1Ev);FloatingNumber_ResetDisplay(p);return p;}
