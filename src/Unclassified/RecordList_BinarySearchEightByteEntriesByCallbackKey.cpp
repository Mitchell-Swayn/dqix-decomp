#include <globaldefs.h>
typedef int (*RecordValueProc)(int);
// Original: arm9/main @ 0x020E0310; symbol: func_020e0310; size: 0x7C.
extern "C" int RecordList_BinarySearchEightByteEntriesByCallbackKey(unsigned int* list, int key, RecordValueProc getValue) {
    unsigned int base=list[1];
    if (base==0 || getValue==0) return 0;
    int raw=(int)list[0];
    unsigned int count=(unsigned int)(raw<<20)>>20;
    if (count==0) return 0;
    int low=0;
    int high=(int)count-1;
    while (low<=high) {
        int middle=low+((high-low+1)>>1);
        int record=(int)base+middle*8;
        int value=getValue(record);
        if (value==key) return record;
        if (value>key) high=middle-1;
        else low=middle+1;
    }
    return 0;
}
