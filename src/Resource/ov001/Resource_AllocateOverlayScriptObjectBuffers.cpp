#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" {extern void* data_ov001_02165880[];char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);void func_ov001_0215a79c();void Graphics_InitializeAndCopyDisplayRecords();}
// Original: arm9/ov001 @ 0x0215A850; symbol: func_ov001_0215a850; size: 0x8C.
extern "C" void Resource_AllocateOverlayScriptObjectBuffers(unsigned allocator){
data_ov001_02165880[2]=_ZN13SafeAllocator8AllocateEj(allocator,0x260);
data_ov001_02165880[9]=_ZN13SafeAllocator8AllocateEj(allocator,0xa28);
data_ov001_02165880[8]=_ZN13SafeAllocator8AllocateEj(allocator,0x700);
data_ov001_02165880[7]=_ZN13SafeAllocator8AllocateEj(allocator,0x84c0);
void* table=_ZN13SafeAllocator8AllocateEj(allocator,0x200);data_ov001_02165880[1]=table;memset(table,0,0x200);
func_ov001_0215a79c();Graphics_InitializeAndCopyDisplayRecords();
}
