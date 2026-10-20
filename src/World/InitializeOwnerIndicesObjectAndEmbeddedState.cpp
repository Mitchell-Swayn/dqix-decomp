#include <globaldefs.h>
ARM
#include <World/Object3D.h>
extern "C" void InitializeSignedAllocatorLists(void*);
// Original: arm9/main @ 0x020553AC; symbol: func_020553ac; size: 0x40.
extern "C" void InitializeOwnerIndicesObjectAndEmbeddedState(int* p){p[0]=-1;p[0x7b]=0;p[1]=0;p[2]=0;p[3]=0;p[4]=0;p[0x7a]=0;((Object3D*)(p+5))->Initialize();InitializeSignedAllocatorLists(p+0x30);}
