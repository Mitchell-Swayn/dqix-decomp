#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
struct TextRecord { short id, padding; char* first; char* second; char** items; char* suffix; char* finalText; };
struct TextList { TextRecord* records; short count,capacity; short* ids; short idCount; unsigned short mask; };
struct TextContext { SafeAllocator* allocator; TextList* list; };
extern "C" TextContext data_02108fc0;
extern "C" const char data_020f1244[];
extern "C" void Object_InitializeInvalidHalfwordAndFiveWords(TextRecord*);
extern "C" void WorldScriptArrayList_AppendEntryWithinCapacity(TextList*,const TextRecord*);
extern "C" unsigned int String_CountBytesUntilTerminator(const char*);
extern "C" int sprintf(char*,const char*,...);
// Original: arm9/main @ 0x0208D594; symbol: func_0208d594; size: 0x298.
extern "C" int Script_AllocateMaskSelectedTextRecordStrings(Script::Parameter* params) {
    unsigned short mask = data_02108fc0.list->mask;
    TextRecord record;
    Object_InitializeInvalidHalfwordAndFiveWords(&record);
    record.id = params[0].ToInt();
    int found;
    short* ids;
    short count = data_02108fc0.list->idCount;
    if (count) {
        found=0;
        ids=data_02108fc0.list->ids;
        for (short i=0;i<count;++i) { if (record.id == *ids) found=1; ++ids; }
        if (!found) return 1;
    }
    const char* text = params[1].ToString();
    unsigned int length;
    if ((mask & 1) && (length=String_CountBytesUntilTerminator(text)) != 0) {
        record.first=(char*)data_02108fc0.allocator->Allocate(length+1);
        record.first[length]=0;
        sprintf(record.first,data_020f1244,text);
    }
    params+=2;
    text=(params++)->ToString();
    if ((mask & 2) && (length=String_CountBytesUntilTerminator(text)) != 0) {
        record.second=(char*)data_02108fc0.allocator->Allocate(length+1);
        record.second[length]=0;
        sprintf(record.second,data_020f1244,text);
    }
    if (mask & 0x3fc) {
        record.items=(char**)data_02108fc0.allocator->Allocate(32);
        for (unsigned char i=0;i<8;++i) record.items[i]=0;
    }
    unsigned int bit=4;
    for (unsigned char i=0;i<8;++i) {
        const char* item=(params++)->ToString();
        if ((mask & bit) && (length=String_CountBytesUntilTerminator(item)) != 0) {
            record.items[i]=(char*)data_02108fc0.allocator->Allocate(length+1);
            char* entry=record.items[i];
            entry[length]=0;
            sprintf(entry,data_020f1244,item);
        }
        bit<<=1;
    }
    text=params[0].ToString();
    if ((mask & 0x400) && (length=String_CountBytesUntilTerminator(text)) != 0) {
        record.suffix=(char*)data_02108fc0.allocator->Allocate(length+1);
        record.suffix[length]=0;
        sprintf(record.suffix,data_020f1244,text);
    }
    text=params[1].ToString();
    if ((mask & 0x800) && (length=String_CountBytesUntilTerminator(text)) != 0) {
        record.finalText=(char*)data_02108fc0.allocator->Allocate(length+1);
        record.finalText[length]=0;
        sprintf(record.finalText,data_020f1244,text);
    }
    WorldScriptArrayList_AppendEntryWithinCapacity(data_02108fc0.list,&record);
    return 1;
}
