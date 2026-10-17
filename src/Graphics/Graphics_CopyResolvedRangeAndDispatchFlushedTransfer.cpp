#include <globaldefs.h>
#include <std_library_functions.h>
#include <System/Cache.h>
struct Format {char pad[0x1c];struct Nibbles {unsigned char low:4,high:4;} n;};
struct Object {unsigned first;Format* format;void* buffer;char padc[0x94];unsigned offset,size;char pada8[20];short x,y;char padc0[5];unsigned char flags;};
extern "C" char* Graphics_GetConfiguredBackgroundCharacterBase(Object*);
extern "C" void func_0204fa0c(Object*,int,int);
typedef void(*Transfer)(void*,unsigned,unsigned);
extern "C" Transfer ReadTwoDimensionalGlobalTableValue(unsigned,unsigned);
// Original: arm9/main @ 0x0204FFC0; symbol: func_0204ffc0; size: 0xA4.
extern "C" void Graphics_CopyResolvedRangeAndDispatchFlushedTransfer(Object* p) {if(!p->format||!p->buffer)return;unsigned low=p->format->n.low,high=p->format->n.high;char* source=Graphics_GetConfiguredBackgroundCharacterBase(p);if(!source)return;if(source)memcpy(p->buffer,source+p->offset,p->size);p->flags|=0x40;func_0204fa0c(p,p->x,p->y);Transfer transfer=ReadTwoDimensionalGlobalTableValue(low,high);CleanInvalidateCacheRange(p->buffer,p->size);transfer(p->buffer,p->offset,p->size);}
