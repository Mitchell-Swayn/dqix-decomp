#include <globaldefs.h>
ARM
struct Source { int pad[2]; unsigned int enabled:1; unsigned int value:15; unsigned int fixed:1; unsigned int hasOther:1; unsigned int unused:14; unsigned int other:15; unsigned int remaining:17; };
struct Global { int pad[3]; unsigned char* object; };
extern "C" Global data_ov025_021ef988;
// Original: arm9/ov025 @ 0x021E5F54; symbol: func_ov025_021e5f54; size: 0x9C.
extern "C" int Object_ApplyPackedHalfwordSettings(Source* source) {
if(source->enabled)*(short*)(data_ov025_021ef988.object+0x21c)=source->value;
else *(short*)(data_ov025_021ef988.object+0x21c)=0;
if(source->fixed)*(short*)(data_ov025_021ef988.object+0x220)=30;
else *(short*)(data_ov025_021ef988.object+0x220)=-1;
if(source->hasOther)*(short*)(data_ov025_021ef988.object+0x222)=source->other;
else *(short*)(data_ov025_021ef988.object+0x222)=-1;
return 1;
}
