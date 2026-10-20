#pragma once

struct RuntimeCharacterMethods {
    int (*decode)(unsigned short*, const char*, unsigned int);
    int (*encode)(char*, unsigned short);
};
struct RuntimeTimeFormats {
    const char* amPm;
    const char* dateTime;
    const char* time12Hour;
    const char* date;
    const char* time24Hour;
    const char* weekdays;
    const char* months;
    const char* empty;
};
struct RuntimeLocaleAuxiliary {
    unsigned int unknown0;
    unsigned int unknown4;
    unsigned int unknown8;
    const unsigned short* table;
};
struct RuntimeLocale {
    RuntimeTimeFormats* time;
    RuntimeLocaleAuxiliary* auxiliary;
    RuntimeCharacterMethods* characters;
};
// Original data: arm9/main @ 0x20eece4; symbol: data_020eece4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 6019000298190002.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern RuntimeCharacterMethods SharedData_UnknownRoleProcedureReferenceRecords_Variant26;
// Original data: arm9/main @ 0x20eecec; symbol: data_020eecec.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 200000006e0000000000000030ee0e02.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern RuntimeLocaleAuxiliary SharedData_UnknownRoleDataReferences_Variant9;
// Original data: arm9/main @ 0x20eee30; symbol: data_020eee30.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0100020003000400050006000700080009000a000b000c000d000e000f0010002100220023002400250026002700280029002a00110012001300140015001600 ...; full span in module reference.
// Observed span: 192 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short SharedData_UnknownRoleInitializedBytes_Variant54[96];
// Original data: arm9/main @ 0x20eed28; symbol: data_020eed28.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex fcec0e02ecec0e02e4ec0e02.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern RuntimeLocale RuntimeWideConversionEncodeWideCharacter_UnknownRoleDataReferences;
typedef char RuntimeCharacterMethodsSizeCheck[sizeof(RuntimeCharacterMethods) == 8 ? 1 : -1];
typedef char RuntimeLocaleSizeCheck[sizeof(RuntimeLocale) == 12 ? 1 : -1];
typedef char RuntimeTimeFormatsSizeCheck[sizeof(RuntimeTimeFormats) == 32 ? 1 : -1];
typedef char RuntimeLocaleAuxiliarySizeCheck[sizeof(RuntimeLocaleAuxiliary) == 16 ? 1 : -1];
