#include <globaldefs.h>
ARM
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_repositioncode off
#pragma force_active on
extern "C" {
int Window_GetTouchedCanvasSideMargin(char*);
void Grid_AdvanceWrappedPageAndClampSelection(int*,int);
int Grid_ComputeSelectedLinearIndex(int*);
struct State;
void Grid_SelectIndexAndInvalidateTouchHistory(State*,int);
}
// Original: arm9/ov000 @ 0x0217F3E4; symbol: func_ov000_0217f3e4; size: 0x80.
extern "C" int BattleMenu_AdvanceActionListPage(char* self) {
 int index;
 int* page;
 int* selection;
 char* window=self+0x188;
 int direction=Window_GetTouchedCanvasSideMargin(window);
 if (!direction) return 0;
 selection=(int*)(window+4);
 page=(int*)(window+0x54);
 Grid_AdvanceWrappedPageAndClampSelection(page,direction);
 index=Grid_ComputeSelectedLinearIndex(page);
 Grid_SelectIndexAndInvalidateTouchHistory((State*)selection,index);
 int mode=*(signed char*)(self+0x1d60+*(signed char*)(self+0x1d68));
 switch(mode) {
 case 6:self[0x1d6e]=index;break;
 case 7:self[0x1d6f]=index;break;
 }
 return 1;
}
