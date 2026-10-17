#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
extern "C" {
    void Object_InitializeSixteenDisplayRecordsAndFlags(void *);
// Original: arm9/main @ 0x020939AC; symbol: func_020939ac; size: 0x30.
    void BackgroundLoader_RemoveStoredTaskAtOffset340(unsigned char *p){
        BackgroundLoader *loader=BackgroundLoader::GetInstance();
        int id=*(int *)(p+832);
        if(id>=0){
            loader->RemoveTask(id);
            *(int *)(p+832)=-1;
        }Object_InitializeSixteenDisplayRecordsAndFlags(p);
    }
}
