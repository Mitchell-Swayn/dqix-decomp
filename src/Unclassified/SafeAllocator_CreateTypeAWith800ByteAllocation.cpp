#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
#include <GameState/GameState.h>
extern "C" {
// Original: arm9/main @ 0x02092A74; symbol: func_02092a74; size: 0x30.
void SafeAllocator_CreateTypeAWith800ByteAllocation(SafeAllocator *p,SafeAllocator *a){if(a==0)return;void *data=a->Allocate(0x800);p->CreateTypeA(data,0x800);}
}
