#include <globaldefs.h>
ARM
extern "C" void Object_ConvertMappedKeyToTwoHalfwords(void*,int,short*,short*);
extern "C" void Graphics_SubmitTransformedCellToOam(void*,void*);
// Original: arm9/ov023 @ 0x021E43F0; symbol: Graphics_SetMappedRecordCoordinatesAndSubmit; size: 0x8c.
// Maps key 1B to signed coordinates, applies one-shot increment flag, submits record in fixed point.
extern "C" void Menu_DrawPartyPreviewCloseButton(char* self) {
 short x,y;char* record=*(char**)(self+0xcc);
 Object_ConvertMappedKeyToTwoHalfwords(self+0xd4,0x1b,&x,&y);
 if(*(unsigned short*)(self+0x634)&0x800){++x;++y;*(unsigned short*)(self+0x634)&=~0x800;}
 *(int*)(record+0x3c)=x<<12;*(int*)(record+0x40)=y<<12;record[0x4a]=0x79;record[0x4e]=2;
 Graphics_SubmitTransformedCellToOam(*(void**)(self+0xc8),record+0x28);
}
