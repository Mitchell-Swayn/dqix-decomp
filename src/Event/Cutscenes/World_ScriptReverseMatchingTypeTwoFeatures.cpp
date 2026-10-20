#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" void* Zone3D_GetMainInstance();
extern "C" void _ZN6Zone3D25ReverseType2FeatureMotionEPN12ZoneFeatures13Opcode6aEntryE(void*,void*);
extern "C" void* _ZN12ZoneFeatures14GetTypeEntriesEi(void*,int);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView* parameter);
struct Entry { unsigned char pad[0x2c]; unsigned char a,b; unsigned short low : 4; unsigned short flags : 12; unsigned char tail[0x40]; Entry *next; };
// Original: arm9/ov001 @ 0x02160B08; symbol: func_ov001_02160b08; size: 0xB8.
extern "C" int World_ScriptReverseMatchingTypeTwoFeatures(char *params, int count) {
    int a = Script_ReadParameterAsInteger((IntegerParameterView*)params);
    int b = Script_ReadParameterAsInteger((IntegerParameterView*)(params + 8));
    if (count > 2) Script_ReadParameterAsInteger((IntegerParameterView*)(params + 16));
    char *zone = (char*)Zone3D_GetMainInstance();
    Entry *entry = (Entry*)_ZN12ZoneFeatures14GetTypeEntriesEi(zone + 0x6c, 2);
    while (entry) {
        unsigned short flags = entry->flags;
        if (flags & 1) {
            if (entry->a == a && entry->b == b) {
                flags &= ~0x200;
                entry->flags = flags;
                _ZN6Zone3D25ReverseType2FeatureMotionEPN12ZoneFeatures13Opcode6aEntryE(zone,entry);
            }
        }
        entry = entry->next;
    }
    return 1;
}
