#include <globaldefs.h>
ARM
extern "C" unsigned int ResourceStringTable_GetTextByKey(void *);
// Original: arm9/ov000 @ 0x0216FCFC; symbol: func_ov000_0216fcfc; size: 0x10.
extern "C" unsigned int BattleScene_FindResourceTextByKey(void *p) { return ResourceStringTable_GetTextByKey((unsigned char *)p + 0x88); }
