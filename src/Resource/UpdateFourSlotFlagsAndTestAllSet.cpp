#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* Object_GetGlobalConnectionState();extern "C" int TestResolvedBitInByteField100C(void*,int);extern "C" void* GameState_FindIndexedObjectWithFlag1000(void*,int);extern "C" void Object_SetBitAndOptionalPairedBitAtOffset17E(void*,int,int);
// Original: arm9/main @ 0x0207973C; symbol: func_0207973c; size: 0x80.
extern "C" int UpdateFourSlotFlagsAndTestAllSet(unsigned char* p){void* state=_ZN9GameState11GetInstanceEv();void* list=Object_GetGlobalConnectionState();for(int i=0;i<4;i++)if(!TestResolvedBitInByteField100C(list,i)||GameState_FindIndexedObjectWithFlag1000(state,i))Object_SetBitAndOptionalPairedBitAtOffset17E(p,i,1);return (p[382]&15)==15;}
