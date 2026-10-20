#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
extern "C" {
// Original data: arm9/main @ 0x20e7b98; symbol: data_020e7b98.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0008000000100000001000000020000000020000000800000020000000800000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern const unsigned int GraphicsClearScreenBuffer_UnknownRoleInitializedBytes[][4];
// Original: arm9/main @ 0x0204B12C; symbol: func_0204b12c; size: 0x48.
    void Graphics_AllocateAndClearConfiguredBuffer(char *p,SafeAllocator *alloc){
        if(!alloc)return;
        unsigned int size=GraphicsClearScreenBuffer_UnknownRoleInitializedBytes[(unsigned char)p[31]][*(int *)(p+24)];
        void *out=alloc->Allocate(size);
        *(void **)(p+20)=out;
        memset(out,0,size);
    }
}
