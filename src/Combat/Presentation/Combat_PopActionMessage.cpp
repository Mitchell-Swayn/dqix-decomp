#include <globaldefs.h>
ARM
struct Table {unsigned short ids[16];short a[16],b[16],c[16];unsigned short d[16];unsigned char e[16];unsigned f[16];char pad[0x60];unsigned char count;char pad2[11];short selected;};
// Original: arm9/ov025 @ 0x021ED1F0; symbol: func_ov025_021ed1f0; size: 0xB0.
extern "C" void Combat_PopActionMessage(Table* self) {
if(!self->count) return;
--self->count;
for(int i=0;i<self->count;++i) {
self->ids[i]=self->ids[i+1];
self->a[i]=self->a[i+1];
self->e[i]=self->e[i+1];
self->f[i]=self->f[i+1];
self->c[i]=self->c[i+1];
self->b[i]=self->b[i+1];
self->d[i]=self->d[i+1];
}
--self->selected;
if(self->selected<0) self->selected=0;
}
