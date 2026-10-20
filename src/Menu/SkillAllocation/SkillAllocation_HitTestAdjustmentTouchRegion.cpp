struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
struct Owner; struct Record;
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
extern "C" int TouchInput_IsSampleInsideRectangle(char*,int,int,int,int);
extern "C" void TextCanvas_GetMarkedTextRectangle(unsigned char*,int,short*,short*,short*,short*);
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
// Original: arm9/ov013 @ 0x021842A0; symbol: func_ov013_021842a0; size: 0x98.
extern "C" int SkillAllocation_HitTestAdjustmentTouchRegion(Owner* owner,int index) {
 if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x5c]) {
  unsigned char* record=(unsigned char*)(Record*)Window_FindActiveCanvasById((WindowCanvasOwner*)(owner),0);
  if(record) {
   short x=*(short*)(record+0xac),y=*(short*)(record+0xae);
   short a,b,c,d;
   TextCanvas_GetMarkedTextRectangle(record,(short)index,&a,&b,&c,&d);
   return TouchInput_IsSampleInsideRectangle((char*)Main_UnknownRoleZeroInitializedStorage_Variant4,a+(short)(x*8),b+(short)(y*8),c,d);
  }
 }
 return 0;
}
