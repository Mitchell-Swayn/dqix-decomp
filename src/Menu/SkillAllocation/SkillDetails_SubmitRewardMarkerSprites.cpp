#include <globaldefs.h>
ARM
extern "C" void Graphics_SubmitTransformedCellToOam(void*,void*);
// Original: arm9/ov013 @ 0x02187784; symbol: Graphics_SubmitTenValidCoordinateEntries; size: 0xa8.
extern "C" void SkillDetails_SubmitRewardMarkerSprites(char* self) {
 if(!*(void**)(self+72) || (*(unsigned char*)(self+105)&1) || *(signed char*)(self+106)<0)return;
 char* entry=*(char**)(self+76)+*(signed char*)(self+106)*40;
 for(int i=0;i<10;i++){int x=(*(short**)(self+80))[i];int y;if(x>=0 && (y=(*(short**)(self+84))[i])>=0){*(int*)(entry+20)=x<<12;*(int*)(entry+24)=y<<12;entry[34]=i+32;entry[38]=0;entry[37]=(*(unsigned char**)(self+88))[i];Graphics_SubmitTransformedCellToOam(*(void**)(self+72),entry);}}
}
