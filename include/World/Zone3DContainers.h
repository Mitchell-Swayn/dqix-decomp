#pragma once
#include "Graphics/Vector.h"

// The eight-byte member owns a count and pointer; its payload is unresolved.
struct ZoneRenderPartEntries
{
    int count;
    void* entries;
    ZoneRenderPartEntries() { Reset(); }
    ~ZoneRenderPartEntries() { Reset(); }
    void Reset();
};

// Partial layout established by container creation, binding and reset routines.
struct ZoneContainerRenderPart
{
    void* unknown_0;
    unsigned short unknown_4;
    unsigned short unknown_6;
    void* unknown_8;
    void* unknown_c;
    void* unknown_10;
    ZoneRenderPartEntries entries;
    Vector3i position;
    Vector3i unknown_28;
    Vector3i scale;
    char unknown_40[0x30];
    int unknown_70;
    int unknown_74;
    int unknown_78;
    int unknown_7c;
    unsigned short diffuseColor;
    unsigned short unknown_82;
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char unknownFlags : 5;
    char unknown_85[3];

    ZoneContainerRenderPart();
    ~ZoneContainerRenderPart();
    void Reset();
    void ResetIfFlag0();
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
