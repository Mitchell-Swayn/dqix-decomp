#include <globaldefs.h>
#include <std_library_functions.h>
struct Object {char pad[0x4c];void* a;void* b;unsigned char* start;unsigned char* cursor;unsigned unused;void* data;};
extern "C" void Text_ProcessBufferedHalfwordCodesAndResetCounters(Object*);
extern "C" void ResetTextParserCountersAndProcessSource(Object*);
extern "C" void TextLayout_WrapEncodedTextToPixelWidth(Object*,unsigned,void*,void*,unsigned,unsigned,unsigned,unsigned);
extern "C" unsigned String_CountBytesUntilTerminator(const void*);
// Original: arm9/main @ 0x0206B224; symbol: func_0206b224; size: 0xA4.
extern "C" void TextStream_AdvanceSegmentAndRebuildBuffers(Object* p) {Text_ProcessBufferedHalfwordCodesAndResetCounters(p);memset(p->a,0,0x280);memset(p->b,0,0x280);int skip=1;if(p->cursor[1]==0xff)skip=2;unsigned char* next=p->cursor+skip;p->start=next;p->cursor=next;ResetTextParserCountersAndProcessSource(p);TextLayout_WrapEncodedTextToPixelWidth(p,1,p->b,p->data,0xe3,0,1,1);unsigned size=String_CountBytesUntilTerminator(p->data);memcpy(p->b,p->data,size);}
