#include <globaldefs.h>
#include <System/Memory.h>
ARM
struct Buffer {char* start;char* current;char* end;unsigned size;};
typedef void* (*Allocate)(const void*,unsigned);typedef void (*Release)(const void*,void*,unsigned);
extern "C" {extern char data_ov031_02249f14[];extern char data_ov031_02249f00[];}
// Original: arm9/ov031 @ 0x0221883C; symbol: func_ov031_0221883c; size: 0xA8.
extern "C" int GrowBufferAndPreserveCursor(char* owner,Buffer* buffer,int extra){
Release release=*(Release*)(owner+0x1014);Allocate allocate=*(Allocate*)(owner+0x1010);
if(extra<=0)return 0;
char* next=(char*)allocate(data_ov031_02249f14,buffer->size+extra);
if(!next)return 0;
MI_CpuCopy8(buffer->start,next,buffer->size);
release(data_ov031_02249f00,buffer->start,0);
if(!next)return 0;
buffer->current=buffer->current+(next-buffer->start);
buffer->size+=extra;buffer->start=next;buffer->end=next+buffer->size;return 1;
}
