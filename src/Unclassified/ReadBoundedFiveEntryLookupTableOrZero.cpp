#include <globaldefs.h>
extern "C" {
    extern int data_020e88e4[];
// Original: arm9/main @ 0x02074988; symbol: func_02074988; size: 0x24.
    int ReadBoundedFiveEntryLookupTableOrZero(int i){
        if(i<0)return 0;
        if(i>4)return 0;
        return data_020e88e4[i];
    }
}
