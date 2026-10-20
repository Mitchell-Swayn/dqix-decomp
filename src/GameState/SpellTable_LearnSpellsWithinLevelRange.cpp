#include <globaldefs.h>
#include <std_library_functions.h>
#pragma always_inline on
class GameObject;
struct SpellLearningEntry {unsigned short spell, level;};
struct SpellLearningData {
    unsigned char prefix[0x10c];
    SpellLearningEntry byVocation[13][20];
    int counts[13];
};
struct SpellLearningTable {SpellLearningData* data;};
struct SpellLearningCharacter {
    unsigned char prefix[0x16c];
    unsigned short levels[13];
    unsigned char suffix[0x950-0x186];
    unsigned vocation;
};
extern "C" unsigned GameObject_GetLinkedIndexedState(int);
extern "C" void CharacterState_LearnSpell(unsigned char*,int);
#pragma force_active on
// Original: arm9/main @ 0x0209AA54; symbol: func_0209aa54; size: 0xCC.
// Learns vocation spells above a previous level and at or below the current level.
extern "C" ARM int SpellTable_LearnSpellsWithinLevelRange(SpellLearningTable* table, GameObject* object, unsigned char* output, int previousLevel)
{
    // Preserve the two original field-address validity checks.
    unsigned dataAddress = (unsigned)table->data;
    if (dataAddress + offsetof(SpellLearningData, byVocation) == 0) return 0;
    if (dataAddress + offsetof(SpellLearningData, counts) == 0) return 0;
    SpellLearningCharacter* character = (SpellLearningCharacter*)GameObject_GetLinkedIndexedState((int)object);
    if (!character) return 0;
    int vocation = character->vocation;
    int learned = 0;
    for (int i=0; i<table->data->counts[vocation]; ++i) {
        int level = table->data->byVocation[vocation][i].level;
        unsigned short spell = table->data->byVocation[vocation][i].spell;
        if (character->levels[character->vocation] >= level && level > previousLevel) {
            CharacterState_LearnSpell((unsigned char*)character,spell);
            output[learned++] = spell;
        }
    }
    return learned;
}
#pragma force_active off
