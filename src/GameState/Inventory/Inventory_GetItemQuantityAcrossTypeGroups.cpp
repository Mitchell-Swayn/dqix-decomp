#include <globaldefs.h>
ARM
struct State {char pad[0xbd0];const short* keys[8];const signed char* values[8];char padc10[16];unsigned char types[8];};
// Original data: arm9/main @ 0x20e8a14; symbol: data_020e8a14.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 10013000c00060009000500070004000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const short InventoryGetItemQuantityAcrossTypeGroups_UnknownRoleInitializedBytes[8];
// Original: arm9/main @ 0x0207C7A0; symbol: func_0207c7a0; size: 0xF4.
extern "C" int Inventory_GetItemQuantityAcrossTypeGroups(const State* s,int key,unsigned type){
 if(key<0)return 0;int selected=-1;
 for(int i=0;i<8;++i)if(type==(reinterpret_cast<const unsigned char*>(s)+i)[0xc20]){selected=i;break;}
 if(selected<0){for(int i=0;i<8;++i){int count=InventoryGetItemQuantityAcrossTypeGroups_UnknownRoleInitializedBytes[i];const short* keys=s->keys[i];for(int j=0;j<count;++j)if(key==keys[j])return s->values[i][j];}}
 else {int count=InventoryGetItemQuantityAcrossTypeGroups_UnknownRoleInitializedBytes[selected];const short* keys=s->keys[selected];for(int j=0;j<count;++j)if(key==keys[j])return s->values[selected][j];}
 return 0;
}
