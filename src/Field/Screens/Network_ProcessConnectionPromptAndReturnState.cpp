#include <globaldefs.h>
ARM
extern "C" int Input_IsKeyMaskNewlyPressed(...);
extern "C" int Menu_UpdateCanvasSessionAndDisconnectFade(...);
extern "C" char* GameResources_GetInstance(...);
extern "C" char* Network_GetConnectionManager(...);
extern "C" int Network_IsClientSession(...);
extern "C" int Field_MergeClientStateAndTestZoneRefresh(...);
extern "C" char* NavigationMessage_GetGlobalInstance(...);
extern "C" int NavigationMessage_EnqueueWithFormattedMemberName(...);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov017 @ 0x21d83f0; symbol: data_ov017_021d83f0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned char ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage[];
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov017 @ 0x021B2698; symbol: Network_ProcessConnectionPromptAndReturnState; size: 0xc0.
// Network ProcessConnectionPromptAndReturnState from listed field operations and calls.
extern "C" int Network_ProcessConnectionPromptAndReturnState(char* self){if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,8192))return 3;if(Menu_UpdateCanvasSessionAndDisconnectFade(P(ResourceGetSharedLoadState_UnknownRoleZeroInitializedStorage,4)))return W(self,8);if(!B(P(GameResources_GetInstance(),0x3b3c),2)&&Network_IsClientSession(Network_GetConnectionManager())){unsigned char flag=0;if(Field_MergeClientStateAndTestZoneRefresh(&flag)){W(self,0x38)=(W(self,0x38)&~1)|1;B(self,0x48)=1;NavigationMessage_EnqueueWithFormattedMemberName(NavigationMessage_GetGlobalInstance(),0x4e23,-1,0);}}return 3;}
