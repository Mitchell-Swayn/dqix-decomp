#include <globaldefs.h>

ARM
#pragma always_inline on
extern "C" {
extern signed char data_020e8bb4[],data_020e8bb5[];
struct Flags { unsigned first:20;unsigned active:1;unsigned rest:11; };
struct Entry {signed char index,pad;};
static inline int SearchActiveEntry(unsigned char *p,const Entry *first,int i,const Entry *second) {
    int index;
    while((index=second[i].index) != -1) {
        if(*(short *)(p+0x1ac+first[i].index*32)>0 && ((Flags *)(p+0x2f4+index*44))->active)return 1;
        i++;
    }
    return 0;
}
// Original: arm9/main @ 0x020854E8; symbol: func_020854e8; size: 0x74.
int FindMappedActiveEntry(unsigned char *p) {
    return SearchActiveEntry(p,(Entry *)data_020e8bb5,0,(Entry *)data_020e8bb4);
}
}
