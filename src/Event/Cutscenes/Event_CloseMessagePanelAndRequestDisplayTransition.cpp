#include <globaldefs.h>
ARM
extern "C" int BackgroundLoader_CancelEightTasksAndResetState(...);
extern "C" int DisplayContext_IgnoreRequestWithData(...);
extern "C" int DisplayContext_IgnoreHook(...);
extern "C" int Memory_FreeThroughAllocatorUnion(...);
extern "C" int DisplayContext_GetGlobalInstance(...);
extern "C" int QuestMessagePanel_RequestAlternateTransition(...);
extern "C" int _ZN13SafeAllocator7DestroyEv(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int _ZNK13SafeAllocator18GetSignedAllocatorEv(...);
extern "C" int _ZNK9GameState12GetTickCountEv(...);
extern "C" int QuestMessagePanel_UpdateAndDrawIndicators(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov001 @ 0x02154E40; symbol: FinishAllocatorAnimationAndQueueDisplayRequest.
extern "C" int Event_CloseMessagePanelAndRequestDisplayTransition(char* self){
void* state=(void*)_ZN9GameState11GetInstanceEv();if(!(H(self,80)&8)&&P(self,312)&&P(self,288)){QuestMessagePanel_RequestAlternateTransition(P(self,288));QuestMessagePanel_UpdateAndDrawIndicators(P(self,288),_ZNK9GameState12GetTickCountEv(state));if(S(P(self,288),210)>=0)return H(self,10);void* allocator=(void*)_ZNK13SafeAllocator18GetSignedAllocatorEv(P(self,312));if(allocator){_ZN13SafeAllocator7DestroyEv(P(self,312));Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocator);P(self,312)=0;}P(self,288)=0;}void* display=(void*)DisplayContext_GetGlobalInstance();int enabled=1;if(B(self,19))enabled=0;DisplayContext_IgnoreHook(display);BackgroundLoader_CancelEightTasksAndResetState(display);DisplayContext_IgnoreRequestWithData(display,111,self+98,1,enabled);return 13;
}
