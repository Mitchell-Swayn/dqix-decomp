#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020B291C; symbol: func_020b291c; size: 0xDC.
extern "C" void RelocateFontResourceBlockPointers(char* base){
 unsigned* block=(unsigned*)(base+*(unsigned short*)(base+12));int i=0;if((int)*(volatile unsigned short*)(base+14)<=0)return;
 do{switch(*block){case 0x46494e46:block[4]+=(unsigned)base;if(block[5])block[5]+=(unsigned)base;if(block[6])block[6]+=(unsigned)base;break;case 0x43574448:if(block[3])block[3]+=(unsigned)base;break;case 0x434d4150:if(block[4])block[4]+=(unsigned)base;break;case 0x43474c50:break;}++i;block=(unsigned*)((char*)block+block[1]);}while(i<*(unsigned short*)(base+14));
}
