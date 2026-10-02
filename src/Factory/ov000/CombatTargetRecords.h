#pragma once

// Result nodes are allocated with a 0x24-byte stride by 0x0215e958.
// Their payload is not yet fully understood; the link is a separate field.
struct CombatResultNode {
    unsigned char unknownPayload[0x20];
    CombatResultNode* next;
};

// 0x0215e938 allocates 0x24-byte records. Resetting the payload alone
// (0x0215fef0) is distinct from resetting the pool link (0x02157cdc).
struct CombatTargetPayload {
    CombatResultNode* resultHeads[3];
    short identifier;
    short targetIds[3];
    unsigned char targetValues[3];
    unsigned char targetCount;
    unsigned char resultCounts[3];
    unsigned char unknown1b[5];
};

struct CombatTargetRecord {
    CombatTargetPayload payload;
    CombatTargetRecord* next;
};

typedef char CombatResultNodeSizeCheck[sizeof(CombatResultNode) == 0x24 ? 1 : -1];
typedef char CombatTargetPayloadSizeCheck[sizeof(CombatTargetPayload) == 0x20 ? 1 : -1];
typedef char CombatTargetRecordSizeCheck[sizeof(CombatTargetRecord) == 0x24 ? 1 : -1];
