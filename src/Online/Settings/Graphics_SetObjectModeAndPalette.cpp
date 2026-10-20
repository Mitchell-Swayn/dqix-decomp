#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct Entry { unsigned flags; unsigned short attributes; unsigned short pad; };
struct Object { char pad[8]; Entry* entries; unsigned char count; };
// Original: arm9/ov031 @ 0x0223BB58; symbol: func_ov031_0223bb58; size: 0x80.
extern "C" void Graphics_SetObjectModeAndPalette(Object* p,int index,int mode,int palette) {
Entry* entries=p->entries;
if(index>=0) {
entries[index].flags=(entries[index].flags&~0xc00)|(mode<<10);
entries[index].attributes=(entries[index].attributes&~0xf000)|(palette<<12);
} else {
int i=0; if(i<p->count) do {
entries[i].flags=(entries[i].flags&~0xc00)|(mode<<10);
entries[i].attributes=(entries[i].attributes&~0xf000)|(palette<<12);
++i; } while(i<p->count);
}
}
