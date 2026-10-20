struct PartyMenuState;
#include <globaldefs.h>
ARM
extern "C" char* TextContext_GetSharedInstance(...);
extern "C" void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void* memset(void*,int,unsigned);
extern "C" int PartyMenu_FormatActionResultMessage(...);
extern "C" int TextContext_SetMessageWindow(...);
extern "C" int TextWindow_StartFormattedMessage(...);
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov002 @ 0x02161174; symbol: Graphics_RenderCachedOrFormattedPagedText; size: 0xc0.
// Graphics RenderCachedOrFormattedPagedText from listed field operations and calls.
extern "C" void Graphics_RenderCachedOrFormattedPagedText(char* self){char* display=TextContext_GetSharedInstance();PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self),W(self,0x1bb8)&255,0,15);if(B(self,0x1c31))memcpy(P(self,0x1bd0),P(self,0x1bd4),2400);else{memset(P(self,0x1bd0),0,2400);PartyMenu_FormatActionResultMessage(self,P(self,0x1bd0),0);}TextContext_SetMessageWindow(display,W(P(self,0),16));TextWindow_StartFormattedMessage(display,(*(char* volatile*)(self+0x1bd0)),0,227);W(display,0x998)=1;if(S(self,0x1c28)==0x232b)B(display,0x19ca)=0;}
