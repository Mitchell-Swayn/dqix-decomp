#include <globaldefs.h>
ARM
struct Record {void* first;void* second;short key;unsigned short a,b;unsigned char flags,state;};
struct Owner {unsigned unknown;Record* records;short count,capacity;};
// Original: arm9/ov023 @ 0x021E1410; symbol: func_ov023_021e1410; size: 0x64.
// Copies one sixteen-byte record into the next available slot and advances the signed count.
extern "C" void AppendSixteenByteRecordWithinCapacity(Owner* self,const Record* source){
 if(self->capacity<=self->count)return;
 Record* destination=self->records+self->count;
 destination->first=source->first;destination->second=source->second;destination->key=source->key;
 destination->a=source->a;destination->b=source->b;destination->flags=source->flags;destination->state=source->state;
 self->count++;
}
