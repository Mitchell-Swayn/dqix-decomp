#include <globaldefs.h>
#include <std_library_functions.h>
struct State{char pad[0x98];void* a;void* b;char gap[0x13];unsigned char mode;};
extern "C" void Window_PopCanvasesAndResetSelection(State*,int);
extern "C" void Menu_ConfigureSecondaryPanelCanvasLayout(unsigned char*,int,int,int);
extern "C" void Menu_AppendOptionalPanelText(void*);
extern "C" void Text_AppendGlyphGrid(unsigned char*);
extern "C" void Menu_AppendCenteredLocalPartyName(char*);
extern "C" void Menu_AppendPresentSelectionMessage(void*);
extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
extern "C" void Window_SetCanvasDisplayAttribute(char*,int,int);
// Original: arm9/ov023 @ 0x021E802C; symbol: func_ov023_021e802c; size: 0x1C8.
// Initializes five present-selection text panels and their configured entry attributes.
extern "C" void InitializePresentSelectionTextPanels(unsigned char* self) {
    Window_PopCanvasesAndResetSelection((State*)(self+0x78),1);
    Menu_ConfigureSecondaryPanelCanvasLayout(self,0x0c,0,5);
    memset(*(char**)(self+0x5d8),0,0x960);
    Menu_AppendOptionalPanelText(self);
    Window_PushTextCanvas(self+0x78,*(char**)(self+0x5d8),0,0,0,0,0,1);
    Menu_ConfigureSecondaryPanelCanvasLayout(self,0x0d,0,0x10);
    memset(*(char**)(self+0x5d8),0,0x960);
    Text_AppendGlyphGrid(self);
    Window_PushTextCanvas(self+0x78,*(char**)(self+0x5d8),0,0,0,0,0,1);
    Menu_ConfigureSecondaryPanelCanvasLayout(self,0x0e,0,2);
    memset(*(char**)(self+0x5d8),0,0x960);
    Menu_AppendCenteredLocalPartyName((char*)self);
    Window_PushTextCanvas(self+0x78,*(char**)(self+0x5d8),1,0,0,1,0,0);
    Menu_ConfigureSecondaryPanelCanvasLayout(self,0x0f,0,0x0d);
    Window_PushTextCanvas(self+0x78,*(char**)(self+0x5d8),1,0,0,1,0,0);
    Menu_ConfigureSecondaryPanelCanvasLayout(self,0x10,0x0f,0x0d);
    memset(*(char**)(self+0x5d8),0,0x960);
    Menu_AppendPresentSelectionMessage(self);
    Window_PushTextCanvas(self+0x78,*(char**)(self+0x5d8),1,1,0,1,0,1);
    for(int i=0;i<5;i++) Window_SetCanvasDisplayAttribute((char*)self+0x78,(i+0x0c)&0xff,0);
}
