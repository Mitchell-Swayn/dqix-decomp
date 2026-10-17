#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
extern "C" {
extern char *data_020f015c[];
// Original: arm9/main @ 0x020488EC; symbol: func_020488ec; size: 0x48.
void Object_BuildNameWithTypeSuffix(char *p){memset(p+0x14c,0,0x30);strcpy(p+0x14c,*(char **)(p+0x148)+0x2c);strcat(p+0x14c,data_020f015c[(*(unsigned char **)(p+0x138))[0x25]]);}
}
