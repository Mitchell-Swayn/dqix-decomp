#include <globaldefs.h>
ARM
#pragma optimize_for_size on
#include <std_library_functions.h>
struct PackedInfo {
    unsigned value;unsigned pad[12];unsigned other;
    unsigned a:6,b:6,c:6,d:6,e:2,f:1,g:1,h:1,rest:3;
};
extern "C" void InitializeCoordinatesAndPackedDescriptorFlags(void*,unsigned,unsigned,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned);
// Original: arm9/main @ 0x020E4E38; symbol: func_020e4e38; size: 0xE0.
extern "C" void BuildTwelveByteDescriptorFromPackedInfo(void* out,PackedInfo* p){
    memset(out,0,12);
    if(p)InitializeCoordinatesAndPackedDescriptorFlags(out,p->value,p->other,(unsigned char)p->a,(unsigned char)p->b,(unsigned char)p->c,(unsigned char)p->d,(unsigned char)p->e,(unsigned char)p->f,(unsigned char)p->g,(unsigned char)p->h,0);
}
