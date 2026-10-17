#include <globaldefs.h>
extern "C" int ReadIndexedSixteenByteTableWord14(void); extern "C" int ReadGlobalAt02110370(void);
extern "C" void PrepareRangeAndFinalizeOperation(void); extern "C" int Filesystem_AllocateReadAndFlushFileBuffer(int,int,int,int,int);
extern "C" void SetSixteenByteRecordWordField14(int,int);
ARM
// Original: arm9/main @ 0x020BE280; symbol: func_020be280; size: 0x6C.
extern "C" int ResourceManager_GetOrCreateSecondaryCachedValue(int p1, int p2, int flags) {
    int result=ReadIndexedSixteenByteTableWord14();
    if (result == 0) {
        int extra=(flags == 0) ? 0 : ReadGlobalAt02110370();
        result=Filesystem_AllocateReadAndFlushFileBuffer(p1,(int)&PrepareRangeAndFinalizeOperation,extra,p1,p2);
        if (flags != 0 && result != 0) SetSixteenByteRecordWordField14(p1,result);
    }
    return result;
}
