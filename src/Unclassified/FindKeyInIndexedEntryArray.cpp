#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct E{signed char key:6;char pad[571];};
// Original: arm9/main @ 0x02086E50; symbol: func_02086e50; size: 0x4C.
E *FindKeyInIndexedEntryArray(char *p,int key){E *data=(E *)(p+0xf80);for(unsigned char i=0;i<*(unsigned char *)(p+0x2c8c);i++)if(data[i].key==key)return data+i;return 0;}
}
