#include <globaldefs.h>
ARM
struct GameResources;
extern "C" char* strstr(const char* str, const char* substr);
extern "C" void MI_CpuCopy8(const void* src, void* dst, unsigned int length);
extern "C" GameResources* GameResources_GetInstance();
extern "C" char Resource_LoadRecognizedRecordPayload_TextDQ9[];
// Original data: arm9/ov031 @ 0x2291e04; symbol: data_ov031_02291e04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage[];
struct Record { char tag[4]; unsigned id, value; unsigned char payload[8]; };
// Original: arm9/ov031 @ 0x02245750; symbol: func_ov031_02245750; size: 0x90.
extern "C" int Resource_LoadRecognizedRecordPayload(void *unused, Record *record) {
    int index;
    if (!strstr((char*)record, Resource_LoadRecognizedRecordPayload_TextDQ9)) return 0;
    for (index = 0; index < 14; index++) {
        if (record->id == (*(unsigned**)(ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage + 0x28))[index]) break;
    }
    if (index == 14) return 0;
    char *resources = (char*)GameResources_GetInstance();
    unsigned char *target = *(unsigned char**)(resources + 0x3b48);
    target[0x28] = index;
    target[0x29] = record->value;
    MI_CpuCopy8(record->payload, target + 0x2a, 8);
    return 1;
}
