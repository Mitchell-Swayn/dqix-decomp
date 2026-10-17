#pragma optimization_level 4
#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <Filesystem/BackgroundLoader.h>
#include <std_library_functions.h>
extern "C" {
    extern char data_020f1474[];
// Original: arm9/main @ 0x02095E90; symbol: func_02095e90; size: 0x50.
    bool Memory_AllocateCleared408ByteBufferAndQueueFile(unsigned char *p,SafeAllocator *alloc){
        void *data=alloc->Allocate(408);
        *(void **)(p+168)=data;
        if(!data)return false;
        memset(data,0,408);
        *(int *)(p+0x4c4)=BackgroundLoader::GetInstance()->QueueLoadFile(data_020f1474,0);
        return true;
    }
}
