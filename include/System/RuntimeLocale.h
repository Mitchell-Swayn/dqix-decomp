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
extern RuntimeCharacterMethods data_020eece4;
extern RuntimeLocaleAuxiliary data_020eecec;
extern unsigned short data_020eee30[96];
extern RuntimeLocale data_020eed28;
typedef char RuntimeCharacterMethodsSizeCheck[sizeof(RuntimeCharacterMethods) == 8 ? 1 : -1];
typedef char RuntimeLocaleSizeCheck[sizeof(RuntimeLocale) == 12 ? 1 : -1];
typedef char RuntimeTimeFormatsSizeCheck[sizeof(RuntimeTimeFormats) == 32 ? 1 : -1];
typedef char RuntimeLocaleAuxiliarySizeCheck[sizeof(RuntimeLocaleAuxiliary) == 16 ? 1 : -1];
