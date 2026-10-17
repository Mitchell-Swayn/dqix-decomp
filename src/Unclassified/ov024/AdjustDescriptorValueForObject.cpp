#include <globaldefs.h>
ARM
struct Descriptor { unsigned a; unsigned code:12;unsigned pad4:20; unsigned value:8;unsigned pad8:24;unsigned pad[3];unsigned low:12;unsigned kind:4;unsigned high:16; };
extern "C" int Object_AdjustValueByThreeQuartersForFlag106(int,int);
extern "C" int TestDescriptorFlag200AtOffset18(void*);
// Original: arm9/ov024 @ 0x021F87DC; symbol: func_ov024_021f87dc; size: 0x98.
extern "C" int AdjustDescriptorValueForObject(char* object,const Descriptor* desc,int* out) {
*out=desc->value;
if(desc->kind==2) {
if(object && TestDescriptorFlag200AtOffset18(object)) *out=0;
else if(desc->code==40) {
*out=20;
if(*(unsigned short*)(*(char**)(object+0x138)+2)>*out) *out=*(unsigned short*)(*(char**)(object+0x138)+2);
} else *out=Object_AdjustValueByThreeQuartersForFlag106((int)object,*out);
}
return *out;
}
