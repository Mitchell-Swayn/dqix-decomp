#include "World/Zone3DContainers.h"

void ZoneContainerRenderPart::Reset()
{
    unknown_0 = 0;
    unknown_6 = 0;
    unknown_8 = 0;
    unknown_c = 0;
    entries.count = 0;
    unknown_4 = 3;
    unknown_10 = 0;
    flag0 = 0;
    unknown_70 = unknown_74 = unknown_78 = unknown_7c = 0;
    position.z = position.y = position.x = 0;
    unknown_28.z = unknown_28.y = unknown_28.x = 0;
    scale.z = scale.y = scale.x = 0x1000;
    unknown_82 = 0x1f;
    diffuseColor = 0x7fff;
    flag1 = 0;
    flag2 = 0;
}

void ZoneContainerRenderPart::ResetIfFlag0()
{
    if (flag0) Reset();
}
