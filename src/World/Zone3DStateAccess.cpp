#include "World/Zone3D.h"

// The two stored values and the map flag's gameplay purpose remain unresolved.
// Original: arm9/main @ 0x0201BC7C; symbol: _ZN6Zone3D14SetUnknown27d8Et; size: 0xC.
void Zone3D::SetUnknown27d8(unsigned short value) { unknown_27d8_ = value; }
// Original: arm9/main @ 0x0201BC88; symbol: _ZN6Zone3D14SetUnknown27daEt; size: 0xC.
void Zone3D::SetUnknown27da(unsigned short value) { unknown_27da_ = value; }

// Original: arm9/main @ 0x0201BC94; symbol: _ZN6Zone3D32HasMapFlag10OutsideExcludedZonesEv; size: 0x70.
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

// Original: arm9/main @ 0x0201BD04; symbol: _ZN6Zone3D18ClearInstanceFlag4Eii; size: 0x38.
void Zone3D::ClearInstanceFlag4(int instanceID, int groupID)
{
    Zone3D_BMDJStruct::InstanceEntry* instance = FindBMDJInstance(groupID, instanceID);
    int group = 0;
    if (groupID >= 0) group = (unsigned char)groupID;
    if (instance) UpdateBMDJFlag4(instance, group, 1);
}

// Original: arm9/main @ 0x0201BD3C; symbol: _ZN6Zone3D16SetInstanceFlag4Eii; size: 0x38.
void Zone3D::SetInstanceFlag4(int instanceID, int groupID)
{
    Zone3D_BMDJStruct::InstanceEntry* instance = FindBMDJInstance(groupID, instanceID);
    int group = 0;
    if (groupID >= 0) group = (unsigned char)groupID;
    if (instance) UpdateBMDJFlag4(instance, group, 0);
}

// Original: arm9/main @ 0x0201BD74; symbol: _ZN6Zone3D20IsInstanceFlag4ClearEii; size: 0x38.
bool Zone3D::IsInstanceFlag4Clear(int instanceID, int groupID)
{
    Zone3D_BMDJStruct::InstanceEntry* instance = FindBMDJInstance(groupID, instanceID);
    if (instance) return !(instance->flags & 4);
    return false;
}
