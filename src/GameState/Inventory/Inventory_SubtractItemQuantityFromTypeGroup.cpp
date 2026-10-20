#include <globaldefs.h>
struct Object {char pad[0xbd0];short* ids[8];signed char* counts[8];char padc10[16];unsigned char keys[8];};
extern "C" int Inventory_FindItemSlotInTypeGroup(Object*,unsigned,unsigned);
// Original: arm9/main @ 0x0207C484; symbol: func_0207c484; size: 0x98.
extern "C" int Inventory_SubtractItemQuantityFromTypeGroup(Object* p,unsigned lookup,int amount,unsigned key) {if(amount<=0)return 0;int index=Inventory_FindItemSlotInTypeGroup(p,lookup,key);if(index<0)return 0;int found;for(int i=0;i<8;i++)if(p->keys[i]==key){found=i;break;}signed char* counts=p->counts[found];counts[index]-=amount;if(counts[index]<=0){p->ids[found][index]=-1;counts[index]=0;}return 1;}
