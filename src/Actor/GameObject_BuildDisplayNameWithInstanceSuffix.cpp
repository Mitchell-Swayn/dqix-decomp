#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
extern "C" {
// Original data: arm9/main @ 0x20f015c; symbol: data_020f015c.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 28010f0259010f0256010f0253010f0250010f0229010f024a010f0247010f0244010f0241010f023e010f023b010f0238010f0235010f0232010f022f010f02 ...; full span in module reference.
// Observed span: 72 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char *GameObjectBuildDisplayNameWithInstanceSuffix_UnknownRoleDataReferences[];
// Original: arm9/main @ 0x020488EC; symbol: func_020488ec; size: 0x48.
void GameObject_BuildDisplayNameWithInstanceSuffix(char *p){memset(p+0x14c,0,0x30);strcpy(p+0x14c,*(char **)(p+0x148)+0x2c);strcat(p+0x14c,GameObjectBuildDisplayNameWithInstanceSuffix_UnknownRoleDataReferences[(*(unsigned char **)(p+0x138))[0x25]]);}
}
