#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" int CharacterState_GetLearnedSkillMask(unsigned char*,int);
struct Entry { unsigned short value,pad; };
// Original data: arm9/main @ 0x20ee710; symbol: data_020ee710.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0900.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Entry GameStateTestMappedObjectBit_UnknownRoleInitializedBytes[];
// Original data: arm9/main @ 0x20ee712; symbol: data_020ee712.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0100140002001f00030040000400610005004b0006007700070082000800b9000900c4000a00fb000b00da000c002a000d00ffffffff.
// Observed span: 54 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Entry GameStateTestMappedObjectBit_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/main @ 0x020DD200; symbol: func_020dd200; size: 0x90.
extern "C" int GameState_TestMappedObjectBit(int index,int key) {
int result=0;
unsigned char* object=(unsigned char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),index);
if(!object)return result;
for(unsigned char i=0;GameStateTestMappedObjectBit_UnknownRoleInitializedBytes[i].value!=65535;++i){
int mapped=GameStateTestMappedObjectBit_UnknownRoleInitializedBytes_Variant2[i].value&255;
if(mapped==key){if(CharacterState_GetLearnedSkillMask(*(unsigned char**)(object+0x150),GameStateTestMappedObjectBit_UnknownRoleInitializedBytes[i].value))result=1;break;}
}
return result;
}
