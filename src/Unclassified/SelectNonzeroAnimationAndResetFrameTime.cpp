#include <globaldefs.h>
extern "C" {
    extern int data_02114e50;
// Original: arm9/main @ 0x02076928; symbol: func_02076928; size: 0x60.
    void SelectNonzeroAnimationAndResetFrameTime(unsigned char *p,int id){
        if(!p[95])return;
        if(*(int *)(p+84)<=0)return;
        if(*(int *)(p+100)==id||id==0)return;
        *(int *)(p+96)=0;
        *(int *)(p+100)=id;
        *(int *)(p+104)=data_02114e50;
        *(int *)(p+108)=(*(int ***)(p+32))[*(int *)(p+100)][*(int *)(p+96)];
    }
}
