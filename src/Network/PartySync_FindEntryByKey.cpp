#include <globaldefs.h>
extern "C" {
struct E{unsigned short key;char pad[10];};
// Original: arm9/main @ 0x0207D9BC; symbol: func_0207d9bc; size: 0x38.
E *PartySync_FindEntryByKey(E *p,unsigned int key){for(int i=0;i<4;i++)if(p[i].key==key)return p+i;return 0;}
}
