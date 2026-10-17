#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" {
ARM struct Table { unsigned short count; unsigned short reserved; unsigned int* entries; };
// Original: arm9/main @ 0x020B02D0; symbol: func_020b02d0; size: 0x48.
 void RelocateTablePointerAndEntryOffsets(Table* self) { self->entries=(unsigned int*)((unsigned int)self->entries+(unsigned int)self); unsigned short i=0; if(self->count <= i) return; do { self->entries[i]=(unsigned int)((unsigned char*)self+self->entries[i]); i++; }while(self->count>i); }
}
