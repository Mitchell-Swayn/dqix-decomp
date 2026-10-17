#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" {
extern unsigned short data_ov031_022493b8[];
extern unsigned char* data_ov031_02250c00;
extern unsigned short data_ov031_02248cda[],data_ov031_02248c88[],data_ov031_02248cb0[],data_ov031_02248c90[],data_ov031_02248cb8[],data_ov031_02248c94[];
void BuildHalfwordRectangleFromOriginAndSize(unsigned short*,unsigned short*,unsigned short*);
int IsInputPointWithinRectangle(unsigned short*);
void System_ResolveGlobalGroupEntry(int);
}
// Original: arm9/ov031 @ 0x02225F2C; symbol: func_ov031_02225f2c; size: 0x1DC.
extern "C" void Graphics_UpdateTouchSelectionFromThreeButtonGroups() {
 if(!IsInputPointWithinRectangle(data_ov031_022493b8))return;
 *(signed char*)(data_ov031_02250c00+0x61)=-1;
 unsigned short rect[4];
 {
 unsigned short* origin=data_ov031_02248cda;
 for(int i=0;i<10;i++,origin+=2) {
  BuildHalfwordRectangleFromOriginAndSize(origin,data_ov031_02248c88,rect);
  if(IsInputPointWithinRectangle(rect)) {
   if(!data_ov031_02250c00[0x67]) {System_ResolveGlobalGroupEntry(9);return;}
   System_ResolveGlobalGroupEntry(0);
   data_ov031_02250c00[0x61]=i;
   return;
  }
 }
 }
 {
 unsigned short* origin=data_ov031_02248cb0;
 for(int i=0;i<2;i++,origin+=2) {
  BuildHalfwordRectangleFromOriginAndSize(origin,data_ov031_02248c90,rect);
  if(IsInputPointWithinRectangle(rect)) {
   if((i==0 && !data_ov031_02250c00[0x66]) || (i==1 && !data_ov031_02250c00[0x68])) {System_ResolveGlobalGroupEntry(9);return;}
   System_ResolveGlobalGroupEntry(0);
   data_ov031_02250c00[0x61]=i+10;
   return;
  }
 }
 }
 {
 unsigned short* origin=data_ov031_02248cb8;
 for(int i=0;i<2;i++,origin+=2) {
  BuildHalfwordRectangleFromOriginAndSize(origin,data_ov031_02248c94,rect);
  if(IsInputPointWithinRectangle(rect)) {
   System_ResolveGlobalGroupEntry(0);
   data_ov031_02250c00[0x61]=i+12;
   return;
  }
 }
 }
}
