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
extern "C" int BattleMenu_CountEnemyTargetGroups(void*);extern "C" int BattleMenu_GetEnemyTargetGroupIndex(void*,int);extern "C" void BattleMenu_ConfigureGlobalCommandSelection(void*,int,int);extern "C" void Grid_SetOrientationAndCoordinatePointers(unsigned char*,int,int,int);extern "C" void Grid_SetEntryCountAndClampSelection(int*,int);extern "C" void Grid_SelectIndexAndComputePageCoordinates(void*,int);extern "C" unsigned TextContext_GetSharedInstance();extern "C" void BattleMenu_AppendSharedActionEnemyGroupNames(void*,void*,int,void*);extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
// Original: arm9/ov000 @ 0x0217A514; symbol: Graphics_BuildSelectedItemActionMenu; size: 0x114.
extern "C" void BattleMenu_BuildSharedActionEnemyGroupWindow(char* self,char* item,int a,int b){
if(!item)return;int count=BattleMenu_CountEnemyTargetGroups(self);int selected=BattleMenu_GetEnemyTargetGroupIndex(self,C(item,29));BattleMenu_ConfigureGlobalCommandSelection(self,a,b);char* panel=self+0x188;H(panel,0xa0)=16;H(panel,0xa2)=1;H(panel,0xa4)=13;H(panel,0xa6)=9;H(panel,0xa8)=12;H(panel,0xaa)=6;H(panel,0xac)=10;H(panel,0xae)=16;B(panel,0xb1)=25;Grid_SetOrientationAndCoordinatePointers((unsigned char*)self+0x244,1,count,0);I(self,0x248)=1;Grid_SetEntryCountAndClampSelection((int*)(self+0x244),count);Grid_SelectIndexAndComputePageCoordinates(self+0x244,selected);char* buffer=V((char*)TextContext_GetSharedInstance(),0x5c);memset(buffer,0,0x960);BattleMenu_AppendSharedActionEnemyGroupNames(self,item,b,buffer);Window_PushTextCanvas(panel,buffer,0,1,0,1,0,0);
}
