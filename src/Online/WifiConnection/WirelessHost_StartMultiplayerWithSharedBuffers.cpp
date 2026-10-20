#include <globaldefs.h>
ARM
struct Global { void* unused; char* object; };
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Global WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage;
extern "C" void WirelessHost_HandleMultiplayerEvent();
extern "C" int WM_StartMP(int,int,int,int,unsigned short,unsigned short);
extern "C" void WirelessHost_SetSystemState(int);
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned);
// Original: arm9/ov031 @ 0x02239724; symbol: func_ov031_02239724; size: 0x98.
extern "C" int WirelessHost_StartMultiplayerWithSharedBuffers() {
 char* self=WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage.object;
 if((unsigned)(*(unsigned*)(self+0x40)-4)<=2) return 1;
 WirelessHost_SetSystemState(4);
 self=WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage.object;
 int result=WM_StartMP((int)WirelessHost_HandleMultiplayerEvent,(int)(self+0x1060),(unsigned short)*(unsigned*)(self+0x12a4),(int)(self+0xf80),(unsigned short)*(unsigned*)(self+0x12a0),1);
 if(result==2) return 1;
 WirelessHost_StoreErrorUnlessTerminal(result);
 return 0;
}
