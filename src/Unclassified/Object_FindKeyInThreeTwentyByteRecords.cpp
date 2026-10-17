#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02087574; symbol: func_02087574; size: 0x50.
char *Object_FindKeyInThreeTwentyByteRecords(char *p,int key){if(key>=0)for(int i=0;i<3;i++)if(*(signed char *)(p+i*20+0xf3c)==key)return p+0xf2c+i*20;return 0;}
}
