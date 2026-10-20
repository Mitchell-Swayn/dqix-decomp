#include "World/Zone3D.h"
#include "Graphics/NSBXX/NSBXX.h"

// Original: arm9/main @ 0x02018F30; symbol: _ZN6Zone3D23UpdateChestDiffuseColorEv; size: 0x3C.
void Zone3D::UpdateChestDiffuseColor()
{
    for (int i = 0; i < 2; ++i)
    {
        NSBXXInternalModel* model = models_498_[i].rawInternalModel_;
        if (model) NSBXX_Model_SetDiffuseReflectionColor(model, (unsigned short)mapListInfo_.unknown_2a);
    }
}

// Original: arm9/main @ 0x02018F6C; symbol: _ZN6Zone3D15SetZoneRotationEi; size: 0x50.
void Zone3D::SetZoneRotation(int angle)
{
    unknown_474_ = angle;
    if (unknown_474_) zoneRotationMatrix_ = RotationMatrixY(unknown_474_);
}
