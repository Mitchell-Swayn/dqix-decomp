#include "World/Zone3D.h"

// The two stored values and the map flag's gameplay purpose remain unresolved.
void Zone3D::SetUnknown27d8(unsigned short value) { unknown_27d8_ = value; }
void Zone3D::SetUnknown27da(unsigned short value) { unknown_27da_ = value; }

bool Zone3D::HasMapFlag10OutsideExcludedZones()
{
    bool result = true;
    if (currentZoneID_ == 10000) result = false;
    else if (currentZoneID_ == 10100) result = false;
    else if ((unsigned short)unknown_4_ == 5900) result = false;
    else if ((unsigned short)unknown_4_ == 6401) result = false;
    else if (!pUnknownStruct_8_->unknown_c_high_) result = false;
    return result;
}

void Zone3D::ClearInstanceFlag4(int instanceID, int groupID)
{
    Zone3D_BMDJStruct::InstanceEntry* instance = FindBMDJInstance(groupID, instanceID);
    int group = 0;
    if (groupID >= 0) group = (unsigned char)groupID;
    if (instance) UpdateBMDJFlag4(instance, group, 1);
}

void Zone3D::SetInstanceFlag4(int instanceID, int groupID)
{
    Zone3D_BMDJStruct::InstanceEntry* instance = FindBMDJInstance(groupID, instanceID);
    int group = 0;
    if (groupID >= 0) group = (unsigned char)groupID;
    if (instance) UpdateBMDJFlag4(instance, group, 0);
}

bool Zone3D::IsInstanceFlag4Clear(int instanceID, int groupID)
{
    Zone3D_BMDJStruct::InstanceEntry* instance = FindBMDJInstance(groupID, instanceID);
    if (instance) return !(instance->flags & 4);
    return false;
}
