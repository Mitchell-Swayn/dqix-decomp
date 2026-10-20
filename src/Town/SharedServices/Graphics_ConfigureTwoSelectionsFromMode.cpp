#include <globaldefs.h>
ARM
struct GridSelection;struct State;
extern "C" void Grid_SetOrientationAndCoordinatePointers(unsigned char*,int,int,int);
extern "C" void Grid_SetEntryCountAndClampSelection(int*,int);
extern "C" void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);
extern "C" void Grid_SelectIndexAndInvalidateTouchHistory(State*,int);
// Original: arm9/ov003 @ 0x0215B3BC; symbol: func_ov003_0215b3bc; size: 0xBC.
extern "C" void Graphics_ConfigureTwoSelectionsFromMode(unsigned char* p) {
int columns,rows,index;
switch(p[0x1a4]){
case 1:columns=p[0x589];index=*(signed char*)(p+0x584);rows=1;break;
case 2:columns=p[0x590];index=*(signed char*)(p+0x585);rows=1;break;
case 3:index=*(signed char*)(p+0x586);rows=1;columns=2;break;
}
Grid_SetOrientationAndCoordinatePointers(p+0xf8,rows,columns,0);
Grid_SetOrientationAndCoordinatePointers(p+0x148,rows,columns,0);
Grid_SetEntryCountAndClampSelection((int*)(p+0xf8),columns);
Grid_SetEntryCountAndClampSelection((int*)(p+0x148),columns);
*(int*)(p+0xfc)=rows;*(int*)(p+0x14c)=rows;
Grid_SelectIndexAndInvalidateTouchHistory((State*)(p+0xf8),index);
Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(p+0x148),index);
}
