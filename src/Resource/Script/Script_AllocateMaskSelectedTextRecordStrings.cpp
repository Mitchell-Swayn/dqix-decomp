#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
struct TextRecord { short id, padding; char* first; char* second; char** items; char* suffix; char* finalText; };
struct TextList { TextRecord* records; short count,capacity; short* ids; short idCount; unsigned short mask; };
struct TextContext { SafeAllocator* allocator; TextList* list; };
// Original data: arm9/main @ 0x2108fc0; symbol: data_02108fc0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" TextContext WorldScriptTextAllocateSelectedEntries_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x20f1244; symbol: data_020f1244.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 25730000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const char ScriptAllocateMaskSelectedTextRecordStrings_UnknownRoleInitializedBytes[];
extern "C" void WorldScriptText_InitializeRecord(TextRecord*);
extern "C" void WorldScriptArrayList_AppendEntryWithinCapacity(TextList*,const TextRecord*);
extern "C" unsigned int String_CountBytesUntilTerminator(const char*);
extern "C" int sprintf(char*,const char*,...);
// Original: arm9/main @ 0x0208D594; symbol: func_0208d594; size: 0x298.
extern "C" int Script_AllocateMaskSelectedTextRecordStrings(Script::Parameter* params) {
    unsigned short mask = WorldScriptTextAllocateSelectedEntries_UnknownRoleZeroInitializedStorage.list->mask;
    TextRecord record;
    WorldScriptText_InitializeRecord(&record);
    record.id = params[0].ToInt();
    int found;
    short* ids;
    short count = WorldScriptTextAllocateSelectedEntries_UnknownRoleZeroInitializedStorage.list->idCount;
    if (count) {
        found=0;
        ids=WorldScriptTextAllocateSelectedEntries_UnknownRoleZeroInitializedStorage.list->ids;
        for (short i=0;i<count;++i) { if (record.id == *ids) found=1; ++ids; }
        if (!found) return 1;
    }
    const char* text = params[1].ToString();
    unsigned int length;
    if ((mask & 1) && (length=String_CountBytesUntilTerminator(text)) != 0) {
        record.first=(char*)WorldScriptTextAllocateSelectedEntries_UnknownRoleZeroInitializedStorage.allocator->Allocate(length+1);
        record.first[length]=0;
        sprintf(record.first,ScriptAllocateMaskSelectedTextRecordStrings_UnknownRoleInitializedBytes,text);
    }
    params+=2;
    text=(params++)->ToString();
    if ((mask & 2) && (length=String_CountBytesUntilTerminator(text)) != 0) {
        record.second=(char*)WorldScriptTextAllocateSelectedEntries_UnknownRoleZeroInitializedStorage.allocator->Allocate(length+1);
        record.second[length]=0;
        sprintf(record.second,ScriptAllocateMaskSelectedTextRecordStrings_UnknownRoleInitializedBytes,text);
    }
    if (mask & 0x3fc) {
        record.items=(char**)WorldScriptTextAllocateSelectedEntries_UnknownRoleZeroInitializedStorage.allocator->Allocate(32);
        for (unsigned char i=0;i<8;++i) record.items[i]=0;
    }
    unsigned int bit=4;
    for (unsigned char i=0;i<8;++i) {
        const char* item=(params++)->ToString();
        if ((mask & bit) && (length=String_CountBytesUntilTerminator(item)) != 0) {
            record.items[i]=(char*)WorldScriptTextAllocateSelectedEntries_UnknownRoleZeroInitializedStorage.allocator->Allocate(length+1);
            char* entry=record.items[i];
            entry[length]=0;
            sprintf(entry,ScriptAllocateMaskSelectedTextRecordStrings_UnknownRoleInitializedBytes,item);
        }
        bit<<=1;
    }
    text=params[0].ToString();
    if ((mask & 0x400) && (length=String_CountBytesUntilTerminator(text)) != 0) {
        record.suffix=(char*)WorldScriptTextAllocateSelectedEntries_UnknownRoleZeroInitializedStorage.allocator->Allocate(length+1);
        record.suffix[length]=0;
        sprintf(record.suffix,ScriptAllocateMaskSelectedTextRecordStrings_UnknownRoleInitializedBytes,text);
    }
    text=params[1].ToString();
    if ((mask & 0x800) && (length=String_CountBytesUntilTerminator(text)) != 0) {
        record.finalText=(char*)WorldScriptTextAllocateSelectedEntries_UnknownRoleZeroInitializedStorage.allocator->Allocate(length+1);
        record.finalText[length]=0;
        sprintf(record.finalText,ScriptAllocateMaskSelectedTextRecordStrings_UnknownRoleInitializedBytes,text);
    }
    WorldScriptArrayList_AppendEntryWithinCapacity(WorldScriptTextAllocateSelectedEntries_UnknownRoleZeroInitializedStorage.list,&record);
    return 1;
}
