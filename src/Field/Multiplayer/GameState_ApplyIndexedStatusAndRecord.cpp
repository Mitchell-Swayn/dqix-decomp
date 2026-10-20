#include <globaldefs.h>
ARM
extern "C" void* Zone3D_GetMainInstance();
extern "C" void* ZoneState_GetTrackedZoneCache();
struct E { unsigned short id; unsigned short unused : 4; unsigned short value : 12; };
extern "C" E *ZoneState_FindTrackedZoneByIdentifier(E *p,int key);
// Original: arm9/ov017 @ 0x021CF4E8; symbol: func_ov017_021cf4e8; size: 0xAC.
extern "C" void GameState_ApplyIndexedStatusAndRecord(void *unused, unsigned char *input, char *self, char *context) {
    int index = input[4];
    int valid;
    if ((unsigned)index <= 3) valid = 1; else valid = 0;
    if (valid) {
        *(unsigned char *)(self + index + 0x7f76) = input[5];
        if (input[5] == 2) {
            unsigned short *destination = (unsigned short *)(context + 0x44b4);
            unsigned short *zone = (unsigned short *)Zone3D_GetMainInstance();
            E *records = (E *)ZoneState_GetTrackedZoneCache();
            E *record = ZoneState_FindTrackedZoneByIdentifier(records, *zone);
            if (record) {
                destination[0] = *zone;
                destination[1] = record->value;
            }
        }
    } else *(unsigned char *)(self + index + 0x7f76) = 5;
    *(unsigned char *)(self + 0x7f7a) |= 1 << input[4];
}
