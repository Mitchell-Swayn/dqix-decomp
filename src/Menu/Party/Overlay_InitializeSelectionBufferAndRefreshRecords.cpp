struct WindowCanvasOwner;
struct WindowCanvasRecord;
struct PartyMenuState;
#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned int);
struct Owner;
struct Record { unsigned char pad[0xa8]; short a8,aa,ac,ae; };
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(char*,unsigned,unsigned);
extern "C" void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);
extern "C" void PartyMenu_FormatSelectedActionMpCost(void*,void*,int);
extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
extern "C" int Window_ReplaceCanvasTextById(Owner*,unsigned,void*,unsigned,unsigned char);
// Original: arm9/ov002 @ 0x0215EF60; symbol: Overlay_InitializeSelectionBufferAndRefreshRecords; size: 0x124.
extern "C" void Overlay_InitializeSelectionBufferAndRefreshRecords(unsigned char* self) {
 int addend=23, position=9, base=0;
 Record* first=(Record*)Window_FindActiveCanvasById((WindowCanvasOwner*)((Owner*)(self+0xec8)),0x10);
 if(first){ position=(short)(first->ae+first->aa); addend=first->ac; base=first->a8; }
 Window_BindNextCanvasResourceByFormatAndLayer((char*)self+0xec8,0,2);
 PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self),0x13,addend,position);
 memset(*(void**)(self+0x1000+0xbd0),0,0x960);
 PartyMenu_FormatSelectedActionMpCost(self,*(void**)(self+0x1000+0xbd0),0);
 Window_PushTextCanvas((char*)self+0x2c8+0xc00,*(void**)(self+0x1000+0xbd0),0,0,0,1,0,0);
 Record* second=(Record*)Window_FindActiveCanvasById((WindowCanvasOwner*)((Owner*)(self+0xec8)),0x13);
 if(second){ short oldA8=second->a8; short oldAe=second->ae; int total=addend+base; second->ac=total-oldA8; second->ae=oldAe; Window_ReplaceCanvasTextById((Owner*)(self+0x2c8+0xc00),0x13,*(void**)(self+0x1000+0xbd0),1,0); }
}
