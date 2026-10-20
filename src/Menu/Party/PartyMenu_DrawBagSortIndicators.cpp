struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" void Window_SetCanvasEnabled(unsigned char*,int,int);
struct Record;struct Owner;
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" bool TextCanvas_IsReady(int);
extern "C" void Graphics_PositionAndSubmitSpriteCell(int,int,void*,unsigned,unsigned char,unsigned char);

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov002 @ 0x0215B138; symbol: Graphics_UpdateTwoSelectedRecordEntriesFromScaledCoordinates; size: 0xFC.
extern "C" void PartyMenu_DrawBagSortIndicators(char* self){Window_SetCanvasEnabled((unsigned char*)self+0xec8,0,40);if((W(self,0x1bb8)==4||W(self,0x1bb8)==5)&&*(signed char*)(self+0x1c20)==4){char* record=(char*)(Record*)Window_FindActiveCanvasById((WindowCanvasOwner*)((Owner*)(self+0xec8)),40);if(record&&TextCanvas_IsReady((int)record)){short x=S(record,0xac),y=S(record,0xae);y*=8;x*=8;Graphics_PositionAndSubmitSpriteCell(x,y,P(self,0x1a68),38,85,255);Graphics_PositionAndSubmitSpriteCell(x,y,P(self,0x1a68),(unsigned short)(B(self,0x248d)+39),88,255);Window_SetCanvasEnabled((unsigned char*)self+0xec8,1,40);}}}