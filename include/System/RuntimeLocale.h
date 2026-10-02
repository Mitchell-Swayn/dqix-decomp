#pragma once

struct RuntimeCharacterMethods {
    int (*decode)(unsigned short*, const char*, unsigned int);
    int (*encode)(char*, unsigned short);
};
struct RuntimeTimeFormats;
struct RuntimeNumericFormats;
struct RuntimeLocale {
    RuntimeTimeFormats* time;
    RuntimeNumericFormats* numeric;
    RuntimeCharacterMethods* characters;
};
extern RuntimeCharacterMethods data_020eece4;
extern RuntimeLocale data_020eed28;
typedef char RuntimeCharacterMethodsSizeCheck[sizeof(RuntimeCharacterMethods) == 8 ? 1 : -1];
typedef char RuntimeLocaleSizeCheck[sizeof(RuntimeLocale) == 12 ? 1 : -1];
