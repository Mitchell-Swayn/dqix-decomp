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
    short unknown_4;
    char unknown_6[2];
    ZoneContainerRenderPart mainPart;
    ZoneContainerRenderPart brokenPart;
    ZoneContainerRenderPart fragments[4];
    char unknown_338[0x30];
};

struct ZoneChestEntry
{
    Vector3i position;
    unsigned short unknown_c;
    unsigned short lidAngle;
    unsigned short timer;
    short loadHandle;
    signed char ownerIndex;
    char unknown_15;
    unsigned char state;
    char unknown_17;
    unsigned char unknown_18;
    unsigned char unknown_19;
    short unknown_1a;
    unsigned short unknown_1c;
    char unknown_1e[2];
    int unknown_20;
};
void ActivateZoneChest(ZoneChestEntry* chest, int ownerIndex, bool reset, bool force);
void SetVector3iComponents(Vector3i* vector, int x, int y, int z);
void ResetZoneContainer(ZoneContainerRenderEntry* entry);
void ResetZoneChest(ZoneChestEntry* chest);
struct GrottoTileData;
void ResetGrottoTileData(GrottoTileData* tile);
void ResetZoneFragmentParts(ZoneContainerRenderPart* parts);
