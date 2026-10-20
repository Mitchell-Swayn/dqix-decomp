#include <globaldefs.h>
ARM
extern "C" unsigned int SpellTable_GetMappingCount(void *);
extern "C" unsigned int SkillTable_GetEntryCount(void *);
// Original: arm9/ov002 @ 0x0215EDC8; symbol: Unclassified_HasPositiveLinkedRecord; size: 0x3C.
// Tests for a positive linked count and positive word in the neighboring record.
extern "C" int PartyMenu_HasLoadedSpellAndSkillTables(void *object) {
int n=(int)SpellTable_GetMappingCount((char*)object+0x2444); if(n>0){ int v=(int)SkillTable_GetEntryCount((char*)object+0x243c); if(v>0)return 1;} return 0;
}
