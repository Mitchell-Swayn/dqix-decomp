#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {void* _ZN9GameState11GetInstanceEv();unsigned char* TextContext_GetSharedInstance();char* ResourceStringTable_GetTextByKey(void*,unsigned);unsigned strlen(const char*);void Church_StartConfiguredMessage(void*,const char*);void Graphics_ClearAndStageSharedBuffers(void*);void Bgm_RequestTemporarySequence(void*,unsigned short);int Bgm_IsTemporarySequencePendingOrPlaying(void*);extern char Main_UnknownRoleZeroInitializedStorage_Variant2[];}
// Original: arm9/ov003 @ 0x0215B0E8; symbol: Graphics_AdvanceOptionalMessageAndIdentifier; size: 0xf4.
// Stages optional message, waits for shared graphics, then resets identifier state.
extern "C" void Church_AdvanceOptionalMessageAndServiceJingle(unsigned char* self){_ZN9GameState11GetInstanceEv();unsigned char* owner=TextContext_GetSharedInstance();unsigned state=self[0x580];if(state==0){if(self[0x59d])return;char* text=ResourceStringTable_GetTextByKey(self+100,1100);if(text&&strlen(text)){W(owner,0x998)=1;Church_StartConfiguredMessage(self,ResourceStringTable_GetTextByKey(self+100,1100));}else Graphics_ClearAndStageSharedBuffers(owner);++self[0x580];}if(state==1){if(W(owner,0x998))return;Bgm_RequestTemporarySequence(Main_UnknownRoleZeroInitializedStorage_Variant2,59);++self[0x580];}if(state==2){if(W(owner,0x9a0)==3)owner[0x19ae]=0;if(!Bgm_IsTemporarySequencePendingOrPlaying(Main_UnknownRoleZeroInitializedStorage_Variant2)){self[0x588]=1;self[0x580]=0;}}}
