#include <globaldefs.h>
struct SpellEntry
{
    unsigned short spell, level;
};
struct SpellTable
{
    char prefix[0x10c];
    SpellEntry byVocation[13][20];
    int counts[13];
};
// Original: arm9/main @ 0x0209AB20; symbol: func_0209ab20; size: 0x5C.
// Collects spell IDs whose required level does not exceed the supplied vocation level.
extern "C" int SpellTable_CollectSpellsAtVocationLevel(SpellTable** p, int vocation, int level, unsigned char* out)
{
    int count = 0;
    for (int i = 0; i < (*p)->counts[vocation]; i++)
    {
        unsigned short learnedLevel = (*p)->byVocation[vocation][i].level;
        unsigned short spell = (*p)->byVocation[vocation][i].spell;
        if (learnedLevel <= level)
        {
            out[count++] = spell;
        }
    }
    return count;
}

