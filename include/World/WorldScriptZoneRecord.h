#pragma once
#include "Graphics/Vector.h"

// A script record selected against the active zone-information selector.
// Numeric field meanings remain neutral until their consumers are recovered.
struct WorldScriptZoneRecord
{
    signed char unknown0;
    char unknown1;
    unsigned short selector0;
    char name[16];
    unsigned char unknown14;
    char unknown15[3];
    float unknown18;
    Vector3fix vector;
    fix16_t unknown28;
    unsigned short selector1;
};
struct Zone3D_StructPtr_8;
struct WorldScriptZoneLoadingState
{
    int matched;
    Zone3D_StructPtr_8* info;
    WorldScriptZoneRecord* record;
};
typedef char WorldScriptZoneRecordSizeCheck[
    sizeof(WorldScriptZoneRecord) == 44 ? 1 : -1];
typedef char WorldScriptZoneLoadingStateSizeCheck[
    sizeof(WorldScriptZoneLoadingState) == 12 ? 1 : -1];
extern "C" WorldScriptZoneLoadingState data_02108fc8;
