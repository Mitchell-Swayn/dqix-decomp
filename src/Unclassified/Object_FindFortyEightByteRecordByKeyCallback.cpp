#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    int ReadSignedHalfwordAtOffset4(void *);
    void *BinarySearchFortyEightByteRecordsUsingKeyCallback(void *,int,int (*)(void *));
// Original: arm9/main @ 0x02097224; symbol: func_02097224; size: 0x14.
    void *Object_FindFortyEightByteRecordByKeyCallback(void *p,int id){
        return BinarySearchFortyEightByteRecordsUsingKeyCallback(p,id,ReadSignedHalfwordAtOffset4);
    }
}
