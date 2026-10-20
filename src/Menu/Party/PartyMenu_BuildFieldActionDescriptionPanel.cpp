struct WindowCanvasOwner;
struct WindowCanvasRecord;
struct PartyMenuState;
#include <globaldefs.h>
ARM
extern "C" {WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);void Window_BindNextCanvasResourceByFormatAndLayer(void*,unsigned,unsigned);void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);void* memset(void*,int,unsigned);void Graphics_FormatSelectedDescriptorOutput(void*,void*,int);void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);}
// Original: arm9/ov002 @ 0x0215EE04; symbol: ConfigureSelectedDescriptorBufferAtRecordRightEdge; size: 0xbc.
// Computes ready record right edge, configures descriptor and submits cleared formatted buffer.
extern "C" void PartyMenu_BuildFieldActionDescriptionPanel(char* self){short edge=16;char* record=(char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self+0xec8),16);if(record)edge=*(short*)(record+0xac)+*(short*)(record+0xa8);Window_BindNextCanvasResourceByFormatAndLayer(self+0xec8,0,2);PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self),18,edge,17);memset(*(void**)(self+0x1bd0),0,0x960);Graphics_FormatSelectedDescriptorOutput(self,*(void**)(self+0x1bd0),0);Window_PushTextCanvas(self+0xec8,*(void**)(self+0x1bd0),0,0,0,0,0,0);}
