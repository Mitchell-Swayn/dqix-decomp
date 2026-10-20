#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" void Graphics_SubmitTransformedCellToOam(void*,void*);
// Original: arm9/ov023 @ 0x021dd404; symbol: SubmitScreenModeFromInputFlags.
extern "C" void ItemDetail_DrawQuantityModeIcon(char* p){if(S(p,0x77b)==1){if((((unsigned)B(p,0x79b)<<30)>>31)==0)return;if(!(H(p,0x774)&0x2000))return;}int mode=S(p,0x77d);if(mode==1){if(!(H(p,0x774)&0x800))return;char* q=p+0x608;B(q,0x26)=1;U(q,0x14)=0x10000;U(q,0x18)=0x68000;B(q,0x22)=0x58;Graphics_SubmitTransformedCellToOam(p+0x12c,q);return;}if(mode==2){if(!(H(p,0x774)&0x800))return;char* q=p+0x608;B(q,0x26)=2;U(q,0x14)=0x10000;U(q,0x18)=0x68000;B(q,0x22)=0x58;Graphics_SubmitTransformedCellToOam(p+0x12c,q);}}
