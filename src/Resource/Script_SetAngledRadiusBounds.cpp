#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" int _Z8fix32sini(int);
extern "C" int _Z8fix32cosi(int);
struct E;
extern "C" E* LinkedList_FindNodeByUnsignedKey(E**,unsigned int);
// Original data: arm9/main @ 0x2108cec; symbol: data_02108cec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0206C6F4; symbol: func_0206c6f4; size: 0x138.
extern "C" int Script_SetAngledRadiusBounds(unsigned char* args) {
 unsigned key=_ZNK6Script9Parameter5ToIntEv(args);
 unsigned char* p=(unsigned char*)LinkedList_FindNodeByUnsignedKey(*(E***)(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage+16),key);
 if(!p) return 0;
 while(p) {
  if(*(unsigned short*)(p+0x44)==*(unsigned short*)(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage+10)) break;
  p=*(unsigned char**)(p+0x70);
 }
 if(!p)return 0;
 p[0x1f]=8;
 *(short*)(p+0x22)=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(args+8));
 int radius=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(args+16));
 int x=(int)(((long long)radius*_Z8fix32sini(*(short*)(p+0x22))+0x800)>>12);
 int z=(int)(((long long)radius*_Z8fix32cosi(*(short*)(p+0x22))+0x800)>>12);
 *(int*)(p+0x24)=*(int*)(p+0x10)+x;
 *(int*)(p+0x28)=*(int*)(p+0x18)+z;
 *(int*)(p+0x2c)=*(int*)(p+0x10)-x;
 *(int*)(p+0x30)=*(int*)(p+0x18)-z;
 int b=*(int*)(p+0x2c),a=*(int*)(p+0x24);
 if(a<b) {*(int*)(p+0x24)=b;*(int*)(p+0x2c)=a;}
 b=*(int*)(p+0x30);a=*(int*)(p+0x28);
 if(a<b) {*(int*)(p+0x28)=b;*(int*)(p+0x30)=a;}
 return 1;
}
