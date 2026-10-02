#pragma once

#include "std_library_functions.h"

// The loaded enchab table has a 12-byte header, followed by four packed arrays:
// monster records, habitat entries, zone IDs and string offsets. Strings follow
// that aligned payload. Names describe observed consumers, not original names.
struct HabitatMonster
{
    unsigned short monsterId;
    unsigned short entryOffset : 12;
    unsigned short entryCount : 4;
};

struct HabitatEntry
{
    unsigned short stringIndex;
    unsigned short visited : 1;
    unsigned short zoneOffset : 11;
    unsigned short zoneCount : 4;
};

struct HabitatHeader
{
    unsigned short monsterCount;
    unsigned short entryCount;
    unsigned short zoneCount;
    unsigned short stringCount;
    unsigned int stringBytes : 31;
    unsigned int relocated : 1;
};

struct EncounterHabitat
{
    HabitatHeader header;
    HabitatMonster* monsters;
    char* strings;
};

typedef void (*HabitatVisitor)(EncounterHabitat*, HabitatMonster*);
typedef int (*HabitatKey)(HabitatMonster*);

typedef char HabitatMonsterSize[sizeof(HabitatMonster) == 4 ? 1 : -1];
typedef char HabitatEntrySize[sizeof(HabitatEntry) == 4 ? 1 : -1];
typedef char HabitatHeaderSize[sizeof(HabitatHeader) == 12 ? 1 : -1];
typedef char EncounterHabitatSize[sizeof(EncounterHabitat) == 20 ? 1 : -1];

extern "C" {
int func_ov014_02188b18(HabitatMonster*);
int func_ov014_021891f0(EncounterHabitat*, HabitatVisitor);
// Payload size remains original fallback after the recorded ten-variant cap.
unsigned int func_ov014_0218934c(EncounterHabitat*);
HabitatMonster* func_ov014_021892d4(EncounterHabitat*, int, HabitatKey);
unsigned short* func_ov014_02189380(EncounterHabitat*);
unsigned int* func_ov014_02189398(EncounterHabitat*);
HabitatEntry* func_ov014_021893e4(EncounterHabitat*, HabitatMonster*);
HabitatEntry* func_ov014_0218940c(EncounterHabitat*, int, HabitatMonster*);
}
