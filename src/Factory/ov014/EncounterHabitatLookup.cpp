#include "EncounterHabitat.h"

extern "C" {
int func_ov014_021891f0(EncounterHabitat* table, HabitatVisitor visitor)
{
    int count;
    HabitatMonster* record = table->monsters;
    if (!record || !(count = table->header.monsterCount) || !visitor) return 0;
    for (int i = 0; i < count; i++, record++) visitor(table, record);
    return 1;
}

int func_ov014_02189244(EncounterHabitat* table, HabitatHeader* file,
                        bool* alreadyRelocated, HabitatVisitor visitor)
{
    *alreadyRelocated = false;
    if (!file) return 0;
    memcpy(table, file, sizeof(HabitatHeader));
    table->monsters = (HabitatMonster*)((char*)file + 12);
    table->strings = (char*)file + (func_ov014_0218934c(table) + 12);
    if (table->header.relocated)
    {
        *alreadyRelocated = true;
        return 1;
    }
    func_ov014_021891f0(table, visitor);
    table->header.relocated = 1;
    file->relocated = 1;
    return 1;
}

HabitatMonster* func_ov014_021892d4(EncounterHabitat* table, int key, HabitatKey getKey)
{
    HabitatMonster* records = table->monsters;
    if (!records || !getKey) return 0;
    int count = table->header.monsterCount;
    if (!count) return 0;
    int low = 0;
    int high = count - 1;
    while (low <= high)
    {
        int middle = low + ((high - low + 1) >> 1);
        HabitatMonster* record = records + middle;
        int value = getKey(record);
        if (value == key) return record;
        if (value > key) high = middle - 1;
        else low = middle + 1;
    }
    return 0;
}
}
