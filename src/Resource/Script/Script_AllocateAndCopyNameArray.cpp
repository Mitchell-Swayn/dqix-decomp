#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct StringTableInfo {
    unsigned char unknown_0[0xc];
    char** names0;
    short count0;
    unsigned char unknown_12[2];
    char** names1;
    short count1;
};

struct StringTables {
    StringTableInfo* info;
    unsigned char unknown_4[8];
    SafeAllocator* allocator;
};

extern "C" StringTables data_02108efc;
extern "C" int String_CountBytesUntilTerminator(const char*); // strlen

// Copies the strings out of the script parameters into freshly allocated storage.
// Original: arm9/main @ 0x020899FC; symbol: func_020899fc; size: 0xA4.
extern "C" ARM int Script_AllocateAndCopyNameArray(Script::Parameter* params) {
    char** names;
    short count = data_02108efc.info->count0;
    names = (char**)data_02108efc.allocator->Allocate(count * 4);
    for (short i = 0; i < count; i++) {
        const char* src = (params++)->ToString();
        int len = String_CountBytesUntilTerminator(src);
        names[i] = (char*)data_02108efc.allocator->Allocate(len + 1);
        memset(names[i], 0, len + 1);
        memcpy(names[i], src, len);
    }
    data_02108efc.info->names0 = names;
    return 1;
}
