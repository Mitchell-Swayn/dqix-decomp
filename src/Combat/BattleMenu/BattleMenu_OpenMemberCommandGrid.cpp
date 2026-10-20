#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define C(p,o) (*(signed char*)((char*)(p)+(o)))
#define V(p,o) (*(char**)((char*)(p)+(o)))
struct State;struct GridSelection;extern "C" unsigned TextContext_GetSharedInstance();extern "C" void Grid_SetEntryCountAndClampSelection(int*,int);extern "C" void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);extern "C" void Grid_SelectIndexAndInvalidateTouchHistory(State*,int);extern "C" void Selection_EnableTouchInput(int);extern "C" void Selection_EnableDirectionalInput(int);extern "C" void Selection_SetTwoGridDimensionsAndEntryCounts(char*,int,int,int);extern "C" void Window_PopCanvasesAndResetSelection(State*,int);extern "C" void Text_AppendSixObjectRecordLabels(unsigned char*,char*,int);extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
// Original: arm9/ov000 @ 0x0217636c; symbol: Graphics_ConfigureSixEntryGridAndPopulateLabels.
extern "C" void BattleMenu_OpenMemberCommandGrid(unsigned char* self,int prefix){
char* panel=V(self,0x38);if(!panel)return;int x=I(self,0x44),y=I(self,0x48);Window_PopCanvasesAndResetSelection((State*)panel,1);Selection_EnableTouchInput((int)panel);Selection_EnableDirectionalInput((int)panel);Selection_SetTwoGridDimensionsAndEntryCounts(panel,2,3,0);Grid_SetEntryCountAndClampSelection((int*)(panel+4),6);Grid_SetEntryCountAndClampSelection((int*)(panel+0x54),6);Grid_SelectIndexAndInvalidateTouchHistory((State*)(panel+4),0);Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(panel+0x54),0);I(panel,8)=1;I(panel,0x58)=1;H(panel,0xa0)=2;H(panel,0xa2)=1;H(panel,0xa4)=(x>>3)+9;H(panel,0xa6)=(y>>3)+1;H(panel,0xa8)=12;H(panel,0xaa)=14;H(panel,0xac)=10;H(panel,0xae)=14;B(panel,0xb1)=13;char* text=V((void*)TextContext_GetSharedInstance(),0x5c);memset(text,0,0x960);Text_AppendSixObjectRecordLabels(self,text,prefix);Window_PushTextCanvas(V(self,0x38),text,0,1,0,1,0,0);
}
