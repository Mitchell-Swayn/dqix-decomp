#include <globaldefs.h>
ARM
extern "C" int GameState_CheckConnectionIndexListStatus(...);
extern "C" int GameState_GetSerializedProgressState(...);
extern "C" int BitArray_ReadNonnegativeIndexMask(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov002 @ 0x216c9ae; symbol: data_ov002_0216c9ae.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffffffffffffffffffffffffffff.
// Observed span: 18 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" char PartyMenuBuildAvailableConnectionActions_UnknownRoleInitializedBytes[];
// Original data: arm9/ov002 @ 0x216cd74; symbol: data_ov002_0216cd74.
// Menu state update handlers; func_ov002_02155960 supplies adjusted menu object in r0. ARM member-function dispatch ABI: adjustmentAndVirtual >> 1 is the this adjustment; bit 0 selects a virtual-table offset. All entries here are direct and have zero adjustment. Function return values are unused.
// Initial values: hex 4c62150200000000ec221602000000007c2516020000000014271602000000006429160200000000502e160200000000e8311602000000006436160200000000 ...; full span in module reference.
// Observed span: 352 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" char PartyMenuUpdateController_MenuStateUpdateHandlers[];
// Original data: arm9/ov002 @ 0x216cfac; symbol: data_ov002_0216cfac.
// Menu state content builders; func_ov002_0215b9a4 supplies adjusted menu object, output buffer, and alternate-mode flag in r0/r1/r2. ARM member-function dispatch ABI: adjustmentAndVirtual >> 1 is the this adjustment; bit 0 selects a virtual-table offset. All entries here are direct and have zero adjustment. Function return values are unused.
// Initial values: hex 000000000000000078c115020000000048c31502000000002cc51502000000002cc715020000000088c915020000000098cd150200000000e8d0150200000000 ...; full span in module reference.
// Observed span: 352 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" char PartyMenuRebuildPanelTextById_MenuStateContentBuilders[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov002 @ 0x02156080; symbol: BuildAvailableConnectionActionIndices.
extern "C" void PartyMenu_BuildAvailableConnectionActions(char*self,short*output,short*count){
char*global=C(GameState_GetSerializedProgressState());int status=GameState_CheckConnectionIndexListStatus(self);struct Nine{short ids[9];};Nine list=*(Nine*)PartyMenuBuildAvailableConnectionActions_UnknownRoleInitializedBytes;short used=0;for(short i=0;i<9;i++){int enabled=1;switch(i){case 2:enabled=BitArray_ReadNonnegativeIndexMask(global,global+140,0x119c)?1:0;break;case 6:enabled=0;break;case 8:if(status!=2)enabled=0;break;}if(!enabled)continue;list.ids[used]=i;used++;}memcpy(output,list.ids,18);*count=used;
}
