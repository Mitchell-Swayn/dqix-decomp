#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
extern "C" {
    void InitializeFourWordsWithInvalidIndex(void *);
    void ClearRecordAndInvalidateTwoIndices(void *);

// Original: arm9/main @ 0x020D9AE8; symbol: func_020d9ae8; size: 0x4C.
    void InitializeRecordKind4AAndEmbeddedAllocator(unsigned char *p,unsigned char i){
        InitializeFourWordsWithInvalidIndex(p);
        p[0]=74;
        p[8]=i;
        p[9]=0;
        *(int *)(p+12)=-1;
        memset(p+16,0,48);
        ClearRecordAndInvalidateTwoIndices(p+64);
        ((SafeAllocator *)(p+88))->ResetAllocatorPointer();
    }
}
