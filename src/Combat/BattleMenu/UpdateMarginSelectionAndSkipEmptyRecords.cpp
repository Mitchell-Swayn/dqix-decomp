#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct State {int count;char pad[44];int index;};struct GridSelection;
extern "C" {
int Window_GetTouchedCanvasSideMargin(char*);
void Grid_AdvanceWrappedPageAndClampSelection(int*,int);
int Grid_ComputeSelectedLinearIndex(int*);
void Grid_SelectIndexAndInvalidateTouchHistory(State*,int);
void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);
int abs(int);
}
// Original: arm9/ov000 @ 0x0217C158; symbol: func_ov000_0217c158; size: 0x148.
// Advances side-margin selection; mode seventeen walks backward past null and unavailable records.
extern "C" int UpdateMarginSelectionAndSkipEmptyRecords(char* arg) {
 short column;int index;signed char row;short originalIndex;int oldColumn;char* grid;char* self=arg;
 int delta=Window_GetTouchedCanvasSideMargin(*(char**)(self+0x38));
 if(!delta)return 0;
 grid=*(char**)(self+0x38);
 Grid_AdvanceWrappedPageAndClampSelection((int*)(grid+0x54),delta);
 index=Grid_ComputeSelectedLinearIndex((int*)(grid+0x54));
 Grid_SelectIndexAndInvalidateTouchHistory((State*)(grid+4),index);
 switch(*(signed char*)(self+0x10+*(signed char*)(self+0x18))) {
 case 15:self[0x20]=index;break;
 case 16:*(short*)(self+0x1e)=index;break;
 case 17: {
 oldColumn=*(signed char*)(self+0x22)&3;
 column=index&3;
 originalIndex=index;
 row=*(int*)(grid+0x68);
 short distance=abs(column-oldColumn);
 if(distance==1 && oldColumn<column) {
 if(!*(void**)(self+0x3f0+index*4))index=row<<2;
 }
 while(!*(void**)(self+0x3f0+index*4))--index;
 char* record;
 while((record=*(char**)(self+0x3f0+index*4))) {if(*(short*)(record+0x18)>0)break;--index;}
 if(originalIndex!=index) {
 Grid_SelectIndexAndInvalidateTouchHistory((State*)(grid+4),index);
 Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(grid+0x54),index);
 }
 self[0x22]=(signed char)index;*(short*)(self+0x2c)=-1;self[0x22]=(signed char)index;
 break;
 }
 }
 return 1;
}
