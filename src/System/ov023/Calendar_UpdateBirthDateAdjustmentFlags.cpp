#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int Calendar_ComputeAgeFromBirthDate(int,int,int);
struct MonthDays { int values[12]; };
extern "C" MonthDays data_ov023_021fd72c;
// Original: arm9/ov023 @ 0x021E61F4; symbol: func_ov023_021e61f4; size: 0x184.
extern "C" void Calendar_UpdateBirthDateAdjustmentFlags(unsigned char* self) {
 MonthDays days=data_ov023_021fd72c;
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
