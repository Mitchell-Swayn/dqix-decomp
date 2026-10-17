#include <globaldefs.h>
ARM
extern "C" void Grid_SetOrientationAndCoordinatePointers(void*,int,int,int);extern "C" void SetNonnegativeValueAndClampSelection(void*,int);
// Original: arm9/main @ 0x0205CF28; symbol: func_0205cf28; size: 0x50.
extern "C" void Selection_SetTwoGridDimensionsAndEntryCounts(char* p,int width,int height,int value){Grid_SetOrientationAndCoordinatePointers(p+4,width,height,value);Grid_SetOrientationAndCoordinatePointers(p+84,width,height,value);int count=width*height;SetNonnegativeValueAndClampSelection(p+4,count);SetNonnegativeValueAndClampSelection(p+84,count);}
