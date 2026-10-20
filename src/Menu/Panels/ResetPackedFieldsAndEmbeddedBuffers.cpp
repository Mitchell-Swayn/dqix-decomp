#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct Owner {unsigned first:9,second:9,third:9,fourth:3,fifth:2;void* buffer;unsigned count;unsigned char records[0x38];unsigned char bytes[0x200];};
// Original: arm9/ov023 @ 0x021F222C; symbol: func_ov023_021f222c; size: 0x70.
// Clears five packed fields, list metadata and both embedded buffers, then binds the byte buffer.
extern "C" void ResetPackedFieldsAndEmbeddedBuffers(Owner* self){
 self->first=0;self->second=0;self->third=0;self->fourth=0;self->fifth=0;
 self->buffer=0;self->count=0;memset(self->records,0,0x38);memset(self->bytes,0,0x200);self->buffer=self->bytes;
}
