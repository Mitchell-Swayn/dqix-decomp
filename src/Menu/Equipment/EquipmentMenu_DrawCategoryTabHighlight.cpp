#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void Graphics_ClearScreenBuffer(void*,void*);extern "C" void Graphics_CopyIndexedScreenRectangle(void*,unsigned,unsigned,unsigned,short,short,short,short,unsigned short);extern "C" void Graphics_CleanConfiguredDestinationCache(void*,int);
// Original: arm9/ov005 @ 0x0215A720; symbol: DrawFlaggedSelectionIndexHighlight; size: 0xCC.
extern "C" void EquipmentMenu_DrawCategoryTabHighlight(char* self){if(W(self,0x3dcc)&0x100){Graphics_ClearScreenBuffer(self+0xea4,0);Graphics_CopyIndexedScreenRectangle(self+0xea4,0,0,0,16,0,16,22,0xffff);unsigned index=B(self,0x3dbc);Graphics_CopyIndexedScreenRectangle(self+0xea4,(unsigned char)(index+1),0,0,(short)(index*2+15),0,4,3,0xffff);Graphics_CleanConfiguredDestinationCache(self+0xea4,0);}}
