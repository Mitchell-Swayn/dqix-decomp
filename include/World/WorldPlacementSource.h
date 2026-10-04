#pragma once
#include "Graphics/Vector.h"
#include "Resource/Script.h"

// Partial placement-source state. Only fields established by recovered methods
// are named; the two byte blocks retain their observed reset extents.
struct WorldPlacementSource
{
    struct PersistentState
    {
        unsigned int unknown0 : 9, count : 4, unknown13 : 4, flags : 8;
        unsigned int unknown25 : 4, unknown29 : 2, available : 1;
    };
    struct Record
    {
        unsigned int value : 16, index : 7, type : 2, unknown25 : 7;
        unsigned int kind : 4, parameter : 9, unknown13 : 4, slotCount : 4;
        unsigned int flags : 8, unknown29 : 3;
        PersistentState* state;
        Vector3i positions[8];
        Record* next;
    };
    char mapPrefix[4];
    Record* head;
    unsigned short count;
    unsigned char unknownA;
    short* randomValues;
    struct Variant
    {
        unsigned short parameter;
        unsigned char unknown2;
        unsigned char slotCount;
    } variants[8];

    static int AcceptOpcode100(Script::Parameter*, int);
    static int AcceptOpcode101(Script::Parameter*, int);
    void LoadForMap(const char* name);
    static int ReadVariantTable(Script::Parameter* parameters, int numParameters);
    static int ReadSpecialRecord(Script::Parameter* parameters, int numParameters);
    static int ReadRecord(Script::Parameter* parameters, int numParameters);
    WorldPlacementSource();
    static WorldPlacementSource* GetInstance();
    void AppendRecord(Record* record);
    Record* FindRecord(int index);
    int GetRandomValue();
    void Reset();
    void ClearPlacements();
    bool IsMapEligible(const char* name);
};
