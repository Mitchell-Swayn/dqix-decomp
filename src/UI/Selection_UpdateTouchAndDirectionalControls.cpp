#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
struct State;struct Owner;struct Grid;struct GridSelection;extern "C" unsigned Selection_SelectEntryAtEnabledTouch(State*);extern "C" int Grid_ReadLinearIndexWhenEnabled(unsigned char*);extern "C" void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);extern "C" void Grid_ResetDirectionalRepeat(unsigned char*);extern "C" void Grid_ResetTouchTracking(char*);extern "C" int Grid_UpdateTouchSelectionFromInput(Owner*);extern "C" int Grid_ComputeSelectedLinearIndex(int*);extern "C" int Grid_UpdateDirectionalSelection(Grid*,int);extern "C" void Grid_SelectIndexAndInvalidateTouchHistory(State*,int);
// Original: arm9/main @ 0x0205C5B0; symbol: Input_UpdatePointerOrDirectionalSelectionAndReportChange; size: 0x10C.
extern "C" int Selection_UpdateTouchAndDirectionalControls(char* self,int ticks){int result=0,old=W(self,52);if(B(self,148)&&Selection_SelectEntryAtEnabledTouch((State*)self)){int index=Grid_ReadLinearIndexWhenEnabled((unsigned char*)self+4);Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(self+84),index);Grid_ResetDirectionalRepeat((unsigned char*)self+84);Grid_ResetTouchTracking(self+4);result=1;}else if(B(self,148)&&((int(*)(Owner*,int))Grid_UpdateTouchSelectionFromInput)((Owner*)(self+4),ticks)){int index=Grid_ReadLinearIndexWhenEnabled((unsigned char*)self+4);if(old!=index)result=2;Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(self+84),index);Grid_ResetDirectionalRepeat((unsigned char*)self+84);}else if(B(self,149)){old=Grid_ComputeSelectedLinearIndex((int*)(self+84));if(Grid_UpdateDirectionalSelection((Grid*)(self+84),ticks)&&old!=Grid_ComputeSelectedLinearIndex((int*)(self+84))){result=1;int index=Grid_ComputeSelectedLinearIndex((int*)(self+84));Grid_SelectIndexAndInvalidateTouchHistory((State*)(self+4),index);W(self,52)=-1;Grid_ResetTouchTracking(self+4);}}return result;}
