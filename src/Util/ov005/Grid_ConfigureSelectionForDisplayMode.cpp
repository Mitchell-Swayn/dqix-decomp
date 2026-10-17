#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void Grid_SetOrientationAndCoordinatePointers(unsigned char*,int,int,int);
extern "C" void SetNonnegativeValueAndClampSelection(int*,int);
struct GridSelection;
extern "C" void ComputePageRowAndColumn(GridSelection*,int);
extern "C" void InitializeSelectionDefaultsAndByteFields(char*);
// Original: arm9/ov005 @ 0x021571D0; symbol: func_ov005_021571d0; size: 0x13C.
extern "C" void Grid_ConfigureSelectionForDisplayMode(char* self) {
 int columns,count,orientation,step;
 short rows;
 short index;
 int wrapA,wrapB;
 switch(*(unsigned char*)(self+0x3db8)) {
 case 0:
  rows=8; columns=1; orientation=0; count=rows; step=columns;wrapA=orientation;wrapB=step;
  index=*(unsigned char*)(self+0x3dbc); break;
 case 2:
  rows=1;columns=8;orientation=0;step=rows;count=columns;wrapA=step;wrapB=orientation;
  index=*(unsigned char*)(self+0x3dbc); break;
 case 3:
  rows=1;columns=8;orientation=0;step=rows;count=columns;wrapA=step;wrapB=orientation;
  index=*(unsigned char*)(self+0x3dbc); break;
 case 4:case 6:
  index=*(signed char*)(self+0x3dbb)-8;
  orientation=1;columns=4;rows=4;step=1;wrapA=1;count=16;wrapB=0;
  break;
 }
 InitializeSelectionDefaultsAndByteFields(self+0x19f4);
 Grid_SetOrientationAndCoordinatePointers((unsigned char*)self+0x19f4,columns,rows,orientation);
 SetNonnegativeValueAndClampSelection((int*)(self+0x19f4),count);
 *(int*)(self+0x19f8)=step;
 ComputePageRowAndColumn((GridSelection*)(self+0x19f4),index);
 *(unsigned char*)(self+0x1a30)=wrapA;
 *(unsigned char*)(self+0x1a31)=wrapB;
}
