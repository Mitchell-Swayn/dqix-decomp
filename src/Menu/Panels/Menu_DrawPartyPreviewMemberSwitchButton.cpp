#include <globaldefs.h>
ARM
extern "C" void Graphics_SubmitTransformedCellToOam(void*,void*);
extern "C" void Object_ConvertMappedKeyToTwoHalfwords(void*,int,short*,short*);
// Original: arm9/ov023 @ 0x021E4358; symbol: Graphics_SubmitMappedPositionWithOneShotOffset; size: 0x98.
extern "C" void Menu_DrawPartyPreviewMemberSwitchButton(char* self) {
 if(*(int*)(self+0x4e8)==1)return;short x,y;char* output=*(char**)(self+0xcc);Object_ConvertMappedKeyToTwoHalfwords(self+0xd4,32,&x,&y);
 if(*(unsigned short*)(self+0x634)&1024){x++;y++;*(unsigned short*)(self+0x634)&=~1024;}
 *(int*)(output+20)=x<<12;*(int*)(output+24)=y<<12;output[34]=123;output[38]=2;Graphics_SubmitTransformedCellToOam(*(void**)(self+0xc8),output);
}
