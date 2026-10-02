#pragma once

// Partial placement-source state. Only fields established by recovered methods
// are named; the two byte blocks retain their observed reset extents.
struct WorldPlacementSource
{
    struct Record;
    unsigned char unknown0[4];
    Record* head;
    unsigned short count;
    unsigned char unknownA;
    void* unknownC;
    unsigned char unknown10[32];

    WorldPlacementSource();
    static WorldPlacementSource* GetInstance();
    void Reset();
    void ClearPlacements();
    bool IsMapEligible(const char* name);
};
