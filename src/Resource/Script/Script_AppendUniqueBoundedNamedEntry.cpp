#include <globaldefs.h>
#include <Resource/Script.h>
#include <std_library_functions.h>
struct NamedEntry { int id; char name[31]; unsigned char flags; };
struct NamedList { unsigned char unrestricted; unsigned char unknown1[7]; NamedEntry* entries; unsigned unknownC; int capacity; unsigned unknown14,unknown18; int owner; unsigned unknown20; int count; };
// Original data: arm9/main @ 0x2108d70; symbol: data_02108d70.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" NamedList ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage;
extern "C" unsigned String_CountBytesUntilTerminator(const char*);
// Original: arm9/main @ 0x02071044; symbol: func_02071044; size: 0x1C4.
extern "C" int Script_AppendUniqueBoundedNamedEntry(Script::Parameter* args) {
    if(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.capacity<=ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.count) return 0;
    int owner=args[0].ToInt();
    args[1].ToInt();
    if(owner==ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.owner || ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.unrestricted) {
        args[2].ToInt(); args[3].ToInt(); args[4].ToInt();
        int id=args[5].ToInt();
        for(int i=0;i<ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.count;++i) {
            if(id==ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entries[i].id && (id<21000 || id>=40000)) return 0;
        }
        ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entries[ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.count].id=id;
        args[6].ToInt();
        const char* name=args[7].ToString();
        if(!name) return 0;
        memset(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entries[ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.count].name,0,32);
        int length=String_CountBytesUntilTerminator(name);
        if(length<31) memcpy(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entries[ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.count].name,name,length);
        else {
            memcpy(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entries[ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.count].name,name,30);
            ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entries[ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.count].name[30]=0;
        }
        ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.entries[ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.count].flags=0;
        ++ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.count;
    }
    return 1;
}
