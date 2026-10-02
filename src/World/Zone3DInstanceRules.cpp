#include "World/Zone3D.h"

// Gameplay meaning of this zone rule list is not established yet.
extern const unsigned short gZoneRuleList[] = {
    100, 198, 200, 201, 400, 4200, 1100, 1200, 1300, 1500,
    1700, 1800, 1900, 2000, 2100, 2200, 2300, 5700, 5800, 0
};
extern const unsigned char data_020e6e53[];
extern const unsigned char data_020e6e54[];
extern const unsigned char data_020e6e55[];
extern const unsigned char data_020e6e56[];

bool Zone3D::IsZoneInRuleList(int zoneID)
{
    unsigned short id = zoneID;
    if (id >= 20000 && id <= 29999) return true;
    for (int i = 0; gZoneRuleList[i]; ++i)
        if (id == gZoneRuleList[i]) return true;
    return false;
}

// The four table columns control instances 2, 12, 3 and 9 in zone 0x170c.
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
    if (instance) UpdateBMDJFlag4(instance, 0, data_020e6e53[row * 4]);
    instance = FindBMDJInstance(0, 12);
    if (instance) UpdateBMDJFlag4(instance, 0, data_020e6e54[row * 4]);
    instance = FindBMDJInstance(0, 3);
    if (instance) UpdateBMDJFlag4(instance, 0, data_020e6e55[row * 4]);
    instance = FindBMDJInstance(0, 9);
    if (instance) UpdateBMDJFlag4(instance, 0, data_020e6e56[row * 4]);
}

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
