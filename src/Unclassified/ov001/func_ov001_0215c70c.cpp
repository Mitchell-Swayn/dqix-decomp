#include <globaldefs.h>
ARM
extern "C" int ReadScriptParameterAsInteger(void *parameter);
extern "C" char *GetBounded1416ByteRecord(int i);
extern "C" unsigned func_ov001_0215a5f0(void);
// Original: arm9/ov001 @ 0x0215C70C; symbol: func_ov001_0215c70c; size: 0x24.
extern "C" unsigned func_ov001_0215c70c(void *parameter) {
    int index = ReadScriptParameterAsInteger(parameter);
    if (!GetBounded1416ByteRecord(index))
        return 0;
    func_ov001_0215a5f0();
    return 1;
}
