#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void Object_ConvertMappedKeyToTwoHalfwords(void*,int,short*,short*);extern "C" void Graphics_SubmitTransformedCellToOam(void*,void*);
// Original: arm9/ov023 @ 0x021E4264; symbol: Graphics_SubmitTwoMappedCursorPositions; size: 0xF4.
extern "C" void Graphics_SubmitTwoMappedCursorPositions(char* self){short x,y;char* record=P(self,0xcc);Object_ConvertMappedKeyToTwoHalfwords(self+0xd4,17,&x,&y);if(U(self,0x634)&0x100){x--;y++;}W(record,0x64)=x<<12;W(record,0x68)=y<<12;B(record,0x72)=127;B(record,0x76)=2;Graphics_SubmitTransformedCellToOam(P(self,0xc8),record+0x50);record=P(self,0xcc);Object_ConvertMappedKeyToTwoHalfwords(self+0xd4,18,&x,&y);if(U(self,0x634)&0x200){x++;y++;}W(record,0x8c)=x<<12;W(record,0x90)=y<<12;B(record,0x9a)=126;B(record,0x9e)=2;Graphics_SubmitTransformedCellToOam(P(self,0xc8),record+0x78);}
