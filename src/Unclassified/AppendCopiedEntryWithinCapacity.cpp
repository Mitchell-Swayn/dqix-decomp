#include <globaldefs.h>
union Vector4 {unsigned words[4];};struct Entry {unsigned char a,b,c,d;unsigned value;Vector4 vec;unsigned short e,f,g;unsigned short pad;unsigned h,i,j;};struct Owner {Entry* entries;unsigned short capacity,count;};
// Original: arm9/main @ 0x020A825C; symbol: func_020a825c; size: 0xA8.
extern "C" void AppendCopiedEntryWithinCapacity(Owner* self,const Entry* input) {if(!input)return;if(self->capacity<=self->count)return;Entry* dest=self->entries+self->count;dest->a=input->a;dest->b=input->b;dest->c=input->c;dest->d=input->d;dest->value=input->value;dest->vec=input->vec;dest->e=input->e;dest->f=input->f;dest->g=input->g;dest->h=input->h;dest->i=input->i;dest->j=input->j;++self->count;}
