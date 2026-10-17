#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
struct Array { int count; void* data; };
// Original: arm9/main @ 0x02048090; symbol: func_02048090; size: 0x28.
extern "C" ARM void AllocateThirtyByteRecordArray(Array* array, int count, SafeAllocator* allocator) {
 array->count=count;
 unsigned int bytes=array->count * 30;
 array->data=allocator->Allocate(bytes);
}
