#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x20ee688; symbol: data_020ee688.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 001e3c.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ee68b; symbol: data_020ee68b.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 6482a0000000080000.
// Observed span: 9 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Item{char bytes[40];};struct State{SafeAllocator allocator;char basePadding[40];unsigned char flag3c;char pad3d[3];unsigned words40[4];char pad50[4];unsigned char flag54;char pad55[7];unsigned word5c,word60;unsigned short half64,half66;unsigned word68;unsigned char flag6c,pad6d;unsigned short half6e;Item entries[3];};extern "C" unsigned char ObjectInitializeThreeEntriesAndAllocatorState_UnknownRoleInitializedBytes[],ObjectInitializeThreeEntriesAndAllocatorState_UnknownRoleInitializedBytes_Variant2[];extern "C" void Object_ClearInitialFieldsAndSetState81(Item*),DisplaySpriteAnimation_SetStartFrame(Item*,unsigned char),DisplaySpriteAnimation_SetEndFrame(Item*,unsigned char),DisplaySpriteAnimation_SetOrigin(Item*,unsigned char,unsigned char),DisplaySpriteAnimation_SetScaleGrowthStep(Item*,int),DisplayOverlay_ResetActivationState(State*);
// Original: arm9/main @ 0x020DAFD4; symbol: func_020dafd4; size: 0xF0.
extern "C" ARM void Object_InitializeThreeEntriesAndAllocatorState(State*p){p->allocator.ResetAllocatorPointer();p->words40[0]=0;p->words40[1]=0;p->words40[2]=0;p->words40[3]=0;p->flag3c=0;p->word5c=0;p->word60=0;p->half66=0;p->flag6c=1;p->flag54=0;for(int i=0;i<3;i++){Item*e=p->entries+i;Object_ClearInitialFieldsAndSetState81(e);DisplaySpriteAnimation_SetStartFrame(e,ObjectInitializeThreeEntriesAndAllocatorState_UnknownRoleInitializedBytes[i]);DisplaySpriteAnimation_SetEndFrame(e,ObjectInitializeThreeEntriesAndAllocatorState_UnknownRoleInitializedBytes_Variant2[i]);DisplaySpriteAnimation_SetOrigin(e,(unsigned char)(i*18+188),164);int value=(int)(((long long)(i<<12)*40+2048)>>12)+901;DisplaySpriteAnimation_SetScaleGrowthStep(e,value);}p->half6e=0;DisplayOverlay_ResetActivationState(p);}
