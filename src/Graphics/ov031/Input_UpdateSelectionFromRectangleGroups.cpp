#include <globaldefs.h>
ARM
extern "C" void System_ResolveGlobalGroupEntry(int);
extern "C" void BuildHalfwordRectangleFromOriginAndSize(unsigned short*,unsigned short*,unsigned short*);
extern "C" int IsInputPointWithinRectangle(unsigned short*);
extern "C" unsigned short data_ov031_022493b8[];
extern "C" unsigned char* data_ov031_02250bfc;
extern "C" unsigned short data_ov031_02248a0c[][2],data_ov031_022489c8[];
extern "C" unsigned short data_ov031_022489e4[][2],data_ov031_022489f4[][2];
extern "C" int data_ov031_0224b43c[];
extern "C" unsigned short data_ov031_022489dc[][2],data_ov031_022489c4[];
// Original: arm9/ov031 @ 0x022242EC; symbol: func_ov031_022242ec; size: 0x1E8.
extern "C" void Input_UpdateSelectionFromRectangleGroups() {
 unsigned short rect[4];
 if(!IsInputPointWithinRectangle(data_ov031_022493b8)) return;
 *(signed char*)(data_ov031_02250bfc+0x11e)=-1;
 int i=0;
 do {
 BuildHalfwordRectangleFromOriginAndSize(data_ov031_02248a0c[i],data_ov031_022489c8,rect);
 if(IsInputPointWithinRectangle(rect)) {
 if(!data_ov031_02250bfc[0x124]) {System_ResolveGlobalGroupEntry(9);return;}
 System_ResolveGlobalGroupEntry(0);data_ov031_02250bfc[0x11e]=i;return;
 }
 ++i;
 }while(i<47);
 i=0;
 do {
 BuildHalfwordRectangleFromOriginAndSize(data_ov031_022489e4[i],data_ov031_022489f4[i],rect);
 if(IsInputPointWithinRectangle(rect)) {
 if((i==3 && !data_ov031_02250bfc[0x123]) || (i==2 && !data_ov031_02250bfc[0x124])) {System_ResolveGlobalGroupEntry(9);return;}
 System_ResolveGlobalGroupEntry(data_ov031_0224b43c[i]);data_ov031_02250bfc[0x11e]=i+47;return;
 }
 ++i;
 }while(i<4);
 i=0;
 do {
 BuildHalfwordRectangleFromOriginAndSize(data_ov031_022489dc[i],data_ov031_022489c4,rect);
 if(IsInputPointWithinRectangle(rect)) {
 System_ResolveGlobalGroupEntry(0);data_ov031_02250bfc[0x11e]=i+51;return;
 }
 ++i;
 }while(i<2);
}
