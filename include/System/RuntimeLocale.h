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
struct RuntimeLocaleAuxiliary;
struct RuntimeLocale {
    RuntimeTimeFormats* time;
    RuntimeLocaleAuxiliary* auxiliary;
    RuntimeCharacterMethods* characters;
};
extern RuntimeCharacterMethods data_020eece4;
extern RuntimeLocale data_020eed28;
typedef char RuntimeCharacterMethodsSizeCheck[sizeof(RuntimeCharacterMethods) == 8 ? 1 : -1];
typedef char RuntimeLocaleSizeCheck[sizeof(RuntimeLocale) == 12 ? 1 : -1];
typedef char RuntimeTimeFormatsSizeCheck[sizeof(RuntimeTimeFormats) == 32 ? 1 : -1];
