#include "World/Zone3D.h"

// Gameplay meaning of this zone rule list is not established yet.
extern const unsigned short gZoneRuleList[] = {
    100, 198, 200, 201, 400, 4200, 1100, 1200, 1300, 1500,
    1700, 1800, 1900, 2000, 2100, 2200, 2300, 5700, 5800, 0
};
// Original data: arm9/main @ 0x20e6e53; symbol: data_020e6e53.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const unsigned char Zone3DUpdateZone170CInstances_UnknownRoleInitializedBytes[];
// Original data: arm9/main @ 0x20e6e54; symbol: data_020e6e54.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const unsigned char Zone3DUpdateZone170CInstances_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/main @ 0x20e6e55; symbol: data_020e6e55.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const unsigned char Zone3DUpdateZone170CInstances_UnknownRoleInitializedBytes_Variant3[];
// Original data: arm9/main @ 0x20e6e56; symbol: data_020e6e56.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0001000000000000010001000000.
// Observed span: 14 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const unsigned char Zone3DUpdateZone170CInstances_UnknownRoleInitializedBytes_Variant4[];

// Original: arm9/main @ 0x0201B868; symbol: _ZN6Zone3D16IsZoneInRuleListEi; size: 0x60.
bool Zone3D::IsZoneInRuleList(int zoneID)
{
    unsigned short id = zoneID;
    if (id >= 20000 && id <= 29999) return true;
    for (int i = 0; gZoneRuleList[i]; ++i)
        if (id == gZoneRuleList[i]) return true;
    return false;
}

// The four table columns control instances 2, 12, 3 and 9 in zone 0x170c.
// Original: arm9/main @ 0x0201B8C8; symbol: _ZN6Zone3D23UpdateZone170cInstancesEbbb; size: 0x154.
void Zone3D::UpdateZone170cInstances(bool first, bool second, bool alternate)
{
    if (currentZoneID_ != 0x170c) return;
    LightingManager* lighting = LightingManager::GetInstance();
    Zone3D_BMDJStruct::InstanceEntry* instance = FindBMDJInstance(0, 10);
    if (instance) UpdateBMDJFlag4(instance, 0, first);
    instance = FindBMDJInstance(0, 11);
    if (instance) UpdateBMDJFlag4(instance, 0, second);
    int row;
    if (alternate)
    {
        if (lighting->timeOfDayIndex_ == 3) row = 0;
        else row = 1;
    }
    else row = lighting->timeOfDayIndex_ == 3 ? 2 : 3;
    instance = FindBMDJInstance(0, 2);
    if (instance) UpdateBMDJFlag4(instance, 0, Zone3DUpdateZone170CInstances_UnknownRoleInitializedBytes[row * 4]);
    instance = FindBMDJInstance(0, 12);
    if (instance) UpdateBMDJFlag4(instance, 0, Zone3DUpdateZone170CInstances_UnknownRoleInitializedBytes_Variant2[row * 4]);
    instance = FindBMDJInstance(0, 3);
    if (instance) UpdateBMDJFlag4(instance, 0, Zone3DUpdateZone170CInstances_UnknownRoleInitializedBytes_Variant3[row * 4]);
    instance = FindBMDJInstance(0, 9);
    if (instance) UpdateBMDJFlag4(instance, 0, Zone3DUpdateZone170CInstances_UnknownRoleInitializedBytes_Variant4[row * 4]);
}

// Original: arm9/main @ 0x0201BA1C; symbol: _ZN6Zone3D27RequestBMDJObjectStateResetEii; size: 0x4C.
void Zone3D::RequestBMDJObjectStateReset(int groupID, int instanceID)
{
    Zone3D_BMDJStruct::InstanceEntry* instance = FindLastBMDJInstance(groupID, instanceID);
    if (!instance || !instance->object) return;
    if (!instance->resource) return;
    if (instance->resource->kind != 2) return;
    instance->doorState = 0;
    instance->doorTimer = 0;
    instance->flags |= 0x100;
}
