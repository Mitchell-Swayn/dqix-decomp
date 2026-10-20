#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {void* _ZN9GameState11GetInstanceEv();unsigned char* GameState_GetFieldOrbitCamera(void*);int Camera_IsOrbitInputEnabled(void*);int Input_IsKeyMaskNewlyPressed(void*,unsigned);void SoundSfx_StartCurrentSequenceArchiveEntry(void*,int,int);void TextCanvas_ResetDisplayPartByKey(void*,int);void KeyRepeater_Reset(void*);void Window_HideAndResetOptionSelection(void*);extern char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[],Main_UnknownRoleZeroInitializedStorage[];int Tavern_ProcessPartyMenuConfirmation(void*);int Tavern_IsPartyMenuCancelled(void*);}
// Original: arm9/ov003 @ 0x02161344; symbol: Resource_ResolveExtendedSelectionExit; size: 0xf4.
// Resolves input-driven selection exit; resets selected entry and optional linked owner.
extern "C" int Tavern_PollConfirmationOptions(unsigned char* self){P(self,1136)=self+1180;int result=0;int pressed=0;unsigned char* object=GameState_GetFieldOrbitCamera(_ZN9GameState11GetInstanceEv());if(object&&((object[0x244]&2)||!Camera_IsOrbitInputEnabled(object)))pressed=Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,512)!=0;if(Tavern_ProcessPartyMenuConfirmation(self)||pressed){SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);result=-1;if(H(self,1180)==44)result=1;}else if(Tavern_IsPartyMenuCancelled(self))result=-1;if(result){TextCanvas_ResetDisplayPartByKey(P(self,804),H(self,1160));KeyRepeater_Reset(self+776);P(self,1136)=0;}if(P(self,912)&&result)Window_HideAndResetOptionSelection(P(self,912));return result;}
