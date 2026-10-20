#pragma optimization_level 4
#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <Filesystem/BackgroundLoader.h>
#include <std_library_functions.h>
extern "C" {
// Original data: arm9/main @ 0x20f1474; symbol: data_020f1474.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 646174612f7363656e6172696f2f71756573746f72646572332e62696e00646174612f7363656e6172696f2f717565737463616e63656c2e62696e00.
// Observed span: 60 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern char QuestLoadOrdersForCurrentScenario_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x02095E90; symbol: func_02095e90; size: 0x50.
    bool Memory_AllocateCleared408ByteBufferAndQueueFile(unsigned char *p,SafeAllocator *alloc){
        void *data=alloc->Allocate(408);
        *(void **)(p+168)=data;
        if(!data)return false;
        memset(data,0,408);
        *(int *)(p+0x4c4)=BackgroundLoader::GetInstance()->QueueLoadFile(QuestLoadOrdersForCurrentScenario_UnknownRoleInitializedBytes,0);
        return true;
    }
}
