#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov009 @ 0x218a9bc; symbol: data_ov009_0218a9bc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000102030405060708090000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov009.md.
struct Map{signed char entries[10];};extern "C" Map CharacterCreationUpdateResourceInitialization_UnknownRoleInitializedBytes_Variant6;
// Original: arm9/ov009 @ 0x02188B14; symbol: Graphics_MapConditionalMenuIndex; size: 0xe4.
extern "C" int CharacterCreation_MapGenderDependentAppearanceChoice(unsigned char* self,int kind,int index){Map map=CharacterCreationUpdateResourceInitialization_UnknownRoleInitializedBytes_Variant6;if(kind==5){if(self[0xda3]){map.entries[0]=1;map.entries[1]=0;}else{map.entries[0]=4;map.entries[1]=0;map.entries[2]=1;map.entries[3]=2;map.entries[4]=3;}return map.entries[index];}if(kind==3){if(self[0xda3]){map.entries[0]=6;map.entries[1]=0;map.entries[2]=1;map.entries[3]=2;map.entries[4]=3;map.entries[5]=4;map.entries[6]=5;}return map.entries[index];}return index;}
