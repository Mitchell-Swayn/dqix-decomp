#include <globaldefs.h>
ARM
#pragma opt_common_subs off
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* GameState_GetObjectWithFlag100(void*,int);extern "C" void Ov023_InitializeFourEmbeddedFields(void*,unsigned);extern "C" void InitializeTenEntryHalfwordSentinels(void*);extern "C" void* GameObject_GetLinkedIndexedState(void*);extern "C" void CharacterPreview_QueueAppearanceModelsAndAnimations(void*,void*,int,int,int);
// Original: arm9/ov023 @ 0x021FC71C; symbol: InitializeAlternateEmbeddedPartyResource; size: 0xac.
extern "C" void CharacterPreview_LoadPartyMemberIntoInactiveBank(char* self,int index,int reset){
void* object=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),index);struct Bits{unsigned char index:1;unsigned char rest:7;};int alternate=((((Bits*)(self+0x1864))->index+1)%2)*0xc20;char* base=self+32;if(reset)Ov023_InitializeFourEmbeddedFields(base+alternate,491);InitializeTenEntryHalfwordSentinels(base+alternate);void* data=GameObject_GetLinkedIndexedState(object);CharacterPreview_QueueAppearanceModelsAndAnimations(base+alternate,data,index,1,0);B(self,0x1864)|=8;
}
