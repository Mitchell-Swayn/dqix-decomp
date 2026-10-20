#include <globaldefs.h>
ARM
extern "C" void *Zone3D_GetMainInstance(void);
extern "C" void *_ZN13ZoneState084021FindEntryByIdentifierEPKv(void *, const void *);
extern "C" void *memset(void *, int, unsigned int);
// Original: arm9/ov003 @ 0x02171F80; symbol: func_ov003_02171f80; size: 0x68.
extern "C" void TagMode_RemoveCacheEntriesForMissingGuests(void *state) {
    void *zone = Zone3D_GetMainInstance();
    unsigned char *record = (unsigned char *)state + 8;
    int index;
    for (index = 0; index < 50; index++, record += 8) {
        if (_ZN13ZoneState084021FindEntryByIdentifierEPKv((char *)zone + 0x840, record) == 0) {
            memset(record, 0, 8);
            *((unsigned char *)state + 0x198) -= 1;
        }
    }
}
