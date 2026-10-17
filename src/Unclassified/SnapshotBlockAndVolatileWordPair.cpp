#include <globaldefs.h>
extern "C" {
    struct Block{
        unsigned int words[10];
    };
// Original: arm9/main @ 0x0207DF50; symbol: func_0207df50; size: 0x40.
    void SnapshotBlockAndVolatileWordPair(char *p){
        *(Block *)(p+40)=*(Block *)p;
        int a=*(volatile int *)(p+88);
        int b=*(volatile int *)(p+92);*(volatile int *)(p+96)=a;*(volatile int *)(p+100)=b;
    }
}
