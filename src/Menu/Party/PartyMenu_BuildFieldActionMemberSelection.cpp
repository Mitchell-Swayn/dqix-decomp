struct PartyMenuState;
#include <globaldefs.h>
ARM
extern "C" int Window_SelectCanvasById(...);
extern "C" int Window_SetCanvasDisplayAttribute(...);
extern "C" int Window_PushTextCanvas(...);
extern "C" void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);
extern "C" int PartyMenu_AppendFieldActionMemberNames(...);
extern "C" int PartyMenu_BuildFieldActionListAndDetails(...);
extern "C" void* memset(void*,int,unsigned);extern "C" unsigned strlen(const char*);
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
// Original: arm9/ov002 @ 0x0215E900; symbol: PrepareMenuTextCanvasAndConfigureTwoAttributes; size: 0xc4.
extern "C" void PartyMenu_BuildFieldActionMemberSelection(char* self){
PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self),W(self,0x1bb8)&255,1,1);memset(P(self,0x1bd0),0,2400);PartyMenu_AppendFieldActionMemberNames(self,P(self,0x1bd0),0);Window_PushTextCanvas(self+0xec8,P(self,0x1bd0),0,1,0,1,0,0);PartyMenu_BuildFieldActionListAndDetails(self,1);Window_SetCanvasDisplayAttribute(self+0xec8,17,1);Window_SelectCanvasById(self+0xec8,16);Window_SetCanvasDisplayAttribute(self+0xec8,16,0);
}
