#include <globaldefs.h>
ARM
struct RangeState;struct State;struct AnimationOwner;
extern "C" {
int CharacterViewer_UpdateCameraTargetFollowingFromInput();int Input_IsKeyMaskReleased(unsigned short*,unsigned);int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);int Input_TestKeyMask(unsigned short*,unsigned short);int Input_PollKeyRepeatCountdown(State*,unsigned);
int CharacterViewer_GetMenuSelectionIndex(RangeState*);char* DebugMenu_GetEntryByIndex(char*,int);void* DebugMenu_GetEntryLabel(void*);
void CharacterViewer_PlayNamedAnimation(unsigned char*,void*);void UpdateCachedAnimationEntry(AnimationOwner*);void Object_SetValueOnResolvedLinkedSubrecord(void*,int);void CharacterViewer_AdjustSelectedAnimationTime(unsigned char*,int);void CharacterViewer_RebuildMenu(unsigned char*,int);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
}
struct Node {unsigned char* object;Node* next;};
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define W(p,o) (*(int*)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define NEW(k) Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,k)
#define HELD(k) Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,k)
#define REPEAT(k) Input_PollKeyRepeatCountdown((State*)KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,k)
// Original: arm9/ov015 @ 0x02191294; symbol: func_ov015_02191294; size: 0x3D4.
// Handles animation selection, owner-wide flags, bounded amount changes and accelerated held-key adjustments.
extern "C" void UI_HandleAnimationSelectionInput(unsigned char* self) {
 if(CharacterViewer_UpdateCameraTargetFollowingFromInput())return;
 if(Input_IsKeyMaskReleased(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x20)||Input_IsKeyMaskReleased(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x10)||Input_IsKeyMaskReleased(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x100)){W(self,0x2bc)=30;W(self,0x2c0)=0;}
 if(NEW(1)) {
 if(HELD(0x100)){P(self,0x30)[0x3a]=!P(self,0x30)[0x3a];self[0x350]=1;return;}
 if(HELD(0x200)) {
 int flag=W(P(self,0x30),0x44);
 if(self[0x19f]){Node* node=*(Node**)(self+0x2c);while(node){if(flag==0)W(node->object,0x44)=1;else W(node->object,0x44)=0;node=node->next;}}
 else {if(flag==0)W(P(self,0x30),0x44)=1;else W(P(self,0x30),0x44)=0;}
 }
 Object_SetValueOnResolvedLinkedSubrecord(P(self,0x30),W(P(self,0x30),0x4c));
 H(P(self,0x30),0x38)=CharacterViewer_GetMenuSelectionIndex((RangeState*)(self+0x2c4));
 int selected=CharacterViewer_GetMenuSelectionIndex((RangeState*)(self+0x2c4));
 char* item=DebugMenu_GetEntryByIndex((char*)self+0x2c4,selected);
 if(item){if(self[0x19f]){Node* node=*(Node**)(self+0x2c);while(node){void* sub=DebugMenu_GetEntryLabel(item);CharacterViewer_PlayNamedAnimation(node->object,sub);node=node->next;}}else {void* sub=DebugMenu_GetEntryLabel(item);CharacterViewer_PlayNamedAnimation(P(self,0x30),sub);}}
 UpdateCachedAnimationEntry((AnimationOwner*)P(self,0x30));self[0x350]=1;return;
 }
 if(NEW(2)) {
 Object_SetValueOnResolvedLinkedSubrecord(P(self,0x30),W(P(self,0x30),0x4c));
 P(self,0x30)[0x3a]=0;H(P(self,0x30),0x38)=-1;W(P(self,0x30),0x44)=0;W(P(self,0x30),0x4c)=0;W(self,0x194)=0;CharacterViewer_RebuildMenu(self,0);return;
 }
 if(NEW(0x100)){if(P(self,0x30)[0x3a])self[0x350]=1;return;}
 if(REPEAT(0x20)) {
 if(HELD(0x100))CharacterViewer_AdjustSelectedAnimationTime(P(self,0x30),-40);
 else {int value=H(self,0x324)-8;int min=H(self,0x320);if(value<min)value=min;H(self,0x324)=value;}
 self[0x350]=1;return;
 }
 if(REPEAT(0x10)) {
 if(HELD(0x100))CharacterViewer_AdjustSelectedAnimationTime(P(self,0x30),40);
 else {int value=H(self,0x324)+8;int max=H(self,0x322);if(value>max)value=max;H(self,0x324)=value;}
 self[0x350]=1;return;
 }
 if(HELD(0x20)) {
 if(!HELD(0x100))return;
 if(W(self,0x2c0)<W(self,0x2bc)){W(self,0x2c0)++;return;}
 W(self,0x2c0)=0;W(self,0x2bc)-=10;CharacterViewer_AdjustSelectedAnimationTime(P(self,0x30),-40);self[0x350]=1;return;
 }
 if(HELD(0x10)) {
 if(!HELD(0x100))return;
 if(W(self,0x2c0)<W(self,0x2bc)){W(self,0x2c0)++;return;}
 W(self,0x2c0)=0;W(self,0x2bc)-=10;CharacterViewer_AdjustSelectedAnimationTime(P(self,0x30),40);self[0x350]=1;
 }
}
