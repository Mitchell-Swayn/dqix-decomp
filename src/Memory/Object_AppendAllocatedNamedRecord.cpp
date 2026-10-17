#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
extern "C" {
    struct R{
        int id;
        char *name;
        int extra[7];
    };
// Original: arm9/main @ 0x020277F4; symbol: func_020277f4; size: 0x84.
    void Object_AppendAllocatedNamedRecord(unsigned char *p,int id,const char *name,SafeAllocator *alloc){
        int count=*(int *)(p+36);
        if(*(int *)(p+40)<=count)return;
        (*(R **)(p+32))[count].id=id;
        unsigned int len=strlen(name);
        char *copy=(char *)alloc->Allocate(len+1);
        (*(R **)(p+32))[*(int *)(p+36)].name=copy;
        strcpy((*(R **)(p+32))[*(int *)(p+36)].name,name);
        (*(int *)(p+36))++;
    }
}
