#pragma opt_propagation off
#pragma opt_arithtransformation off
#include <globaldefs.h>
struct Buffer {unsigned int a,b;char* data;};
inline unsigned int RelativeIndex(const char* value,const char* base) {return value-base;}
// Original: arm9/main @ 0x02079840; symbol: func_02079840; size: 0x30.
extern "C" ARM char* ResolveRelativeDataOffsetOrFallback(Buffer* self,char* offset,char* fallback) {
 bool absent=true;unsigned int index=RelativeIndex(offset,0);
 if(index!=0xffffffff && self->data)absent=false;
 if(!absent)fallback=self->data+index;
 return fallback;
}
