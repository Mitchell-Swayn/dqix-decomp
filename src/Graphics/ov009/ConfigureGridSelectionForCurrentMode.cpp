#include <globaldefs.h>
ARM
extern "C" void Grid_SetOrientationAndCoordinatePointers(unsigned char*,int,int,int);
extern "C" void SetNonnegativeValueAndClampSelection(int*,int);
extern "C" void ComputePageRowAndColumn(void*,int);
extern "C" void InitializeSelectionDefaultsAndByteFields(char*);
// Original: arm9/ov009 @ 0x02188C2C; symbol: func_ov009_02188c2c; size: 0x170.
extern "C" void ConfigureGridSelectionForCurrentMode(unsigned char* self) {
 int columns,rows,count,pages,index;
 switch(*(signed char*)(self+0xc58)) {
 case 1: columns=1;rows=2;count=2;pages=1;index=self[0xda3];break;
 case 2: columns=5;rows=1;count=5;pages=1;index=*(self+self[0xda3]+0xda4);break;
 case 3: columns=5;rows=2;index=*(self+self[0xda3]+0xdac);count=10;pages=1;break;
 case 4: columns=5;rows=2;index=*(self+self[0xda3]+0xdae);count=10;pages=1;break;
 case 5: columns=5;rows=2;index=*(self+self[0xda3]+0xda6);count=10;pages=1;break;
 case 6: columns=4;rows=2;index=*(self+self[0xda3]+0xdaa);count=8;pages=1;break;
 case 7: columns=4;rows=2;index=*(self+self[0xda3]+0xda8);count=8;pages=1;break;
 case 8: columns=11;rows=6;count=66;pages=1;index=0;break;
 }
 unsigned char* base=self+0x3ec;
 InitializeSelectionDefaultsAndByteFields((char*)base+0x800);
 Grid_SetOrientationAndCoordinatePointers(base+0x800,columns,rows,1);
 SetNonnegativeValueAndClampSelection((int*)(base+0x800),count);
 *(int*)(base+0x804)=pages;
 ComputePageRowAndColumn(base+0x800,index);
 base[0x83d]=0;
}
