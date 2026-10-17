#pragma optimize_for_size off
#include <globaldefs.h>
ARM
extern "C" unsigned ReadBoundedSixteenByteRecordWordField10(unsigned); extern "C" void* ResourceAllocator_AllocateTrackedAlignedBlock(void*,unsigned,unsigned,unsigned,unsigned); extern "C" unsigned Filesystem_ReadIndexedResourceRangeInChunks(unsigned,void*,unsigned,unsigned); extern "C" void _Z15CleanCacheRangePKvj(const void*,unsigned);
// Original: arm9/main @ 0x020BE09C; symbol: func_020be09c; size: 0xA0.
extern "C" void* Filesystem_AllocateReadAndFlushFileBuffer(unsigned file,unsigned a,unsigned b,unsigned c,void* allocator) { unsigned length=ReadBoundedSixteenByteRecordWordField10(file); if(!length) return 0; if(!allocator) return 0; void* buffer=ResourceAllocator_AllocateTrackedAlignedBlock(allocator,length+32,a,b,c); if(!buffer) return 0; if(length!=Filesystem_ReadIndexedResourceRangeInChunks(file,buffer,length,0)) return 0; _Z15CleanCacheRangePKvj(buffer,length); return buffer; }
