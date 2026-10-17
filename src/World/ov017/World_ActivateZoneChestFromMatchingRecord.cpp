#include <globaldefs.h>
ARM

extern "C" unsigned short *ReadGlobalValueAt020FB3F0(void);
extern "C" void *_ZN6Zone3D13GetChestEntryEi(void *, int);
extern "C" void _Z17ActivateZoneChestP14ZoneChestEntryibb(void *, int, bool, bool);

// Original: arm9/ov017 @ 0x021CFDA0; symbol: func_ov017_021cfda0; size: 0x40.
extern "C" void World_ActivateZoneChestFromMatchingRecord(void *unused, unsigned char *record) {
    unsigned short *zoneIndex = ReadGlobalValueAt020FB3F0();
    if (*(unsigned short *)(record + 4) != *zoneIndex) {
        return;
    }
    void *chest = _ZN6Zone3D13GetChestEntryEi(zoneIndex, *(unsigned short *)(record + 6));
    if (chest != 0) {
        _Z17ActivateZoneChestP14ZoneChestEntryibb(chest, record[8], false, false);
    }
}
