#include <globaldefs.h>
ARM
extern "C" void Grid_SetOrientationAndCoordinatePointers(unsigned char*,int,int,int);
extern "C" void Grid_SetEntryCountAndClampSelection(int*,int);
struct GridSelection;
extern "C" void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);
extern "C" void Grid_InitializeDirectionalSelection(char*);
// Original: arm9/ov003 @ 0x021696F4; symbol: func_ov003_021696f4; size: 0x138.
extern "C" void Grid_ConfigureSelectionFromColumnLimits(char* self,int column) {
 int current=*(signed char*)(self+0x4ef+column);
 int enabled=0;
 for(int i=0;i<column;i++) {
  if(*(signed char*)(self+0x4ef+i)<*(signed char*)(self+0x4f3+i))break;
  if(i==column-1)enabled=1;
 }
 if(column==0)enabled=1;
 int first=3;
 for(int i=0;i<4;i++) {
  if(*(signed char*)(self+0x4f3+i)>0){first=i;break;}
 }
 if(column<=first)enabled=0;
 Grid_InitializeDirectionalSelection(self+0x4fc);
 if(enabled) {
  int limit=*(signed char*)(self+0x4f3+column);
  Grid_SetOrientationAndCoordinatePointers((unsigned char*)self+0x4fc,1,limit+1,0);
  *(int*)(self+0x500)=1;
  Grid_SetEntryCountAndClampSelection((int*)(self+0x4fc),limit+1);
  Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(self+0x4fc),limit-current);
 } else {
  Grid_SetOrientationAndCoordinatePointers((unsigned char*)self+0x4fc,1,10,0);
  *(int*)(self+0x500)=1;
  Grid_SetEntryCountAndClampSelection((int*)(self+0x4fc),10);
  Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(self+0x4fc),9-current);
 }
}
