#pragma once

#include "globaldefs.h"
#include "std_library_functions.h"
#include "World/Zone3DEmbeddedState.h"

// Partial menu layout established by the initializer at 0x0215505c and
// inventory callers. The selected owner is distinct from a lookup's owner
// argument: party item reads use this field, while counts use the argument.
struct InventoryMenuState {
    unsigned char unknown_0000_[0x7ec];
    ZoneState2754 itemTable_;
    unsigned char unknown_0804_[0x1c20 - 0x804];
    signed char selectedOwner_;
    unsigned char unknown_1c21_[0x1c50 - 0x1c21];
    int ownerCount_;
    int owners_[5];
    unsigned char unknown_1c68_[5];
    unsigned char unknown_1c6d_;
    signed char availableMembers_[5];
    signed char availableMemberCount_;
};

typedef char SelectedOwnerOffsetCheck[
    offsetof(InventoryMenuState, selectedOwner_) == 0x1c20 ? 1 : -1];
typedef char ItemTableOffsetCheck[
    offsetof(InventoryMenuState, itemTable_) == 0x7ec ? 1 : -1];
typedef char OwnerOffsetCheck[
    offsetof(InventoryMenuState, owners_) == 0x1c54 ? 1 : -1];
typedef char AvailableMemberOffsetCheck[
    offsetof(InventoryMenuState, availableMembers_) == 0x1c6e ? 1 : -1];
typedef char AvailableMemberCountOffsetCheck[
    offsetof(InventoryMenuState, availableMemberCount_) == 0x1c73 ? 1 : -1];
