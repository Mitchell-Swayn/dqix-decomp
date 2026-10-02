#include "World/Zone3D.h"
#include "Graphics/NSBXX/NSBXX.h"

void Zone3D::UpdateChestDiffuseColor()
{
    for (int i = 0; i < 2; ++i)
    {
        NSBXXInternalModel* model = models_498_[i].rawInternalModel_;
        if (model) NSBXX_Model_SetDiffuseReflectionColor(model, (unsigned short)mapListInfo_.unknown_2a);
    }
}

void Zone3D::SetZoneRotation(int angle)
{
    unknown_474_ = angle;
    if (unknown_474_) zoneRotationMatrix_ = RotationMatrixY(unknown_474_);
}
