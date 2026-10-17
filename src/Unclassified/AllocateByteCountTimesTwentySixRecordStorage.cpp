#include <globaldefs.h>
#include <Resource/GameResources.h>
#include <Memory/SafeAllocator.h>
// Original: arm9/main @ 0x02026B0C; symbol: func_02026b0c; size: 0x30.
extern "C" void AllocateByteCountTimesTwentySixRecordStorage(void* object, int value) {
    GameResources* resources=GameResources_GetInstance();
    *(unsigned char*)((char*)object+0x77a)=value;
    void* memory=((SafeAllocator*)((char*)resources+0x128))->Allocate((unsigned int)(value&0xff)*0x1a);
    *(void**)((char*)object+0x77c)=memory;
}
