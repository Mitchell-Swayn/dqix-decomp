#include <globaldefs.h>
ARM
extern "C" void DisplayLayout_AdvanceActiveCanvases(unsigned char*,unsigned);
// Original: arm9/ov003 @ 0x02167494; symbol: func_ov003_02167494; size: 0xB4.
extern "C" void Graphics_AdvanceSubBackgroundScroll(char* self,int step) {
if(!*(unsigned char*)(self+0x74) || !*(void**)(self+0x10)) return;
if(step==0) step=1;
DisplayLayout_AdvanceActiveCanvases(*(unsigned char**)(self+0x10),step);
*(volatile unsigned*)0x04001010=0;
*(int*)(self+0x68)-=step<<11;
*(int*)(self+0x6c)+=step<<11;
if(*(int*)(self+0x68)<-0x100000) *(int*)(self+0x68)+=0x100000;
if(*(int*)(self+0x6c)>0x100000) *(int*)(self+0x6c)-=0x100000;
*(volatile unsigned*)0x04001014=((*(int*)(self+0x68)>>12)&0x1ff)|(((*(int*)(self+0x6c)>>12)<<16)&0x1ff0000);
}
