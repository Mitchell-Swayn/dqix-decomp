#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
extern "C" {
extern unsigned char data_02153694[];
extern SafeAllocator data_02153680;
extern unsigned char data_02114e20[];
void CancelOwnerTaskAndResetEmbeddedState(void *);
void Memory_FreeThroughAllocatorUnion(void *,void *);
// Original: arm9/main @ 0x020E5094; symbol: func_020e5094; size: 0x58.
void CleanupTwoResourceOwnersAndDestroyGlobalAllocator() {
    for (int i=0; i<2; i++) CancelOwnerTaskAndResetEmbeddedState(data_02153694+i*24);
    SignedAllocatorHeader *allocation = data_02153680.GetSignedAllocator();
    if (!allocation) return;
    Memory_FreeThroughAllocatorUnion(data_02114e20, allocation);
    data_02153680.Destroy();
}
}
