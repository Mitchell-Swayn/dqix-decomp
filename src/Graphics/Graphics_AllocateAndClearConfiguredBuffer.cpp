#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
extern "C" {
    extern const unsigned int data_020e7b98[][4];
// Original: arm9/main @ 0x0204B12C; symbol: func_0204b12c; size: 0x48.
    void Graphics_AllocateAndClearConfiguredBuffer(char *p,SafeAllocator *alloc){
        if(!alloc)return;
        unsigned int size=data_020e7b98[(unsigned char)p[31]][*(int *)(p+24)];
        void *out=alloc->Allocate(size);
        *(void **)(p+20)=out;
        memset(out,0,size);
    }
}
