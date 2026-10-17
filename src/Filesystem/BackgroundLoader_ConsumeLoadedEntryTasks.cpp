#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
extern "C" void ClearWordsAndHalfwordsAtOffsets8Through18(void*);
extern "C" void Graphics_InitializeBackgroundMapFromDataAndPalette(void*,void*,unsigned,int,int);
struct State
{
    unsigned char pad[32];
    char* entries;
    int count;
    unsigned char rest[72];
    int next,current;
};
// Original: arm9/main @ 0x020210F8; symbol: func_020210f8; size: 0xB8.
extern "C" ARM void BackgroundLoader_ConsumeLoadedEntryTasks(State* p,int* tasks,unsigned flags)
{
    if(tasks)
    {
        BackgroundLoader* loader=BackgroundLoader::GetInstance();
        void* data=0;
        unsigned size=0;
        p->next=p->current+1;
        for(int i=0;i<p->count;++i)
        {
            loader->GetLoadedFileByID(tasks[i],&data,&size);
            ClearWordsAndHalfwordsAtOffsets8Through18(p->entries+i*36+8);
            Graphics_InitializeBackgroundMapFromDataAndPalette(p->entries+i*36+8,data,flags,1,0);
            BackgroundLoader::GetInstance()->RemoveTask(tasks[i]);
            tasks[i]=-1;
        }
    }
}
