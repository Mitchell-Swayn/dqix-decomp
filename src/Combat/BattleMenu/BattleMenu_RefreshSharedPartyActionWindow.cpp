struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" int Graphics_AppendSelectableRecordNameList(...);
extern "C" int Window_ReplaceCanvasTextById(...);
extern "C" int Window_SetCanvasEnabled(...);
extern "C" int TextContext_GetSharedInstance(...);
extern "C" int BattleMenu_UpdateSharedPartyActionDescriptionWindow(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov000 @ 0x0217A0A4; symbol: LoadSelectableNameListAndResetReadyRecordFlags.
extern "C" void BattleMenu_RefreshSharedPartyActionWindow(char*self){
char*buffer=P(C(TextContext_GetSharedInstance()),92);memset(buffer,0,0x960);Graphics_AppendSelectableRecordNameList(self,0,buffer);Window_ReplaceCanvasTextById(self+0x188,23,buffer,1,0);if(B(self,0x1d81)){Window_SetCanvasEnabled(self+0x188,0,24);Window_SetCanvasEnabled(self+0x188,0,25);char*record=C((int)Window_FindActiveCanvasById((WindowCanvasOwner*)(self+0x188),23));if(record){B(record,197)&=~64;H(record,194)=0;}H(self,0x1d72)&=~256;}if(B(self,0x1d79)){BattleMenu_UpdateSharedPartyActionDescriptionWindow(self,0);return;}char*record=C((int)Window_FindActiveCanvasById((WindowCanvasOwner*)(self+0x188),24));if(record)H(record,194)=0;B(self+0x1000,0xd79)=1;
}
