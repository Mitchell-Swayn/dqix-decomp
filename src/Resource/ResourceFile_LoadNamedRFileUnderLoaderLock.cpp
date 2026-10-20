#include <globaldefs.h>
#include <std_library_functions.h>
#include "World/Zone3DContainers.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/BackgroundLoader.h"
extern "C" void __clear(void*,unsigned);
extern "C" char ResourceFile_LoadNamedRFileUnderLoaderLock_FormatDataAniS[];
extern "C" void* Text_GetSharedResourceScratchBuffer();
extern "C" void ZoneContainerRenderPart_LoadSerializedFramesAndAnimations(ZoneContainerRenderPart*,void*,unsigned);
// Original: arm9/main @ 0x02047A78; symbol: func_02047a78; size: 0xB8.
extern "C" ARM void ResourceFile_LoadNamedRFileUnderLoaderLock(ZoneContainerRenderPart* p,char* name,unsigned flags)
{
    char path[128];
    if(name)
    {
        if(p->flag0)
        {
            if(p->flag0)p->Reset();
            p->flag0=0;
        }unsigned size=strlen(name);
        if((name+size)[-1]=='r')
        {
            __clear(path,128);
            sprintf(path,ResourceFile_LoadNamedRFileUnderLoaderLock_FormatDataAniS,name);
            void* buffer=Text_GetSharedResourceScratchBuffer();
            BackgroundLoader::AddLockGlobal();
            if(LoadFileIntoMemory(path,buffer,0))ZoneContainerRenderPart_LoadSerializedFramesAndAnimations(p,buffer,flags);
            BackgroundLoader::RemoveLockGlobal();
        }
    }
}
