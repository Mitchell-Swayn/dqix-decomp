#include <globaldefs.h>
ARM
extern "C" void Overlay_UpdateSharedSignedStateIfChanged(int);
extern "C" void System_ResolveGlobalGroupEntry(int);
extern "C" void BuildHalfwordRectangleFromOriginAndSize(unsigned short*,unsigned short*,unsigned short*);
extern "C" int System_IsActiveInputPointWithinRectangle(const void*);
extern "C" unsigned short data_ov031_022493b8[];
extern "C" unsigned short data_ov031_02248cda[][2],data_ov031_02248c88[];
extern "C" unsigned short data_ov031_02248cb0[][2],data_ov031_02248c90[];
extern "C" unsigned short data_ov031_02248cb8[][2],data_ov031_02248c94[];
struct State { unsigned char pad[0x60]; unsigned char state; signed char selected; unsigned char pad2[3]; unsigned char hold,enabled; };
extern "C" State* data_ov031_02250c00;
// Original: arm9/ov031 @ 0x022262D8; symbol: func_ov031_022262d8; size: 0x1F0.
extern "C" void Input_UpdateHeldRectangleSelectionAndRepeat() {
 unsigned short rect[4];
 if(!System_IsActiveInputPointWithinRectangle(data_ov031_022493b8)) goto reset;
 {
 int i=0;
 do {
 BuildHalfwordRectangleFromOriginAndSize(data_ov031_02248cda[i],data_ov031_02248c88,rect);
 if(System_IsActiveInputPointWithinRectangle(rect)) {
 if(data_ov031_02250c00->selected!=i) goto reset;
 Overlay_UpdateSharedSignedStateIfChanged(i);goto done;
 }
 ++i;
 }while(i<10);
 }
 {
 unsigned short* origin=data_ov031_02248cb0[0];
 int i=0;
 do {
 BuildHalfwordRectangleFromOriginAndSize(origin,data_ov031_02248c90,rect);
 if(System_IsActiveInputPointWithinRectangle(rect)) {
 int code=i+10;
 if(data_ov031_02250c00->selected!=code) goto reset;
 Overlay_UpdateSharedSignedStateIfChanged(code);
 if(i!=0) goto done;
 data_ov031_02250c00->hold++;
 if(data_ov031_02250c00->hold<40) return;
 if(!data_ov031_02250c00->enabled) {
 System_ResolveGlobalGroupEntry(9);
 data_ov031_02250c00->selected=-1;return;
 }
 data_ov031_02250c00->state=16;
 data_ov031_02250c00->hold-=7;return;
 }
 ++i;origin+=2;
 }while(i<2);
 }
 {
 unsigned short* origin=data_ov031_02248cb8[0];
 int i=0;
 do {
 BuildHalfwordRectangleFromOriginAndSize(origin,data_ov031_02248c94,rect);
 if(System_IsActiveInputPointWithinRectangle(rect)) {
 int code=i+12;
 if(data_ov031_02250c00->selected!=code) goto reset;
 Overlay_UpdateSharedSignedStateIfChanged(code);goto done;
 }
 ++i;origin+=2;
 }while(i<2);
 }
 reset:Overlay_UpdateSharedSignedStateIfChanged(-1);
 done:data_ov031_02250c00->hold=0;
}
