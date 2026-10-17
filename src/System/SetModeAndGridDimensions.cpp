// Reviewed original control flow and widths; initialization retains per-field writes.
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
#include <System/Graphics.h>
extern "C" void* memcpy(void*,const void*,unsigned int);extern "C" void* memset(void*,int,unsigned int);extern "C" unsigned int data_020ef74c[];struct Pair{unsigned int first:10;unsigned int second:10;unsigned int rest:12;};
// Original: arm9/main @ 0x02028D68; symbol: func_02028d68; size: 0x74.
extern "C" void SetModeAndGridDimensions(unsigned int mode){data_020ef74c[3]=mode;if(mode==0){data_020ef74c[1]=8;data_020ef74c[2]=8;return;}if(mode-1<=1){data_020ef74c[2]=6;data_020ef74c[1]=12;return;}if(mode-3<=1){data_020ef74c[2]=5;data_020ef74c[1]=10;return;}if(mode-5<=1){data_020ef74c[2]=6;data_020ef74c[1]=12;}}
