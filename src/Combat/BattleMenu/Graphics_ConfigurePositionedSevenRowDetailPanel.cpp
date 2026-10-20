struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void GameState_BuildIndexedTextAndEnsureReadyRecord(void*,void*),BattleMenu_ConfigureGlobalCommandSelection(void*,int,int),BattleMenu_AppendEquipmentChoicePage(void*,void*),Window_PushTextCanvas(void*,void*,int,int,int,int,int,int),BattleMenu_PositionStackedWindowsWithinScreen(void*,int,int);extern "C" unsigned TextContext_GetSharedInstance();extern "C" void* memset(void*,int,unsigned);extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);extern "C" int Window_ReplaceCanvasTextById(void*,unsigned,void*,unsigned,unsigned char);
// Original: arm9/ov000 @ 0x02178074; symbol: Graphics_ConfigurePositionedSevenRowDetailPanel; size 0x128.
extern "C" void Graphics_ConfigurePositionedSevenRowDetailPanel(char* self,void* source,int a,int b){if(!source)return;int x=W(source,0x44),y=W(source,0x48);GameState_BuildIndexedTextAndEnsureReadyRecord(self,source);BattleMenu_ConfigureGlobalCommandSelection(self,a,b);char* panel=self+0x188;H(panel,0xa0)=18;H(panel,0xa2)=9;H(panel,0xa4)=(x>>3)+14;H(panel,0xa6)=y>>3;H(panel,0xa8)=12;H(panel,0xaa)=8;H(panel,0xac)=10;H(panel,0xae)=12;B(panel,0xb1)=7;int count=W(panel,0x58);void* scratch=P((void*)TextContext_GetSharedInstance(),0x5c);memset(scratch,0,0x960);BattleMenu_AppendEquipmentChoicePage(self,scratch);Window_PushTextCanvas(panel,scratch,0,0,count>1,1,0,0);void* row=(void*)Window_FindActiveCanvasById((WindowCanvasOwner*)(panel),33);if(row)H(row,0xc2)=0;BattleMenu_PositionStackedWindowsWithinScreen(panel,7,33);Window_ReplaceCanvasTextById(panel,7,scratch,1,0);}
