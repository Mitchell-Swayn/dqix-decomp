#include <globaldefs.h>
ARM

extern "C" int ReadScriptParameterAsInteger(void *parameter);
extern "C" char *GetBounded1416ByteRecord(int index);
extern "C" void Memory_AllocateAndInitializePoolNode(void *record, int first, int second);

// Original: arm9/ov001 @ 0x0215C5B4; symbol: func_ov001_0215c5b4; size: 0x48.
extern "C" int Unclassified_ApplyScriptParametersToBoundedRecord(void *parameters) {
    char *record = GetBounded1416ByteRecord(ReadScriptParameterAsInteger(parameters));
    if (record == 0) {
        return 0;
    }
    int first = ReadScriptParameterAsInteger((char *)parameters + 8);
    int second = ReadScriptParameterAsInteger((char *)parameters + 0x10);
    Memory_AllocateAndInitializePoolNode(record, first, second);
    return 1;
}
