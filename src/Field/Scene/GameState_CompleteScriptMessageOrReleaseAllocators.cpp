#include <globaldefs.h>
ARM
extern "C" char* GameResources_GetInstance(...);
extern "C" int Field_SpawnSharedPresentationEffectAtPosition(...);
extern "C" char* Script_ReadGlobalExecutionValue(...);
extern "C" int Field_DrawFloatingContainerLootSprite(...);
extern "C" int GameObject_RequestMovementInputEnable(...);
extern "C" int SoundSfx_StartCurrentSequenceArchiveEntry(...);
extern "C" void Text_EnqueueThreeEntryMessage(void*,const char*,unsigned char,unsigned char,unsigned char,unsigned char);
extern "C" int Memory_DestroyTwoAllocatorsAndRestoreGameFlags(...);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage[];
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov017 @ 0x021B5F00; symbol: GameState_CompleteScriptMessageOrReleaseAllocators; size: 0xc0.
// GameState CompleteScriptMessageOrReleaseAllocators from listed field operations and calls.
extern "C" int GameState_CompleteScriptMessageOrReleaseAllocators(char* self){char* resources=GameResources_GetInstance();if(B(self,0x54)){Field_SpawnSharedPresentationEffectAtPosition(resources,self+0x2c,0);Text_EnqueueThreeEntryMessage(Script_ReadGlobalExecutionValue(),(*(char* volatile*)(self+0x3c)),0,0,1,0);return 5;}Field_DrawFloatingContainerLootSprite(self);GameObject_RequestMovementInputEnable(P(self,0x1c));if(S((*(char* volatile*)(self+0x3c)),0)){Text_EnqueueThreeEntryMessage(Script_ReadGlobalExecutionValue(),(*(char* volatile*)(self+0x3c)),0,0,1,0);SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,14,0);return 5;}Memory_DestroyTwoAllocatorsAndRestoreGameFlags(self);B(self,1)=1;return 6;}
