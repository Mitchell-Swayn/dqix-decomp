#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" {
ARM char* BattleMenu_FindPartyCommandRecord(char*, int);
void* memcpy(void*, const void*, unsigned);
void Graphics_TransferPaletteRange(void*, unsigned, unsigned, unsigned, unsigned);
double Runtime_ComputeSine(double);
}
// Original: arm9/ov000 @ 0x02174E50; symbol: func_ov000_02174e50; size: 0x170.
// Encodes the four-slot record's float field into its packed halfword and updates the indexed table.
extern "C" ARM void BattleMenu_UpdatePartyFlashPaletteColor(unsigned char* self, int index) {
    (void)GameState::GetInstance();
    unsigned char* record = (unsigned char*)BattleMenu_FindPartyCommandRecord((char*)self, index);
    if (!record) return;

    float value = *(float*)(record + 0x40);
    unsigned short defaultValue;
    unsigned short packedValue;
    if (3.14f <= value) {
        defaultValue = 0x7fff;
        memcpy(*(void**)(self + 0x178), &defaultValue, 2);
        Graphics_TransferPaletteRange(self + 0x8c4, (unsigned)(index + 2), 0xf, *(unsigned*)(self + 0x178), 2);
        record[0x24] &= ~8;
        *(unsigned*)(record + 0x40) = 0;
        *(unsigned short*)(record + 0x80) = 0x7fff;
    } else {
        float doubled = value * 2.0f;
        float sine = (float)Runtime_ComputeSine((double)doubled);
        if (sine < 0.0f) sine = -sine;
        float remainder = 1.0f - sine;
        int lower = (int)(remainder * 16.0f) + 0xf;
        int upper = (int)(remainder * 31.0f);
        if (lower > 0x1f) lower = 0x1f;
        if (upper > 0x1f) upper = 0x1f;
        packedValue = (unsigned short)((lower << 5) | 0x1f | (upper << 10));
        memcpy(*(void**)(self + 0x178), &packedValue, 2);
        Graphics_TransferPaletteRange(self + 0x8c4, (unsigned)(index + 2), 0xf, *(unsigned*)(self + 0x178), 2);
        *(unsigned short*)(record + 0x80) = packedValue;
    }
}
