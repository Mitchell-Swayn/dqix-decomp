#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/LightingManager.h>
struct Node;
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" void Lighting_ApplyTintToModelTree(Node*,void*);
extern "C" void* Zone3D_GetMainInstance();



// Original data: arm9/ov001 @ 0x2164d14; symbol: data_ov001_02164d14.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000034430000f041000034430000f041.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" volatile unsigned char LightingApplyScriptPresetAndUpdateScene_UnknownRoleInitializedBytes[];
// Original data: arm9/ov001 @ 0x2164d34; symbol: data_ov001_02164d34.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char UpdateTimeOfDayLightingAndApplyNodeTints_UnknownRoleInitializedBytes[];
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" volatile unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x02160504; symbol: func_ov001_02160504; size: 0xD0.
extern "C" int UpdateTimeOfDayLightingAndApplyNodeTints(){GameState* game=GameState::GetInstance();char* state=(char*)Zone3D_GetMainInstance();unsigned char* light=(unsigned char*)LightingManager::GetInstance();if(B(state,0x834))return 1;int time=game->GetTimeOfDay();U(light,0x98)=time;unsigned flags=U(EventGetObjectSession_UnknownRoleZeroInitializedStorage,12);if(!(flags&1)){flags|=1;unsigned value=U(EventGetObjectSession_UnknownRoleZeroInitializedStorage,0);U(LightingApplyScriptPresetAndUpdateScene_UnknownRoleInitializedBytes,0x20)=value;U(LightingApplyScriptPresetAndUpdateScene_UnknownRoleInitializedBytes,0x24)=U(EventGetObjectSession_UnknownRoleZeroInitializedStorage,0x10);U(LightingApplyScriptPresetAndUpdateScene_UnknownRoleInitializedBytes,0x28)=U(EventGetObjectSession_UnknownRoleZeroInitializedStorage,0x30);U(LightingApplyScriptPresetAndUpdateScene_UnknownRoleInitializedBytes,0x2c)=U(EventGetObjectSession_UnknownRoleZeroInitializedStorage,0x2c);U(EventGetObjectSession_UnknownRoleZeroInitializedStorage,12)=flags;}U(light,0x94)=U(UpdateTimeOfDayLightingAndApplyNodeTints_UnknownRoleInitializedBytes,time*4);if(U(state,0x410)==1){unsigned char* node=(unsigned char*)U(state,0x41c);while(node){if(U(node,0x44))Lighting_ApplyTintToModelTree((Node*)U(node,0x44),node+4);node=(unsigned char*)U(node,0x54);}B(state,0x834)=1;}return 1;}
