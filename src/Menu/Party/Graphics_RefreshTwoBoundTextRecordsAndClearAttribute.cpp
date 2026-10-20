struct PartyMenuState;
extern "C" void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);
#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(char*,unsigned,unsigned),Window_PushTextCanvas(void*,void*,int,int,int,int,int,int),Window_SetCanvasDisplayAttribute(char*,int,int),Graphics_AppendTwoCenteredIndexedTextLines(char*,char*);extern "C" int TextMarkup_AppendCursorTag(char*,int);extern "C" void* memset(void*,int,unsigned);
// Original: arm9/ov002 @ 0x02160068; symbol: Graphics_RefreshTwoBoundTextRecordsAndClearAttribute; size 0x128.
extern "C" void Graphics_RefreshTwoBoundTextRecordsAndClearAttribute(char* self){Window_BindNextCanvasResourceByFormatAndLayer(self+0xec8,0,3);PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self),29,21,11);memset(P(self,0x1bd0),0,0x960);((void(*)(char*,char*,int))Graphics_AppendTwoCenteredIndexedTextLines)(self,P(self,0x1bd0),0);Window_PushTextCanvas(self+0xec8,P(self,0x1bd0),0,0,0,1,0,0);Window_BindNextCanvasResourceByFormatAndLayer(self+0xec8,0,3);PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self),(unsigned char)W(self,0x1bb8),4,3);memset(P(self,0x1bd0),0,0x960);TextMarkup_AppendCursorTag(P(self,0x1bd0),S(self,0x1c06));Window_PushTextCanvas(self+0xec8,P(self,0x1bd0),0,0,0,1,0,0);Window_SetCanvasDisplayAttribute(self+0xec8,29,0);}
