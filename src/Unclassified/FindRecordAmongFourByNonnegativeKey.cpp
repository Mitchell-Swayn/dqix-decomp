#include <globaldefs.h>
extern "C" {
struct E {unsigned short key;char pad[790];};
// Original: arm9/main @ 0x02028BD0; symbol: func_02028bd0; size: 0x44.
E *FindRecordAmongFourByNonnegativeKey(E *p,int key){if(key<0)return 0;for(int i=0;i<4;i++)if(p[i].key==key)return p+i;return 0;}
}
