#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
// Original: arm9/main @ 0x020545B8; symbol: func_020545b8; size: 0xAC.
extern "C" ARM void Memory_DestroyFourteenEmbeddedAllocators(char* self) {
 for (int i=0;i<10;i++) { if (((SafeAllocator*)(self+4+i*0x14))->GetSignedAllocator()) ((SafeAllocator*)(self+4+i*0x14))->Destroy(); }
 SafeAllocator* list[4]={(SafeAllocator*)(self+0x52c),(SafeAllocator*)(self+0x540),(SafeAllocator*)(self+0x554),(SafeAllocator*)(self+0x5d8)};
 for(int i=0;i<4;i++) {SafeAllocator* a=list[i];if(a->GetSignedAllocator()) a->Destroy();}
}
