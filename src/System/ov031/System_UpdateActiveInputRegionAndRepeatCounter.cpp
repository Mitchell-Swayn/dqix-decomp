#include <globaldefs.h>
ARM
struct Rect { unsigned short v[4]; };
extern "C" Rect data_ov031_022493b8;
extern "C" unsigned short data_ov031_02248a0c[][2],data_ov031_022489c8[2],data_ov031_022489fc[][2],data_ov031_022489ec[][2],data_ov031_022489dc[][2],data_ov031_022489c4[2];
extern "C" char* data_ov031_02250bfc;
extern "C" void func_ov031_02224a20(int);
extern "C" void System_ResolveGlobalGroupEntry(int);
extern "C" void BuildHalfwordRectangleFromOriginAndSize(unsigned short*,unsigned short*,unsigned short*);
extern "C" int System_IsActiveInputPointWithinRectangle(const Rect*);
// Original: arm9/ov031 @ 0x0222481C; symbol: func_ov031_0222481c; size: 0x204.
extern "C" void System_UpdateActiveInputRegionAndRepeatCounter() {
 Rect rect;
 if(System_IsActiveInputPointWithinRectangle(&data_ov031_022493b8)) {
  for(int i=0;i<47;i++) {
   BuildHalfwordRectangleFromOriginAndSize(data_ov031_02248a0c[i],data_ov031_022489c8,rect.v);
   if(System_IsActiveInputPointWithinRectangle(&rect)) {
    if(*(signed char*)(data_ov031_02250bfc+0x11e)!=i) goto fail;
    func_ov031_02224a20(i);goto done;
   }
  }
  unsigned short* size=data_ov031_022489fc[0];
  unsigned short* origin=data_ov031_022489ec[0];
  for(int i=2;i<4;i++,size+=2,origin+=2) {
   BuildHalfwordRectangleFromOriginAndSize(origin,size,rect.v);
   if(System_IsActiveInputPointWithinRectangle(&rect)) {
    if(*(signed char*)(data_ov031_02250bfc+0x11e)!=i+47) goto fail;
    func_ov031_02224a20(i+47);
    if(i!=3)return;
    ++*(unsigned char*)(data_ov031_02250bfc+0x122);
    if(*(unsigned char*)(data_ov031_02250bfc+0x122)<40)return;
    if(!*(unsigned char*)(data_ov031_02250bfc+0x123)) {
     System_ResolveGlobalGroupEntry(9);
     *(signed char*)(data_ov031_02250bfc+0x11e)=-1;
     return;
    } else {
     *(unsigned char*)(data_ov031_02250bfc+0x11c)=0x80;
     *(unsigned char*)(data_ov031_02250bfc+0x122)-=7;
     return;
    }
   }
  }
  unsigned short* lastOrigin=data_ov031_022489dc[0];
  for(int i=0;i<2;i++,lastOrigin+=2) {
   BuildHalfwordRectangleFromOriginAndSize(lastOrigin,data_ov031_022489c4,rect.v);
   if(System_IsActiveInputPointWithinRectangle(&rect)) {
    if(*(signed char*)(data_ov031_02250bfc+0x11e)!=i+51) goto fail;
    func_ov031_02224a20(i+51);goto done;
   }
  }
 }
 fail: func_ov031_02224a20(-1);
 done: *(unsigned char*)(data_ov031_02250bfc+0x122)=0;
}
