#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" {
void* memcpy(void*,const void*,unsigned);
void Graphics_SubmitTransformedCellToOam(void*,void*);
void Object_ConvertMappedKeyToTwoHalfwords(void*,int,short*,short*);
// Original data: arm9/ov006 @ 0x215ffe2; symbol: data_ov006_0215ffe2.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0b000c0006000700.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
// Original data: arm9/ov006 @ 0x215fff4; symbol: data_ov006_0215fff4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1c001d001a001b00ffff.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
extern short SubmitQuantityControlDisplayRecords_UnknownRoleInitializedBytes_Variant3[],SubmitQuantityControlDisplayRecords_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov006 @ 0x215ffc0; symbol: data_ov006_0215ffc0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 080a0c0e.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
extern volatile unsigned char SubmitQuantityControlDisplayRecords_UnknownRoleInitializedBytes[];
}
struct ControlRecord {unsigned char pad[0x14];int x,y;unsigned char pad2[6];unsigned char style;inline void Configure(short px,short py,unsigned char value){x=px<<12;y=py<<12;style=value;}};
// Original: arm9/ov006 @ 0x021587D0; symbol: func_ov006_021587d0; size: 0x144.
// Submits mapped quantity-control records, offsetting pressed increase/decrease parts.
extern "C" void SubmitQuantityControlDisplayRecords(unsigned char* self) {
 if(*(unsigned short*)(self+0x394)&8) {
  short keys[5];memcpy(keys,SubmitQuantityControlDisplayRecords_UnknownRoleInitializedBytes_Variant3,10);
  if(self[0x38f]==10) {keys[0]=31;keys[1]=32;keys[2]=33;keys[3]=34;}
  short x,y;
  for(unsigned char i=0;keys[i]>=0;++i) {
   Object_ConvertMappedKeyToTwoHalfwords(self+0x100,keys[i],&x,&y);
   short index=SubmitQuantityControlDisplayRecords_UnknownRoleInitializedBytes_Variant2[i];
   unsigned char* record=*(unsigned char**)(self+0x24)+index*40;
   if(index==11 && self[0x430]) {++x;++y;}
   if(index==12 && self[0x431]) {++x;++y;}
   ((ControlRecord*)record)->Configure(x,y,SubmitQuantityControlDisplayRecords_UnknownRoleInitializedBytes[i]);
   Graphics_SubmitTransformedCellToOam(self+0xac,record);
  }
 }
}
