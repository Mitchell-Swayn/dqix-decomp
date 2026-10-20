#include <globaldefs.h>
ARM
extern "C" int GameState_ReadUnknownB0(...);
extern "C" int Camera_UpdateManualInputAndTargetFollowing(...);
extern "C" int Input_IsKeyMaskNewlyPressed(...);
extern "C" int CharacterViewer_UpdateModelByKind(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int CharacterViewer_RebuildMenu(...);
extern "C" int CharacterViewer_PushMenuHistory(...);
extern "C" int CharacterViewer_PopMenuHistory(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov015 @ 0x02190D7C; symbol: ToggleMenuModeAndRestoreEligibleHistorySelection.
extern "C" void CharacterViewer_ToggleOperationMenu(char*self){
int state=_ZN9GameState11GetInstanceEv();if(!state)return;int actor=GameState_ReadUnknownB0(state);if(actor)Camera_UpdateManualInputAndTargetFollowing(actor);for(char*node=P(self,44);node;node=P(node,4))CharacterViewer_UpdateModelByKind(P(node,0));if(!Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,4))return;int previous=W(self,404);W(self,404)=W(self,408);W(self,408)=previous;if(W(self,404)==2){CharacterViewer_PushMenuHistory(self,W(self,420));W(self,420)=35;}else{int selected;do{selected=CharacterViewer_PopMenuHistory(self);}while(selected>=35);int category=*(signed char*)(self+56);if(category>=0){switch(category){case 0:case 1:while(selected>=15)selected=CharacterViewer_PopMenuHistory(self);break;case 2:while(selected>=33)selected=CharacterViewer_PopMenuHistory(self);break;}*(signed char*)(self+56)=-1;if(W(self,404)==1)W(self,404)=0;}W(self,420)=selected;}CharacterViewer_RebuildMenu(self,0);
}
