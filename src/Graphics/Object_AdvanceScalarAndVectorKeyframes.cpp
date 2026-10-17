#include <globaldefs.h>
ARM
extern "C" int Object_ReadOptionalResourceWordC(char*);
struct Key {unsigned time;float x,y,z;};
extern "C" Key** _ZN19SignedAllocatorList13GetNthElementEj(void*,unsigned);
extern "C" float Point_ComputeFloatingPointSlope(Key**,Key**);
// Original: arm9/main @ 0x02055CCC; symbol: func_02055ccc; size: 0x204.
extern "C" void Object_AdvanceScalarAndVectorKeyframes(char* self) {
 unsigned char* config=(unsigned char*)Object_ReadOptionalResourceWordC(*(char**)(self+0x30));
 for(int i=0;i<3;i++) {
  unsigned entries=(config+0x10)[i];
  if(entries<=1)continue;
  if((int)entries<=*(unsigned short*)(self+i*2+0xbc))continue;
  Key** prev=_ZN19SignedAllocatorList13GetNthElementEj(*(char**)(self+0x30)+0x80+i*12,*(unsigned short*)(self+i*2+0xbc));
  if(!prev || (*prev)->time>=*(unsigned*)(self+4))continue;
  ++((unsigned short*)(self+0xbc))[i];
  if(*(unsigned short*)(self+0xbc+i*2)>=(config+0x10)[i]) {*(int*)(self+0xa4+i*4)=0;continue;}
  Key** next=_ZN19SignedAllocatorList13GetNthElementEj(*(char**)(self+0x30)+0x80+i*12,*(unsigned short*)(self+i*2+0xbc));
  if(next)*(float*)(self+0xa4+i*4)=Point_ComputeFloatingPointSlope(prev,next);
 }
 if(config[0x13]<=1||config[0x13]<=*(unsigned short*)(self+0xc2))return;
 Key** prev=_ZN19SignedAllocatorList13GetNthElementEj(*(char**)(self+0x30)+0xa4,*(unsigned short*)(self+0xc2));
 if(!prev || (*prev)->time>=*(unsigned*)(self+4))return;
 ++*(unsigned short*)(self+0xc2);
 if(*(unsigned short*)(self+0xc2)>=config[0x13]) {
  *(int*)(self+0xb8)=0;*(int*)(self+0xb4)=0;*(int*)(self+0xb0)=0;return;
 }
 Key** next=_ZN19SignedAllocatorList13GetNthElementEj(*(char**)(self+0x30)+0xa4,*(unsigned short*)(self+0xc2));
 if(!next)return;
 {Key* a=*prev;Key* b=*next;
 *(float*)(self+0xb0)=(b->x-a->x)/(float)(int)(b->time-a->time);}
 {Key* a=*prev;Key* b=*next;
 *(float*)(self+0xb4)=(b->y-a->y)/(float)(int)(b->time-a->time);}
 {Key* a=*prev;Key* b=*next;
 *(float*)(self+0xb8)=(b->z-a->z)/(float)(int)(b->time-a->time);}
}
