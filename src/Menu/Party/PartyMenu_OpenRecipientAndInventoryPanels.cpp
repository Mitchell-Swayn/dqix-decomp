struct PartyMenuState;
#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);void* memset(void*,int,unsigned);void Graphics_FormatColoredMemberList(void*,void*,int);void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);void PartyMenu_OpenRecipientInventoryPreview(void*);void Window_SelectCanvasById(void*,unsigned);void Window_SetCanvasDisplayAttribute(void*,int,int);}
// Original: arm9/ov002 @ 0x0215D654; symbol: Graphics_RefreshSelectedMemberTextAndMenuMode; size: 0xd8.
extern "C" void PartyMenu_OpenRecipientAndInventoryPanels(unsigned char* self){PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self),(unsigned char)W(self,0x1bb8),4,1);memset(P(self,0x1bd0),0,2400);Graphics_FormatColoredMemberList(self,P(self,0x1bd0),0);Window_PushTextCanvas(self+0xec8,P(self,0x1bd0),0,1,0,1,0,0);PartyMenu_OpenRecipientInventoryPreview(self);PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self),(unsigned char)W(self,0x1bb8),7,1);Window_SelectCanvasById(self+0xec8,(unsigned char)W(self,0x1bb8));Window_SetCanvasDisplayAttribute(self+0xec8,(unsigned char)W(self,0x1bb8),0);}
