#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x217101c; symbol: data_ov004_0217101c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
struct Flags {unsigned char low:6;unsigned char bit6:1;unsigned char bit7:1;};extern "C" {extern char* FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage;void MotionRecord_SetSelectionParameterAndRefreshByKey(void*,int,unsigned short,int);void MenuTextCanvas_RedrawByKey(void*,unsigned short);}
// Original: arm9/ov004 @ 0x02166608; symbol: ApplyPackedFlagModesToTwoEntries; size: 0x7c.
// Applies two mode values derived from packed flag bits6 and7 to entries AA and A0.
extern "C" void QuestMenu_RefreshCategoryAndSortIndicators(void* self) {char* p=FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage;MotionRecord_SetSelectionParameterAndRefreshByKey(self,0xaa,(unsigned short)(((Flags*)(p+0x50))->bit6+1),15);MenuTextCanvas_RedrawByKey(self,0x15);MotionRecord_SetSelectionParameterAndRefreshByKey(self,0xa0,(unsigned short)(((Flags*)(p+0x50))->bit7+3),15);MenuTextCanvas_RedrawByKey(self,0x16);}
