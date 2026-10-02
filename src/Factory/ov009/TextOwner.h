#ifndef FACTORY_OV009_TEXT_OWNER_H
#define FACTORY_OV009_TEXT_OWNER_H
#include "Memory/SafeAllocator.h"
#include "TextPattern.h"
#include "TextSelection.h"
#include "World/Object3D.h"
#include "World/Zone3DEmbeddedState.h"

// Names describe use in the lifecycle routines. Opaque subobjects retain
// their observed extents; their internal behavior belongs to other units.
struct TextOwner {
    SafeAllocator arenas[9];
    SafeAllocator* auxiliaryArena;
    SafeAllocator* pairArenas;
    unsigned char unknown_bc[4];
    void* resourceA;
    void* resourceB;
    ZoneState2754 zoneState;
    TextResourceTable resourceTable;
    void* unknown_f8;
    TextPatternContext pattern;
    unsigned char widgets[6][0x20];
    unsigned char controllers[2][0xbc];
    unsigned char primaryElements[1][0xe0];
    unsigned char secondaryElements[4][0xe0];
    void* unknown_7d0;
    void* unknown_7d4;
    void* buffers[6];
    void* handles[6];
    unsigned char unknown_808[0x70];
    Object3D objectA;
    unsigned char unknown_924[0x2c8];
    unsigned char unknown_bec[0x40];
    TextSelectionIndices selectionIndices;
    short selectedIds[6];
    signed char state;
    unsigned char substate;
    unsigned char unknown_c5a[0x7e];
    Object3D objectB;
    unsigned char unknown_d84;
    unsigned char controllerResult;
    unsigned char unknown_d86[2];
    int unknown_d88;
    int unknown_d8c;
    int unknown_d90;
    unsigned char unknown_d94;
    unsigned char mode;
    short unknown_d96;
    short unknown_d98;
    unsigned char unknown_d9a[2];
    unsigned int flags;
    unsigned char enabled[2];
    unsigned char category;
    unsigned char selectedTextBuffer;
    unsigned char pairs[6][2];
    char** textBuffers;
    unsigned char wildcard;
    unsigned char unknown_db5;
    unsigned char unknown_db6;
};
typedef char TextOwnerModeCheck[offsetof(TextOwner, mode) == 0xd95 ? 1 : -1];
typedef char TextOwnerBufferCheck[offsetof(TextOwner, textBuffers) == 0xdb0 ? 1 : -1];
typedef char TextOwnerPatternCheck[offsetof(TextOwner, pattern) == 0xfc ? 1 : -1];
typedef char TextOwnerObjectACheck[offsetof(TextOwner, objectA) == 0x878 ? 1 : -1];
typedef char TextOwnerObjectBCheck[offsetof(TextOwner, objectB) == 0xcd8 ? 1 : -1];
typedef char TextOwnerStateCheck[offsetof(TextOwner, state) == 0xc58 ? 1 : -1];
typedef char TextOwnerSelectionCheck[offsetof(TextOwner, selectionIndices) == 0xc2c ? 1 : -1];
#endif
