#include <globaldefs.h>
ARM
extern "C" void *GetGlobalStatePointer(void);
extern "C" void RecordFlags_ClearWordMask(unsigned int *, unsigned int);
// Original: arm9/ov004 @ 0x0216312C; symbol: func_ov004_0216312c; size: 0x18.
extern "C" int GameState_ClearGlobalRecordFlag(void) {
    RecordFlags_ClearWordMask((unsigned int *)GetGlobalStatePointer(), 1);
    return 0;
}
