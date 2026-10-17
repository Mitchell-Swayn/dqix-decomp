#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *parameter);
extern "C" unsigned char data_ov001_021658b8[];
extern "C" void _ZN13HMRFAllocator4FreeEi(void *allocator, int freeFlag);
// Original: arm9/ov001 @ 0x02161900; symbol: func_ov001_02161900; size: 0x30.
extern "C" int Resource_FreeIndexedHMRFRecord(IntegerParameterView *parameter) {
    int index = ReadScriptParameterAsInteger(parameter);
    void *record = *(void **)(data_ov001_021658b8 + index * 4);
    if (record)
        _ZN13HMRFAllocator4FreeEi(*(void **)record, 1);
    return 1;
}
