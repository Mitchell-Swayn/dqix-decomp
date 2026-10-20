#include <globaldefs.h>
struct Object {char pad[0xbd0];short* arrays[8];char pad2[0x20];short counts[8];unsigned char ids[8];};
// Original: arm9/main @ 0x0207CAA4; symbol: func_0207caa4; size: 0x94.
extern "C" ARM int Inventory_FindItemSlotInTypeGroup(Object* p,int item,unsigned id){if(item<0)return -2;int found=-1;for(int i=0;i<8;i++){if(p->ids[i]==id){found=i;break;}}if(found==-1)return -2;short* a=p->arrays[found];short count=p->counts[found];for(short i=0;i<count;i++)if(item==a[i])return i;return -1;}
