#include <globaldefs.h>
ARM
struct FlagByte { unsigned char low:7; unsigned char high:1;};
// Original data: arm9/ov004 @ 0x217101c; symbol: data_ov004_0217101c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" char *FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
extern "C" int Resource_ReadIndexedNodeAndFlag(void*,int*);
extern "C" void QuestMenu_RefreshCategoryAndSortIndicators(void*);
extern "C" void QuestMenu_ClearEntryLinksAndActiveList();
extern "C" void QuestMenu_LinkEntriesInSelectedStatusOrder();
extern "C" void QuestMenu_SelectQuestRowAndRefreshHighlight(void*,int);
extern "C" void QuestMenu_PopulateVisibleQuestRows(void*);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
// Original: arm9/ov004 @ 0x02166FE4; symbol: ToggleSharedFlagAndRefreshObjectEntries; size: 0x84.
extern "C" int QuestMenu_ToggleStatusSortingAndPreserveSelection(void *self) {
 int temp;int value=Resource_ReadIndexedNodeAndFlag(self,&temp);
 FlagByte *flag=(FlagByte*)(FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage+0x50);flag->high=(unsigned char)(flag->high+1);
 QuestMenu_RefreshCategoryAndSortIndicators(self);QuestMenu_ClearEntryLinksAndActiveList();QuestMenu_LinkEntriesInSelectedStatusOrder();QuestMenu_SelectQuestRowAndRefreshHighlight(self,value);QuestMenu_PopulateVisibleQuestRows(self);
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);return 0;
}
