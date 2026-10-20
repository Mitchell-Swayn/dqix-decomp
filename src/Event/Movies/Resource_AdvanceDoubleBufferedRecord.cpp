#include <globaldefs.h>
ARM
struct Stream { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual int read(void*,unsigned); virtual void wait(); };
struct Output { unsigned word,pad[2],a[6],b[6]; };
struct State {
 Stream* stream; unsigned pad04[2],count; unsigned char pad10[14]; unsigned short stride; unsigned char pad20[20];
 Output* output; unsigned char pad38[36]; unsigned* table1; unsigned* table2; unsigned char pad64[12];
 unsigned char* buffers[2]; unsigned sizes[2],offsets[2],values[2]; int index; unsigned pad94,position; unsigned char pad9c[16]; unsigned selectors[6]; unsigned padc4,product;
};
// Original: arm9/ov016 @ 0x0218EF50; symbol: func_ov016_0218ef50; size: 0x138.
extern "C" int Resource_AdvanceDoubleBufferedRecord(State* p) {
 if(p->position==p->count)return 0;
 p->position++;
 int prev=p->index;
 p->index=(prev+1)%2;
 p->stream->wait();
 unsigned word=*(unsigned*)(p->offsets[p->index]+p->sizes[p->index]+p->buffers[p->index]);
 p->sizes[prev]=word>>14;
 p->values[prev]=word&0x3fff;
 p->output->word=(unsigned)(p->buffers[p->index]+p->offsets[p->index]);
 if(p->position<p->count) p->offsets[prev]=p->stream->read(p->buffers[prev],p->sizes[prev]+4);
 int i=0; do {
 p->output->a[i]=p->table1[p->selectors[i]];
 p->output->b[i]=p->table2[p->selectors[i]];
 } while(++i<6);
 p->product=p->stride*p->values[p->index];
 return 1;
}
