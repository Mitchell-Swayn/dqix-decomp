#pragma once

#include "CombatTargetRecords.h"

// 0x0215e918 and the initialization loops at 0x0215d114 use a 0x34
// stride. The payload reset excludes the pool link at 0x30.
struct CombatActionPayload {
    // 0x0215bccc clears six heads/counts; ov025 queries categories 0..5.
    CombatResultNode* resultHeads[6];
    unsigned char unknown18[4];
    short identifier;
    unsigned char unknown1e[2];
    short combatantId;
    unsigned char unknown22[4];
    unsigned char resultCounts[6];
    unsigned char unknown2c[4];
};

struct CombatActionRecord {
    CombatActionPayload payload;
    CombatActionRecord* next;
};

// Reset independently clears this 0x0e-byte subobject at 0x18.
// The final halfword is also written from combatant data by callers.
struct CombatActionValues {
    unsigned char unknown18[12];
    unsigned short value;
};

// 0x0215e9d8 returns these records with a 0x28-byte stride.
// Callers append 0x34-byte action records and 0x24-byte target records
// to separate lists; the two counts and head pointers are independent.
struct CombatActionGroup {
    unsigned char unknown00[6];
    short identifier;
    unsigned char actionCount;
    unsigned char targetCount;
    unsigned char unknown0a[6];
    CombatActionRecord* actionHead;
    CombatTargetRecord* targetHead;
    CombatActionValues values;
    unsigned char unknown26[2];
};

typedef char CombatActionPayloadSizeCheck[sizeof(CombatActionPayload) == 0x30 ? 1 : -1];
typedef char CombatActionRecordSizeCheck[sizeof(CombatActionRecord) == 0x34 ? 1 : -1];
typedef char CombatActionValuesSizeCheck[sizeof(CombatActionValues) == 0x0e ? 1 : -1];
typedef char CombatActionGroupSizeCheck[sizeof(CombatActionGroup) == 0x28 ? 1 : -1];
