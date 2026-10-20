#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
extern "C" {
    void LinkedQueue_InitializeNodeStatus(void *);
    void ResourceStringLoader_Reset(void *);

// Original: arm9/main @ 0x020D9AE8; symbol: func_020d9ae8; size: 0x4C.
    void InitializeRecordKind4AAndEmbeddedAllocator(unsigned char *p,unsigned char i){
        LinkedQueue_InitializeNodeStatus(p);
        p[0]=74;
        p[8]=i;
        p[9]=0;
        *(int *)(p+12)=-1;
        memset(p+16,0,48);
        ResourceStringLoader_Reset(p+64);
        ((SafeAllocator *)(p+88))->ResetAllocatorPointer();
    }
}
