#include <globaldefs.h>
#include <Resource/Script.h>
#include <std_library_functions.h>
struct NamedEntry { int id; char name[31]; unsigned char flags; };
struct NamedList { unsigned char unrestricted; unsigned char unknown1[7]; NamedEntry* entries; unsigned unknownC; int capacity; unsigned unknown14,unknown18; int owner; unsigned unknown20; int count; };
extern "C" NamedList data_02108d70;
extern "C" unsigned String_CountBytesUntilTerminator(const char*);
// Original: arm9/main @ 0x02071044; symbol: func_02071044; size: 0x1C4.
extern "C" int Script_AppendUniqueBoundedNamedEntry(Script::Parameter* args) {
    if(data_02108d70.capacity<=data_02108d70.count) return 0;
    int owner=args[0].ToInt();
    args[1].ToInt();
    if(owner==data_02108d70.owner || data_02108d70.unrestricted) {
        args[2].ToInt(); args[3].ToInt(); args[4].ToInt();
        int id=args[5].ToInt();
        for(int i=0;i<data_02108d70.count;++i) {
            if(id==data_02108d70.entries[i].id && (id<21000 || id>=40000)) return 0;
        }
        data_02108d70.entries[data_02108d70.count].id=id;
        args[6].ToInt();
        const char* name=args[7].ToString();
        if(!name) return 0;
        memset(data_02108d70.entries[data_02108d70.count].name,0,32);
        int length=String_CountBytesUntilTerminator(name);
        if(length<31) memcpy(data_02108d70.entries[data_02108d70.count].name,name,length);
        else {
            memcpy(data_02108d70.entries[data_02108d70.count].name,name,30);
            data_02108d70.entries[data_02108d70.count].name[30]=0;
        }
        data_02108d70.entries[data_02108d70.count].flags=0;
        ++data_02108d70.count;
    }
    return 1;
}
