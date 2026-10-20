struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" void Graphics_SubmitTransformedCellToOam(void*,void*);
// Original: arm9/ov023 @ 0x021E6B04; symbol: SubmitMode14IndexedFixedPosition; size: 0x88.
// Copies signed coordinates to the selected forty-byte entry and submits it in mode14.
extern "C" void SubmitMode14IndexedFixedPosition(char* self) {
if(*(unsigned char*)(self+0x1371)!=14)return;
if(*(unsigned char*)(self+0x1370)>=10)return;
if(!(void*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self+0xac),14))return;
char* input=**(char***)(self);if(!input)return;
char* entry=*(char**)(self+0x1364)+(*(unsigned char*)(input+14)+15)*40;
int x=*(short*)input;int y=*(short*)(input+2);
*(int*)(entry+0x14)=x<<12;*(int*)(entry+0x18)=y<<12;entry[0x26]=0;
Graphics_SubmitTransformedCellToOam(*(void**)(self+0x135c),entry);
}
