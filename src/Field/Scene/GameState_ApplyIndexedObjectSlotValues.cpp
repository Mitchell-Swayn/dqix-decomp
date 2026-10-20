#include <globaldefs.h>
ARM
struct IndexTable { short v[8]; };
struct ByteTable { signed char v[8]; };
// Original data: arm9/ov017 @ 0x21d619e; symbol: data_ov017_021d619e.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000000000000000ffff000000000000010000000300000006000000.
// Observed span: 34 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" IndexTable GameStateApplyIndexedObjectSlotValues_UnknownRoleInitializedBytes_Variant2;
// Original data: arm9/ov017 @ 0x21d6186; symbol: data_ov017_021d6186.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000000000ff.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" ByteTable GameStateApplyIndexedObjectSlotValues_UnknownRoleInitializedBytes;
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
  IndexTable ids=GameStateApplyIndexedObjectSlotValues_UnknownRoleInitializedBytes_Variant2;
  ids.v[0]=index;
  ids.v[1]=index*12+0x13;
  ids.v[2]=index*12+0x14;
  ids.v[3]=index*12+0x15;
  ids.v[4]=index*12+0x1b;
  ids.v[5]=index*12+0x1c;
  ids.v[6]=index*12+0x1d;
  record=(signed char*)(self+0x445c+index*11);
  ByteTable bytes=GameStateApplyIndexedObjectSlotValues_UnknownRoleInitializedBytes;
  bytes.v[0]=record[0]; bytes.v[1]=record[1]; bytes.v[2]=record[2]; bytes.v[3]=record[3]; bytes.v[4]=record[7]; bytes.v[5]=record[8]; bytes.v[6]=record[9];
  for(int i=0;ids.v[i]>-1;i++) {
   void* object=_ZN9GameState20GetGameObjectByIndexEi(state,ids.v[i]);
   if(object && bytes.v[i]>=0) Graphics_SetNestedModelPolygonIDIfAvailable(object,bytes.v[i]);
  }
 }
}
