#include <globaldefs.h>
ARM
extern "C" int TileGrid_GetSelectedCellHandleByKey(void*,int);
extern "C" void QuestMenu_ClearEntryLinksAndActiveList();
extern "C" void QuestMenu_LinkEntriesInSelectedStatusOrder();
extern "C" void Filesystem_QueuePositionRecord(void*);
extern "C" void Menu_QueueScriptEntry(void*,unsigned);
// Original data: arm9/ov004 @ 0x217101c; symbol: data_ov004_0217101c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" char* FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov004 @ 0x02166B40; symbol: SelectSharedRecordModeAndDispatchRefreshEvent; size: 0x98.
extern "C" int QuestMenu_SelectCategoryAndRebuildGrid(void* self) {
 char* state=FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage;int kind=TileGrid_GetSelectedCellHandleByKey(self,90);int value;
 switch(kind){case 180:goto normal;case 181:*(unsigned char*)(state+80)|=192;value=*(short*)(state+74);break;default:normal: {*(unsigned char*)(state+80)&=~64;*(unsigned char*)(state+80)|=128;value=*(short*)(state+72);}break;}
 if(value){QuestMenu_ClearEntryLinksAndActiveList();QuestMenu_LinkEntriesInSelectedStatusOrder();Filesystem_QueuePositionRecord(self);Menu_QueueScriptEntry(self,301);}else Menu_QueueScriptEntry(self,102);return 0;
}
