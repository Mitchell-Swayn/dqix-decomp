#include <globaldefs.h>
ARM
extern "C" unsigned int ResolveIndexedRecordAndReturnSecondWord(void *);
// Original: arm9/ov000 @ 0x0216FCFC; symbol: func_ov000_0216fcfc; size: 0x10.
extern "C" unsigned int func_ov000_0216fcfc(void *p) { return ResolveIndexedRecordAndReturnSecondWord((unsigned char *)p + 0x88); }
