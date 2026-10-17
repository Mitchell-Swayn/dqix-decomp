#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
struct Header { unsigned short a,b; unsigned char c,d; unsigned short e; unsigned length; void* data; };
// Original: arm9/main @ 0x0204ACDC; symbol: func_0204acdc; size: 0xAC.
extern "C" int AllocateAndCopySerializedPayload(Header* self,unsigned ignored,const char* input,SafeAllocator* allocator) { unsigned header; memcpy(&header,input,4); memcpy(&self->a,input+4,2); memcpy(&self->b,input+6,2); memcpy(&self->c,input+8,1); memcpy(&self->d,input+9,1); memcpy(&self->e,input+10,2); memcpy(&self->length,input+12,4); self->data=allocator->Allocate(self->length); memcpy(self->data,input+16,self->length); return 0; }
