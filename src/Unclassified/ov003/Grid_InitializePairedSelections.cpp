#include <globaldefs.h>
ARM
struct GridSelection; struct State;
extern "C" void Grid_SetOrientationAndCoordinatePointers(unsigned char*,int,int,int);
extern "C" void SetNonnegativeValueAndClampSelection(int*,int);
extern "C" void ComputePageRowAndColumn(GridSelection*,int);
extern "C" void Selection_InvalidateIndexAndComputePageCoordinates(State*,int);
// Original: arm9/ov003 @ 0x0215DD3C; symbol: func_ov003_0215dd3c; size: 0x84.
extern "C" void Grid_InitializePairedSelections(unsigned char* p) {
 int count,width,index;
 if(p[0x148]==1){count=p[0x3c0];width=1;index=*(signed char*)(p+0x3c1);}
 Grid_SetOrientationAndCoordinatePointers(p+0x9c,width,count,0);
 Grid_SetOrientationAndCoordinatePointers(p+0xec,width,count,0);
 SetNonnegativeValueAndClampSelection((int*)(p+0x9c),count);
 SetNonnegativeValueAndClampSelection((int*)(p+0xec),count);
 *(int*)(p+0xa0)=width;
 *(int*)(p+0xf0)=width;
 Selection_InvalidateIndexAndComputePageCoordinates((State*)(p+0x9c),index);
 ComputePageRowAndColumn((GridSelection*)(p+0xec),index);
}
