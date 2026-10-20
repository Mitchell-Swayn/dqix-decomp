struct PartyMenuState;
#include <globaldefs.h>
ARM
extern "C" void PartyMenu_ReadCanvasBounds(PartyMenuState*,int,short*,short*,short*,short*);
extern "C" void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);
extern "C" void* memset(void*,int,unsigned);
extern "C" void PartyMenu_AppendInventoryCategoryOptions(void*,void*,int);
extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
// Original: arm9/ov002 @ 0x0215C474; symbol: Resource_ReloadBufferFromReadyRecordBounds; size: 0xb8.
extern "C" void PartyMenu_OpenInventoryCategoryPanel(char* self) {
 short a=0,b=0,c=1,d=1;PartyMenu_ReadCanvasBounds((PartyMenuState*)(self),1,(short*)(&a),(short*)(&b),(short*)(&c),(short*)(&d));PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self),*(int*)(self+0x1bb8)&255,a,b);memset(*(void**)(self+0x1bd0),0,2400);PartyMenu_AppendInventoryCategoryOptions(self,*(void**)(self+0x1bd0),0);Window_PushTextCanvas(self+0xec8,*(void**)(self+0x1bd0),0,1,0,1,0,0);
}
