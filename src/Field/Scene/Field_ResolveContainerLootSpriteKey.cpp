#include <globaldefs.h>
ARM
#include <World/Zone3D.h>
struct ContainerMapFlags {
    unsigned short low : 2;
    unsigned short kind : 2;
    unsigned short high : 12;
};
struct ContainerMapRecord {
    unsigned unknown_00;
    ContainerMapFlags flags;
};
struct ContainerLootSprite {
    unsigned char unknown_00[0x12];
    short key;
    unsigned short sprite;
    unsigned char unknown_16;
    unsigned char palette;
    unsigned char unknown_18[12];
    ContainerMapRecord* map;
};
struct LootRecord {
    unsigned char unknown_00[16];
    unsigned low : 20;
    unsigned palette : 8;
    unsigned high : 4;
};
extern "C" Zone3D* Zone3D_GetMainInstance();
extern "C" LootRecord* ZoneState2754_FindPrimaryRecordByKey(ZoneState2754*, int);
extern "C" int ZoneSerializedRecord_GetPreferredAttribute(LootRecord*, int);
#pragma force_active on
// Original: arm9/ov017 @ 0x021B5C88; symbol: func_ov017_021b5c88; size: 0x70.
extern "C" int Field_ResolveContainerLootSpriteKey(ContainerLootSprite* container) {
    ZoneState2754* records = &Zone3D_GetMainInstance()->state_2754_;
    if (container->map->flags.kind == 1) {
        container->palette = 0x69;
        container->sprite = 0x7f;
    } else {
        LootRecord* record = ZoneState2754_FindPrimaryRecordByKey(records, container->key);
        if (record) {
            container->palette = record->palette;
            container->sprite = ZoneSerializedRecord_GetPreferredAttribute(record, 0);
        }
    }
    return 2;
}

#pragma force_active off
