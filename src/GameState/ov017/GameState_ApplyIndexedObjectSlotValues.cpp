#include <globaldefs.h>
ARM
struct IndexTable { short v[8]; };
struct ByteTable { signed char v[8]; };
extern "C" IndexTable data_ov017_021d619e;
extern "C" ByteTable data_ov017_021d6186;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" void Graphics_SetNestedModelPolygonIDIfAvailable(void*,int);
// Original: arm9/ov017 @ 0x02192400; symbol: func_ov017_02192400; size: 0x148.
extern "C" void GameState_ApplyIndexedObjectSlotValues(char* self,int index) {
 int valid;
 if(index>=0 && index<=3) valid=1; else valid=0;
 if(valid) {
  void* state=_ZN9GameState11GetInstanceEv();
  signed char* record;
  IndexTable ids=data_ov017_021d619e;
  ids.v[0]=index;
  ids.v[1]=index*12+0x13;
  ids.v[2]=index*12+0x14;
  ids.v[3]=index*12+0x15;
  ids.v[4]=index*12+0x1b;
  ids.v[5]=index*12+0x1c;
  ids.v[6]=index*12+0x1d;
  record=(signed char*)(self+0x445c+index*11);
  ByteTable bytes=data_ov017_021d6186;
  bytes.v[0]=record[0]; bytes.v[1]=record[1]; bytes.v[2]=record[2]; bytes.v[3]=record[3]; bytes.v[4]=record[7]; bytes.v[5]=record[8]; bytes.v[6]=record[9];
  for(int i=0;ids.v[i]>-1;i++) {
   void* object=_ZN9GameState20GetGameObjectByIndexEi(state,ids.v[i]);
   if(object && bytes.v[i]>=0) Graphics_SetNestedModelPolygonIDIfAvailable(object,bytes.v[i]);
  }
 }
}
