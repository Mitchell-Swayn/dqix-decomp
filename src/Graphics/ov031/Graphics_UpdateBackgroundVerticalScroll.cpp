#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int FastIntDivide(int,int);
extern "C" int FastIntModulus(int,int);
struct ScrollState {int unknown;unsigned short position;unsigned short pad;unsigned char* dirty;};
extern "C" ScrollState data_ov031_02290ca0;
extern "C" volatile unsigned char data_ov031_02249048[];
// Original: arm9/ov031 @ 0x02230778; symbol: func_ov031_02230778; size: 0x84.
extern "C" void Graphics_UpdateBackgroundVerticalScroll(){
 if(!data_ov031_02290ca0.dirty[0x44])return;
 int index=FastIntDivide(data_ov031_02290ca0.position,29);
 int scroll=FastIntModulus(data_ov031_02290ca0.position,29)-51;
 int amount=data_ov031_02249048[index];
 *(unsigned int*)0x04000010=(scroll<<16)&0x1ff0000;
 *(unsigned int*)0x04000018=((scroll+amount)<<16)&0x1ff0000;
 data_ov031_02290ca0.dirty[0x44]=0;
}
