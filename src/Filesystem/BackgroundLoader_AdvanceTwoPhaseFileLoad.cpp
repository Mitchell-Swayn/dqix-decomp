#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
extern "C" char BackgroundLoader_AdvanceTwoPhaseFileLoad_PathDataBinVrambankBin[];
extern "C" void Script_ExecuteWithArgumentPointerAndContext(void*,unsigned char,void*,unsigned);
// Original: arm9/main @ 0x02097A04; symbol: func_02097a04; size: 0xBC.
extern "C" ARM int BackgroundLoader_AdvanceTwoPhaseFileLoad(char* p)
{
    void* data;
    unsigned size;
    BackgroundLoader* loader=BackgroundLoader::GetInstance();
    if((unsigned char)p[28]==0)
    {
        *(int*)(p+24)=loader->QueueLoadFile(BackgroundLoader_AdvanceTwoPhaseFileLoad_PathDataBinVrambankBin,0);
        p[28]=(unsigned char)p[28]+1;
    }
    else if((unsigned char)p[28]==1 && loader->GetTaskStatus(*(int*)(p+24)))
    {
        loader->GetLoadedFileByID(*(int*)(p+24),&data,&size);
        if(data)Script_ExecuteWithArgumentPointerAndContext(p,(unsigned char)p[29],data,size);
        loader->RemoveTask(*(int*)(p+24));
        *(int*)(p+24)=-1;
        p[28]=0;
        return 1;
    }
    return 0;
}
