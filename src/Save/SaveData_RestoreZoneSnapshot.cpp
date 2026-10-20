#include <globaldefs.h>
#pragma opt_propagation off
#include <World/Zone3D.h>
#include <System/Memory.h>

extern "C" void* Zone3D_GetMainInstance();

// The trailing values accompany the first 0x1b30 bytes of ZoneState0840.
struct SavedZoneSnapshot
{
    unsigned char entries[0xd98];
    struct Tail {
    unsigned char remainingEntries[0xd98];
    unsigned int value_1b30;
    unsigned int value_1b34;
    unsigned int value_1b38;
    unsigned short mode_1b3c;
    unsigned char flag_1b3e;
    } tail;
};

#pragma force_active on
// Original: arm9/main @ 0x020A9B2C; symbol: func_020a9b2c; size: 0x78.
// Restores the saved zone entries, three trailing values, low-byte mode and flag.
extern "C" ARM int SaveData_RestoreZoneSnapshot(const void* savedBytes)
{
    const SavedZoneSnapshot* snapshot = (const SavedZoneSnapshot*)savedBytes;
    const SavedZoneSnapshot::Tail* tail = &snapshot->tail;
    Zone3D* zone = (Zone3D*)Zone3D_GetMainInstance();
    ZoneState0840* zoneState = &zone->state_840_;
    zoneState->unknown_1b38 = tail->value_1b30;
    zoneState->unknown_1b34 = tail->value_1b34;
    zoneState->unknown_1b44 = tail->value_1b38;
    zoneState->unknown_1b3c = tail->mode_1b3c & 0xff;
    zoneState->unknown_1b61 = tail->flag_1b3e != 0;
    MI_CpuCopy8(snapshot, &zone->state_840_, 0x1b30);
    return 1;
}
#pragma force_active off
