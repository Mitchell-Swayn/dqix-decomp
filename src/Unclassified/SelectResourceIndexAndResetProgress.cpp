#include <globaldefs.h>
extern "C" {
    unsigned char *Object_GetValidSixtyByteEntry(unsigned int,int);
    unsigned char *GetTwentyByteEntryByBoundedIndex(void *,int);
    extern int data_02114e50;
// Original: arm9/main @ 0x0203F138; symbol: func_0203f138; size: 0x90.
    void SelectResourceIndexAndResetProgress(unsigned char *p,int i){
        if(*(short *)(p+40)<0)return;
        unsigned char *q=Object_GetValidSixtyByteEntry(*(unsigned int *)p,*(short *)(p+40));
        if(!q||!*(unsigned int *)(q+40))return;
        if(i<0||*(unsigned int *)(q+40)<=(unsigned int)i)return;
        if(*(int *)(p+48)==i)return;
        unsigned char *entry=GetTwentyByteEntryByBoundedIndex(q+16,i);
        if(!entry)return;
        *(int *)(p+52)=0;
        *(int *)(p+48)=i;
        *(int *)(p+56)=data_02114e50;
        *(int *)(p+60)=(*(int **)(entry+12))[*(int *)(p+52)];
    }
}
