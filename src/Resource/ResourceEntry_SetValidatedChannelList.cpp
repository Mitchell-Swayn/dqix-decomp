#include <globaldefs.h>
ARM
extern "C" int ReservePreviouslyUnusedMaskBits(unsigned);
// Original: arm9/main @ 0x020BC948; symbol: func_020bc948; size: 0x60.
extern "C" int ResourceEntry_SetValidatedChannelList(unsigned char* p,int count,const unsigned char* src){unsigned mask=0; int i=0;if(count>0)do {(p+i)[0x4c]=src[i];mask|=1u<<src[i];i++;}while(i<count); if(!ReservePreviouslyUnusedMaskBits(mask))return 0; *(int*)(p+0x48)=count;*(unsigned*)(p+0x44)=mask;return 1;}
