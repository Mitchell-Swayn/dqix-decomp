struct PartyMenuState;
#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void* memset(void*,int,unsigned);extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);extern "C" void PartyMenu_ReadCanvasBounds(PartyMenuState*,int,short*,short*,short*,short*);extern "C" void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);extern "C" void Text_AppendCursorPageHeaderAndFourIndexedFragments(void*,char*,int);
// Original: arm9/ov002 @ 0x0215CCC4; symbol: BuildTypeFourCursorPageAndBindText; size: 0xD4.
extern "C" void PartyMenu_OpenItemCommandPanel(char* self){short a=0,b=0,c=1,d=1;PartyMenu_ReadCanvasBounds((PartyMenuState*)(self),4,(short*)(&a),(short*)(&b),(short*)(&c),(short*)(&d));a+=1;b+=8;PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self),(unsigned char)W(self,0x1bb8),a,b);memset(P(self,0x1bd0),0,0x960);Text_AppendCursorPageHeaderAndFourIndexedFragments(self,P(self,0x1bd0),0);Window_PushTextCanvas(self+0xec8,P(self,0x1bd0),0,1,0,1,0,0);}
