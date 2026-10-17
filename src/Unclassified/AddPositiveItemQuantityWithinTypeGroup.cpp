#include <globaldefs.h>
extern "C" int Object_FindItemIndexInMatchingIdGroup(void*,unsigned,unsigned);
struct Inventory {char pad[0xbd0];short* entries[8];signed char* quantities[8];short lengths[8];unsigned char types[8];};
// Original: arm9/main @ 0x0207C378; symbol: func_0207c378; size: 0x10C.
extern "C" ARM int AddPositiveItemQuantityWithinTypeGroup(Inventory* p,unsigned item,int amount,unsigned type){if(amount<=0)return 0;int index=Object_FindItemIndexInMatchingIdGroup(p,item,type);if(index==-2)return 0;int group=-1;for(int i=0;i<8;i++){if(type==p->types[i]){group=i;break;}}if(group<0)return 0;int result=0;signed char* counts=p->quantities[group];if(index>=0){result=1;counts[index]+=amount;if(counts[index]>99)counts[index]=99;}else {short* entries=p->entries[group];short length=p->lengths[group];for(short i=0;i<length;i++){if(entries[i]<0){entries[i]=item;counts[i]=amount;result=1;if(counts[i]>99)counts[i]=99;break;}}}return result;}
