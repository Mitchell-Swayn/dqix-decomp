struct WindowCanvasOwner;
struct WindowCanvasRecord;
struct PartyMenuState;
#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);void* memset(void*,int,unsigned);void Text_AppendTwoIndexedFragmentsWithSeparator(char*,char*,int);void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);void PartyMenu_ReadCanvasBounds(PartyMenuState*,int,short*,short*,short*,short*);void Window_RefreshSelectionGeometry(unsigned char*);}
// Original: arm9/ov002 @0x02160fb4; symbol:Graphics_RebuildSelectedRecordTextAndCenteredBounds; size:0x110.
// Rebuilds selected record text and centers its bounds within32-by15 area before geometry refresh.
#pragma always_inline on
inline void SetXY(unsigned char* p,short x,short y){H(p,0xac)=x;H(p,0xae)=y;}
inline void SetSize(unsigned char* p,short x,short y){H(p,0xa8)=x;H(p,0xaa)=y;}
extern "C" void PartyMenu_BuildActionConfirmationText(unsigned char* self){PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self),W(self,0x1bb8)&255,1,1);memset(P(self,0x1bd0),0,2400);Text_AppendTwoIndexedFragmentsWithSeparator((char*)self,(char*)P(self,0x1bd0),0);Window_PushTextCanvas(self+0xec8,P(self,0x1bd0),0,1,0,1,0,0);unsigned char* record=(unsigned char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self+0xec8),W(self,0x1bb8)&255);if(record){short a,b,c,d;PartyMenu_ReadCanvasBounds((PartyMenuState*)((char*)self),W(self,0x1bb8)&255,(short*)(&a),(short*)(&b),(short*)(&c),(short*)(&d));a=32-c;b=15-d;SetXY(record,a,b);SetSize(record,c,d);Window_RefreshSelectionGeometry(self+0xec8);}}
