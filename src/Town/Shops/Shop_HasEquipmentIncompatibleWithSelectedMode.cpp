#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define I(p,o) (*(int*)((p)+(o)))
#define U(p,o) (*(unsigned*)((p)+(o)))
#define H(p,o) (*(unsigned short*)((p)+(o)))
#define S(p,o) (*(short*)((p)+(o)))
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define C(p,o) (*(signed char*)((p)+(o)))
#define V(p,o) (*(char**)((p)+(o)))
// Original data: arm9/ov003 @ 0x217fb60; symbol: data_ov003_0217fb60.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 08090700050106ff.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" char* GameState_GetObjectWithFlag100(void*,int);extern "C" unsigned char ShopHasEquipmentIncompatibleWithSelectedMode_UnknownRoleInitializedBytes[];struct Selector{unsigned char bit:1;unsigned char rest:7;};struct FourBits{unsigned low:4;unsigned high:28;};struct EquipmentBits{unsigned low:27;unsigned first:1;unsigned second:1;unsigned locked:1;unsigned high:2;};
// Original: arm9/ov003 @ 0x0217839C; symbol: GameState_TestEquippedRecordLacksSelectedModeFlag; size: 0x120.
extern "C" int Shop_HasEquipmentIncompatibleWithSelectedMode(int index,char* action){
if(((FourBits*)(action+8))->low!=7)return 0;char* object=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),index);if(!object)return 0;unsigned char i;char* data=V(object,0x150);char* special=data+0x2d4;if(!special)return 0;if(S(special,24)!=0x4680)return 0;unsigned char flags[2];for(i=0;i<8;++i){unsigned key=ShopHasEquipmentIncompatibleWithSelectedMode_UnknownRoleInitializedBytes[i];if(key==255)break;char* entry=data+0x194+key*32;if(entry&&S(entry,24)>=0){char* descriptor=V(entry,0);if(descriptor&&!((EquipmentBits*)(descriptor+4))->locked){flags[0]=((EquipmentBits*)(descriptor+4))->first!=0;flags[1]=((EquipmentBits*)(descriptor+4))->second!=0;if(!flags[((Selector*)(data+0x49c))->bit])return 1;}}}return 0;
}
