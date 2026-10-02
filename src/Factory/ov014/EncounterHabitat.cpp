#include "EncounterHabitat.h"

extern "C" {
unsigned short* func_ov014_02189380(EncounterHabitat* table)
{
    HabitatEntry* entries = (HabitatEntry*)(table->monsters + table->header.monsterCount);
    return (unsigned short*)(entries + table->header.entryCount);
}

unsigned int* func_ov014_02189398(EncounterHabitat* table)
{
    char* start = (char*)table->monsters;
    char* end = (char*)(func_ov014_02189380(table) + table->header.zoneCount);
    unsigned int offset = (end - start + 3) & ~3;
    return (unsigned int*)(start + offset);
}

HabitatMonster* func_ov014_021893c4(EncounterHabitat* table, int monsterId)
{
    if (monsterId < 0) return table->monsters;
    return func_ov014_021892d4(table, monsterId, func_ov014_02188b18);
}

HabitatEntry* func_ov014_021893e4(EncounterHabitat* table, HabitatMonster* monster)
{
    if (!monster) return 0;
    HabitatEntry* entries = (HabitatEntry*)(table->monsters + table->header.monsterCount);
    return entries + monster->entryOffset;
}

HabitatEntry* func_ov014_0218940c(EncounterHabitat* table, int index, HabitatMonster* monster)
{
    if (!monster) return 0;
    return func_ov014_021893e4(table, monster) + index;
}

unsigned int* func_ov014_02189430(EncounterHabitat* table, int index, HabitatMonster* monster)
{
    if (!monster) return 0;
    HabitatEntry* entry = func_ov014_0218940c(table, index, monster);
    if (!entry) return 0;
    return func_ov014_02189398(table) + entry->stringIndex;
}
}
