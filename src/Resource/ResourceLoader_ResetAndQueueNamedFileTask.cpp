#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
extern "C" {
    void BackgroundLoader_RemoveTaskAndClearLoadedPointer(void *);
// Original: arm9/main @ 0x020DBF18; symbol: func_020dbf18; size: 0x58.
    int ResourceLoader_ResetAndQueueNamedFileTask(int *p,const char *name,int a,int b,int c){
        BackgroundLoader *loader=BackgroundLoader::GetInstance();
        BackgroundLoader_RemoveTaskAndClearLoadedPointer(p);
        p[0]=a;
        p[1]=b;
        p[2]=c;
        p[3]=loader->QueueLoadFile(name,0);
        p[4]=1;
        return 0;
    }
}
