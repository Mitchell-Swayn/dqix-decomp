#include <globaldefs.h>
#include <Resource/Script.h>
struct Record {char* first;char* second;unsigned short value;unsigned char flag1,flag2;}; struct Pair {void* first;void* second;}; struct RecordArray {Record* records;Pair* pairs;int count,pairCount;};
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
extern "C" { extern char Main_UnknownRoleZeroInitializedStorage_Variant3[]; extern RecordArray* CharacterViewerScriptAppendMenuEntry_UnknownRoleZeroInitializedStorage; void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned); unsigned String_CountBytesUntilTerminator(const char*); void CharacterViewer_AppendMenuCatalogEntry(RecordArray*,const Record*); }
// Original: arm9/ov015 @ 0x0218B5C8; symbol: func_ov015_0218b5c8; size: 0xF4.
extern "C" ARM int CharacterViewer_ScriptAppendMenuEntry(const Script::Parameter* parameters) {
    const char* first=parameters[0].ToString();
    const char* second=parameters[1].ToString();
    int value=parameters[2].ToInt();
    int flag1=parameters[3].ToInt();
    int flag2=parameters[4].ToInt();
    Record record;
    record.first=0; record.second=0; record.value=0; record.flag1=0; record.flag2=0;
    if(first) {record.first=(char*)AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,String_CountBytesUntilTerminator(first)+1);if(record.first)strcpy(record.first,first);}
    if(second) {record.second=(char*)AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,String_CountBytesUntilTerminator(second)+1);if(record.second)strcpy(record.second,second);}
    RecordArray* p=CharacterViewerScriptAppendMenuEntry_UnknownRoleZeroInitializedStorage;
    record.value=value; record.flag1=flag1; record.flag2=flag2;
    CharacterViewer_AppendMenuCatalogEntry(p,&record);
    return 1;
}
