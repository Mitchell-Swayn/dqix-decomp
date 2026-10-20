struct PartyMenuState;
#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(char*,unsigned,unsigned);extern "C" void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);extern "C" void Text_BuildSevenMappedOptionsAndFinalRow(char*,char*,int);extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
// Original: arm9/ov002 @ 0x02160734; symbol: RebuildSevenMappedMenuOptions; size: 0x98.
// Clears and rebuilds the seven mapped option text buffer, then binds it to menu records.
extern "C" void RebuildSevenMappedMenuOptions(char* self){Window_BindNextCanvasResourceByFormatAndLayer(self+0xec8,0,2);PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self),*(unsigned*)(self+0x1bb8)&255,1,1);memset(*(void**)(self+0x1bd0),0,0x960);Text_BuildSevenMappedOptionsAndFinalRow(self,*(char**)(self+0x1bd0),0);Window_PushTextCanvas(self+0xec8,*(void**)(self+0x1bd0),0,0,0,1,0,0);}
