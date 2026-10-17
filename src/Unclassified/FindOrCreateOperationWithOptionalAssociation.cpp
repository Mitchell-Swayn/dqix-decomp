#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int ReadIndexedSixteenByteTableWord14(void);
extern "C" int ReadGlobalAt02110370(void);
extern "C" int Filesystem_AllocateReadAndFlushFileBuffer(void *, void *, void *, void *, void *);
extern "C" void SetSixteenByteRecordWordField14(void *, int);
extern "C" void InitializeObjectAndDispatchRelativeDataPointer(void);
// Original: arm9/main @ 0x020BE1A8; symbol: func_020be1a8; size: 0x6C.
extern "C" int FindOrCreateOperationWithOptionalAssociation(void *param1, void *param2, int param3) {
    int result = ReadIndexedSixteenByteTableWord14();
    if (result == 0) {
        int secondary = param3 != 0 ? ReadGlobalAt02110370() : 0;
        result = Filesystem_AllocateReadAndFlushFileBuffer(param1, (void *)InitializeObjectAndDispatchRelativeDataPointer, (void *)secondary, param1, param2);
        if (param3 != 0 && result != 0) SetSixteenByteRecordWordField14(param1, result);
    }
    return result;
}
