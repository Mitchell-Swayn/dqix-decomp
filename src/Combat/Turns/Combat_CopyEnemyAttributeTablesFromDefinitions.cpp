#include <globaldefs.h>
ARM
extern "C" void* MonsterBattleData_FindEntryById(void*, int);
struct AttributeBytes { unsigned char values[22]; };
struct EnemyGroupRecord {
    unsigned short species;
    unsigned char unknown02[8];
    unsigned char count:4;
    unsigned char flags:4;
    unsigned char unknown0B[13];
};
struct EnemyStateRecord { unsigned char unknown00[0x3e]; AttributeBytes attributes; unsigned char byte54, byte55; unsigned char unknown56[0x4e]; };
struct MonsterDefinitionProjection { unsigned char unknown00[0x6c]; AttributeBytes attributes; unsigned char byte82, byte83; };
struct BattleProjection { unsigned char unknown00[0x81b1]; unsigned char groupFlagsLow:4; unsigned char groupCount:2; unsigned char groupFlagsHigh:2; unsigned char unknown81B2[2]; EnemyGroupRecord groups[3]; };
#pragma force_active on
// Original: arm9/ov000 @ 0x0215F03C; symbol: func_ov000_0215f03c; size: 0xd4.
// Copies per-species attribute bytes into every enemy state belonging to the encounter groups.
extern "C" void Combat_CopyEnemyAttributeTablesFromDefinitions(unsigned char* battle)
{
    unsigned char* resources = *(unsigned char**)(battle + 0x8e18);
    unsigned char* definitions = resources + 0x284;
    EnemyStateRecord* states = (EnemyStateRecord*)(resources + 0x158);
    EnemyGroupRecord* groups = ((BattleProjection*)battle)->groups;
    for (int groupIndex = 0; groupIndex < ((BattleProjection*)battle)->groupCount; ++groupIndex) {
        int species = groups[groupIndex].species;
        // The original byte cursor is bounded by the encoded count, not a proven array type.
        unsigned char* indices = (unsigned char*)&groups[groupIndex] + 2;
        for (int index = 0; index < groups[groupIndex].count; ++index) {
            EnemyStateRecord* state = &states[indices[index]];
            MonsterDefinitionProjection* definition = (MonsterDefinitionProjection*)MonsterBattleData_FindEntryById(definitions + 0x400, species);
            if (definition) {
                state->attributes = definition->attributes;
                state->byte54 = definition->byte82;
                state->byte55 = definition->byte83;
            }
        }
    }
}
#pragma force_active off
