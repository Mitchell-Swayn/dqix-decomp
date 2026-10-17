#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" unsigned char* Object_FindHalfwordKeyInThirtyTwoByteEntries(unsigned char*,int);
struct Descriptor { unsigned short key; short pad,first,second,third; unsigned short count0:4,count1:4,count2:4,other:4; int GetCount0(){return count0;} int GetCount1(){return count1;} int GetCount2(){return count2;} };
struct Owner { unsigned char* table; short** ids; unsigned char** counts; unsigned short* lengths; Descriptor* descriptor; short index0,index1,index2; signed char category0,category1,category2; };
// Original: arm9/ov006 @ 0x021537D0; symbol: func_ov006_021537d0; size: 0x2A8.
extern "C" int Resource_ResolveThreeRequiredEntries(Owner* self,int key) {
 if(!self->lengths) return 0;
 self->descriptor=(Descriptor*)Object_FindHalfwordKeyInThirtyTwoByteEntries(self->table,key);
 if(!self->descriptor) return 0;
 if(self->descriptor->first>0 && self->descriptor->count0) {
 self->index0=-1;
 self->category0=-1;
 for(signed char category=0;category<9;category++) {
 short* entries=self->ids[category];
 unsigned short length=self->lengths[category];
 for(unsigned short i=0;i<length;i++) {
 if(self->descriptor->first==entries[i]) {
 self->index0=i;
 self->category0=category;
 break;
 }
 }
 }
 if(self->index0<0) return 0;
 if(self->counts[self->category0][self->index0]<self->descriptor->GetCount0()) return 0;
 }
 if(self->descriptor->second>0 && self->descriptor->count1) {
 self->index1=-1;
 self->category1=-1;
 for(signed char category=0;category<9;category++) {
 short* entries=self->ids[category];
 unsigned short length=self->lengths[category];
 for(unsigned short i=0;i<length;i++) {
 if(self->descriptor->second==entries[i]) {
 self->index1=i;
 self->category1=category;
 break;
 }
 }
 }
 if(self->index1<0) return 0;
 if(self->counts[self->category1][self->index1]<self->descriptor->GetCount1()) return 0;
 }
 if(self->descriptor->third>0 && self->descriptor->count2) {
 self->index2=-1;
 self->category2=-1;
 for(signed char category=0;category<9;category++) {
 short* entries=self->ids[category];
 unsigned short length=self->lengths[category];
 for(unsigned short i=0;i<length;i++) {
 if(self->descriptor->third==entries[i]) {
 self->index2=i;
 self->category2=category;
 break;
 }
 }
 }
 if(self->index2<0) return 0;
 if(self->counts[self->category2][self->index2]<self->descriptor->GetCount2()) return 0;
 }
 return 1;
}
