#pragma once
#include "Graphics/Vector.h"

// Partial layouts established by container creation and model binding.
struct ZoneContainerRenderPart
{
    char unknown_0[0x1c];
    Vector3i position;
    char unknown_28[0xc];
    Vector3i scale;
    char unknown_40[0x40];
    unsigned short diffuseColor;
    char unknown_82[6];
};
struct ZoneContainerRenderEntry
{
    unsigned short containerID;
    short state;
    char unknown_4[4];
    ZoneContainerRenderPart mainPart;
    ZoneContainerRenderPart brokenPart;
    ZoneContainerRenderPart fragments[4];
    char unknown_338[0x30];
};
