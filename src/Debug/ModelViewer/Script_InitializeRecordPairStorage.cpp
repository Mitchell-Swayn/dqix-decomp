#include <globaldefs.h>
#include <Resource/Script.h>
struct Record {void* first;void* second;short value;unsigned char flag1,flag2;};struct Pair {void* first;void* second;};struct RecordArray {Record* records;Pair* pairs;int count,pairCount;};
// Original data: arm9/ov015 @ 0x2194560; symbol: data_ov015_02194560.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern char Main_UnknownRoleZeroInitializedStorage_Variant3[];void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);void CharacterViewer_DestroyMenuCatalog(RecordArray*);extern RecordArray* CharacterViewerScriptAppendMenuEntry_UnknownRoleZeroInitializedStorage;void CharacterViewer_AllocateMenuCatalogEntries(RecordArray*,int);void Script_InitializeRecordPairStorage(RecordArray*,int);}
// Original: arm9/ov015 @ 0x0218B9AC; symbol: func_ov015_0218b9ac; size: 0x28.
extern "C" ARM void Script_InitializeRecordPairStorage(RecordArray* p,int count){p->pairs=(Pair*)AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,(unsigned)count<<3);p->pairCount=0;}
