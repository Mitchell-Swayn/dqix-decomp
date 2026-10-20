#include <globaldefs.h>
ARM
extern "C" {void Window_PopCanvasesAndResetSelection(void*,int);void Menu_ConfigureSecondaryPanelCanvasLayout(unsigned char*,int,int,int);void* memset(void*,int,unsigned);void Text_FormatCharacterPackedSummary(char*);void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);}
// Original: arm9/ov023 @ 0x021E7F68; symbol: ResetAndSubmitCharacterSummaryBuffer; size: 0x7c.
// Resets selection, configures summary record, clears 960-byte buffer and submits display.
extern "C" void Menu_ShowCharacterSummaryCanvas(unsigned char* self) {Window_PopCanvasesAndResetSelection(self+0x78,1);Menu_ConfigureSecondaryPanelCanvasLayout(self,11,3,5);memset(*(void**)(self+0x5d8),0,0x960);if(*(int*)(self+0x5f4))Text_FormatCharacterPackedSummary((char*)self);Window_PushTextCanvas(self+0x78,*(void**)(self+0x5d8),0,0,0,1,0,0);}
