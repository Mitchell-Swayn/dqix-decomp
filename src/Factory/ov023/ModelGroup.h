#pragma once
#include "World/Object3D.h"
#include "Filesystem/BackgroundLoader.h"

struct ZoneState2754;

// Partial layout of the 0xc20-byte model group allocated by overlay 23.
// The ten Object3D instances are real contiguous subobjects, not raw offsets.
struct Ov23ModelGroup
{
    Object3D objects[10];
    SafeAllocator allocators[10];
    SafeAllocator auxiliaryAllocator;
    unsigned char unknown_794[0x460];
    short taskIDs[12];
    ZoneState2754* zoneState;
    unsigned char unknown_c10;
    unsigned char flag_c11;
    unsigned char loading_c12;
    unsigned char unknown_c13;
    unsigned char enabled_c14;
    unsigned char flag_c15;
    unsigned char unknown_c16[2];
    void* unknown_c18;
    unsigned int unknown_c1c;
};

typedef char ObjectSizeCheck[sizeof(Object3D) == 0xac ? 1 : -1];
typedef char GroupSizeCheck[sizeof(Ov23ModelGroup) == 0xc20 ? 1 : -1];
typedef char TaskOffsetCheck[offsetof(Ov23ModelGroup, taskIDs) == 0xbf4 ? 1 : -1];
typedef char StateOffsetCheck[offsetof(Ov23ModelGroup, zoneState) == 0xc0c ? 1 : -1];
typedef char FlagOffsetCheck[offsetof(Ov23ModelGroup, flag_c11) == 0xc11 ? 1 : -1];
typedef char RotationOffsetCheck[offsetof(Object3D, rotation_) == 0x50 ? 1 : -1];
typedef char AllocatorOffsetCheck[offsetof(Ov23ModelGroup, allocators) == 0x6b8 ? 1 : -1];
typedef char AuxiliaryOffsetCheck[offsetof(Ov23ModelGroup, auxiliaryAllocator) == 0x780 ? 1 : -1];
typedef char LoadingOffsetCheck[offsetof(Ov23ModelGroup, loading_c12) == 0xc12 ? 1 : -1];
typedef char TailPointerOffsetCheck[offsetof(Ov23ModelGroup, unknown_c18) == 0xc18 ? 1 : -1];
