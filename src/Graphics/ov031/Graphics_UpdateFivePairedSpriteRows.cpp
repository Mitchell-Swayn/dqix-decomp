#include <globaldefs.h>
ARM
extern "C" int FastIntModulus(int,int);
struct Global {unsigned short pad,position;unsigned char* state;};
extern "C" Global data_ov031_02290c8c;
// Original: arm9/ov031 @ 0x0222C660; symbol: func_ov031_0222c660; size: 0xBC.
extern "C" void Graphics_UpdateFivePairedSpriteRows(){
 int y=54-FastIntModulus(data_ov031_02290c8c.position,28);
 int count=data_ov031_02290c8c.state[0x51];
 if(count>5)count=5;
 int i=0;
 if(count>0){do{
 unsigned* a=*(unsigned**)(data_ov031_02290c8c.state+0x10+i*4);
 *a=(*a&0xfe00ff00)|((y-2)&255)|0xb30000;
 unsigned* b=*(unsigned**)(data_ov031_02290c8c.state+0x24+i*4);
 *b=(*b&0xfe00ff00)|((y+1)&255)|0xd20000;
 i++;y+=28;
 }while(i<count);
 }
 data_ov031_02290c8c.state[0x56]=1;
}
