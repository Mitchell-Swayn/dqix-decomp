#include <globaldefs.h>
extern "C" { void Graphics_WriteFourHorizontalObjectAttributes(void*,void*,int,int,int,int);
// Original: arm9/main @ 0x0203C4D0; symbol: func_0203c4d0; size: 0x7C.
 ARM void PopulateIndexedRecordAndAdvancePaletteSlot(unsigned char* self,int index,int a,int b,int c,unsigned int palette) { if(index<0 || !*(void**)self)return; unsigned int flags=*(volatile unsigned int*)(self+1292);unsigned int color=palette;color+=flags>>5;Graphics_WriteFourHorizontalObjectAttributes(self+4+(short)index*40,(unsigned char*)*(void**)self+*(unsigned short*)(self+1296)*8,a,b,c,color&15); *(volatile unsigned short*)(self+1296)+=4; *(volatile unsigned short*)(self+1296)&=127; } }
