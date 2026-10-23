#include <globaldefs.h>

extern "C" int GameResources_IsSelectedScreenBrightnessWithinExtremes(char*,int);

// Original: arm9/main @ 0x0203B5E0; symbol: func_0203b5e0; size: 0x18.
extern "C" ARM bool GameResources_IsSelectedScreenBrightnessAtOrBeyondExtreme(char* resources,int screen) {
    return GameResources_IsSelectedScreenBrightnessWithinExtremes(resources,screen) == 0;
}
