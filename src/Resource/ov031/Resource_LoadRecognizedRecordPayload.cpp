#include <globaldefs.h>
ARM
struct GameResources;
extern "C" char* strstr(const char* str, const char* substr);
extern "C" void MI_CpuCopy8(const void* src, void* dst, unsigned int length);
extern "C" GameResources* GameResources_GetInstance();
extern "C" char data_ov031_0224c94e[];
extern "C" char data_ov031_02291e04[];
struct Record { char tag[4]; unsigned id, value; unsigned char payload[8]; };
// Original: arm9/ov031 @ 0x02245750; symbol: func_ov031_02245750; size: 0x90.
extern "C" int Resource_LoadRecognizedRecordPayload(void *unused, Record *record) {
    int index;
    if (!strstr((char*)record, data_ov031_0224c94e)) return 0;
    for (index = 0; index < 14; index++) {
        if (record->id == (*(unsigned**)(data_ov031_02291e04 + 0x28))[index]) break;
    }
    if (index == 14) return 0;
    char *resources = (char*)GameResources_GetInstance();
    unsigned char *target = *(unsigned char**)(resources + 0x3b48);
    target[0x28] = index;
    target[0x29] = record->value;
    MI_CpuCopy8(record->payload, target + 0x2a, 8);
    return 1;
}
