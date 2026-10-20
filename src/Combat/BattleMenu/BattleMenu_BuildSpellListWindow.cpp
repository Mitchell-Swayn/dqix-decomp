struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define I(p,o) (*(int*)((p)+(o)))
#define U(p,o) (*(unsigned*)((p)+(o)))
#define H(p,o) (*(unsigned short*)((p)+(o)))
#define S(p,o) (*(short*)((p)+(o)))
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define C(p,o) (*(signed char*)((p)+(o)))
#define V(p,o) (*(char**)((p)+(o)))
extern "C" void BattleMenu_UpdateSpellDescriptionWindow(void*);extern "C" void BattleMenu_ConfigureActorCommandSelection(void*,int,int);extern "C" int Grid_GetEntryCount(void*);extern "C" unsigned TextContext_GetSharedInstance();extern "C" void BattleMenu_AppendVisibleSpellNames(char*,char*,char*);extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);extern "C" void BattleMenu_PositionStackedWindowsWithinScreen(void*,int,int);
// Original: arm9/ov000 @ 0x02178BA8; symbol: Graphics_BuildPagedMenuWithRecord34; size: 0x114.
extern "C" void BattleMenu_BuildSpellListWindow(char* self,char* list,int a,int b){
BattleMenu_UpdateSpellDescriptionWindow(self);int x=I(list,0x44),y=I(list,0x48);BattleMenu_ConfigureActorCommandSelection(list,a,b);char* panel=self+0x188;H(panel,0xa0)=16;H(panel,0xa2)=9;H(panel,0xa4)=(x>>3)+16;H(panel,0xa6)=y>>3;H(panel,0xa8)=12;H(panel,0xaa)=8;H(panel,0xac)=10;H(panel,0xae)=12;B(panel,0xb1)=15;int paged=0;if(Grid_GetEntryCount(panel+0x54)>4)paged=1;char* buffer=V((char*)TextContext_GetSharedInstance(),0x5c);memset(buffer,0,0x960);BattleMenu_AppendVisibleSpellNames(self,list,buffer);Window_PushTextCanvas(panel,buffer,0,0,paged,1,0,0);char* record=(char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(panel),34);if(record)H(record,0xc2)=0;BattleMenu_PositionStackedWindowsWithinScreen(self+0x188,15,34);
}
