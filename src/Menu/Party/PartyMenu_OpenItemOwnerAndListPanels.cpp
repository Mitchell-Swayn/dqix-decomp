struct PartyMenuState;
#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void PartyMenu_ReadCanvasBounds(PartyMenuState*,int,short*,short*,short*,short*);void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);void* memset(void*,int,unsigned);void Graphics_AppendPartyMemberListText(char*,char*,int);void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);void Window_BindNextCanvasResourceByFormatAndLayer(char*,unsigned,unsigned);void PartyMenu_OpenSelectedOwnerItemList(void*);void Window_SetCanvasDisplayAttribute(char*,int,int);void Window_SelectCanvasById(unsigned char*,unsigned);}
// Original: arm9/ov002 @0x0215c614; symbol:Graphics_RebuildPartyListCanvasAndSelectionMode; size:0x118.
// Rebuilds party list text canvas using expanded record bounds, binds matching pair and refreshes selected mode.
extern "C" void PartyMenu_OpenItemOwnerAndListPanels(unsigned char* self){short a=0,b=0,c=1,d=1;PartyMenu_ReadCanvasBounds((PartyMenuState*)((char*)self),3,(short*)(&a),(short*)(&b),(short*)(&c),(short*)(&d));b+=3;PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self),W(self,0x1bb8)&255,a,b);memset(P(self,0x1bd0),0,2400);Graphics_AppendPartyMemberListText((char*)self,(char*)P(self,0x1bd0),0);Window_PushTextCanvas(self+0xec8,P(self,0x1bd0),0,1,0,1,0,0);Window_BindNextCanvasResourceByFormatAndLayer((char*)self+0xec8,0,2);PartyMenu_OpenSelectedOwnerItemList(self);Window_SetCanvasDisplayAttribute((char*)self+0xec8,W(self,0x1bb8)&255,0);Window_SelectCanvasById(self+0xec8,W(self,0x1bb8)&255);}
