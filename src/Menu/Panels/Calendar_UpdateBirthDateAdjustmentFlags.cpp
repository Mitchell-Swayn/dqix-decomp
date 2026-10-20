#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int Calendar_ComputeAgeFromBirthDate(int,int,int);
struct MonthDays { int values[12]; };
// Original data: arm9/ov023 @ 0x21fd72c; symbol: data_ov023_021fd72c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1f0000001c0000001f0000001e0000001f0000001e0000001f0000001f0000001e0000001f0000001e0000001f000000.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" MonthDays CalendarUpdateBirthDateAdjustmentFlags_UnknownRoleInitializedBytes;
// Original: arm9/ov023 @ 0x021E61F4; symbol: func_ov023_021e61f4; size: 0x184.
extern "C" void Calendar_UpdateBirthDateAdjustmentFlags(unsigned char* self) {
 MonthDays days=CalendarUpdateBirthDateAdjustmentFlags_UnknownRoleInitializedBytes;
 self[0x13ab]=0;
 _ZN9GameState11GetInstanceEv();
 int age=Calendar_ComputeAgeFromBirthDate(*(unsigned short*)(self+0x13fc),self[0x13fe],self[0x13ff]);
 if(age<130) self[0x13ab]|=2;
 if(age>0) self[0x13ab]|=1;
 if((unsigned)self[0x13fe]<12) {
  if(Calendar_ComputeAgeFromBirthDate(*(unsigned short*)(self+0x13fc),self[0x13fe]+1,self[0x13ff])>=0) self[0x13ab]|=4;
 }
 if((unsigned)self[0x13fe]>1) {
  if(Calendar_ComputeAgeFromBirthDate(*(unsigned short*)(self+0x13fc),self[0x13fe]-1,self[0x13ff])<=130) self[0x13ab]|=8;
 }
 int year=*(unsigned short*)(self+0x13fc);
 if(year%4==0) days.values[1]=29;
 if(self[0x13ff]<days.values[self[0x13fe]-1]) {
  if(Calendar_ComputeAgeFromBirthDate(year,self[0x13fe],self[0x13ff]+1)>=0) self[0x13ab]|=0x10;
 }
 if((unsigned)self[0x13ff]>1) {
  if(Calendar_ComputeAgeFromBirthDate(*(unsigned short*)(self+0x13fc),self[0x13fe],self[0x13ff]-1)<=130) self[0x13ab]|=0x20;
 }
}
