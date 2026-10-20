struct PartyMenuState;
#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);extern "C" void Graphics_AppendIndexedPartyAndExtraText(char*,char*,int);extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);extern "C" void PartyMenu_OpenRecipientInventoryPreview(void*);extern "C" void Window_SelectCanvasById(void*,unsigned);extern "C" void Window_SetCanvasDisplayAttribute(void*,int,int);
// Original: arm9/ov002 @ 0x0215DAE0; symbol: RebuildPartyOptionTextAndSelectMode11; size: 0xAC.
// Rebuilds party-option text in the960-byte-word buffer and selects mode11 with zero low nibble.
extern "C" void RebuildPartyOptionTextAndSelectMode11(char* self){PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self),*(unsigned*)(self+0x1bb8)&255,5,1);memset(*(void**)(self+0x1bd0),0,0x960);Graphics_AppendIndexedPartyAndExtraText(self,*(char**)(self+0x1bd0),0);Window_PushTextCanvas(self+0xec8,*(void**)(self+0x1bd0),0,1,0,1,0,0);PartyMenu_OpenRecipientInventoryPreview(self);Window_SelectCanvasById(self+0xec8,11);Window_SetCanvasDisplayAttribute(self+0xec8,11,0);}
