#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" signed char data_020e8b91[];extern "C" signed char data_020e8b90[];
// Original: arm9/main @ 0x02085474; symbol: func_02085474; size: 0x74.
extern "C" int TestSelectedEntryField2F4Bit18(unsigned char* p){int count=0;for(int i=0;data_020e8b90[i*2]!=-1;i++){int index=data_020e8b90[i*2];int check=data_020e8b91[i*2];if(*(short*)(p+check*32+0x1ac)>0&&((*(unsigned*)(p+index*44+0x2f4)<<13)>>31)){return 1;}}return count;}
