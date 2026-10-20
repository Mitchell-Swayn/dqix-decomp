#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))

#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" unsigned TextContext_GetSharedInstance();extern "C" void* Zone3D_GetMainInstance();extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);extern "C" void _ZN13SafeAllocator7DestroyEv(void*);extern "C" void Graphics_ApplySubBackgroundSnapshotAndClearPending(void*);extern "C" void Graphics_ApplyMainBackgroundSnapshotAndClearPending(void*);extern "C" void Window_ClearResourceBuffers(unsigned char*);extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void*);extern "C" void Window_ResetResourceTransfers(void*);extern "C" void Selection_ReleaseAttachedDisplayResources(unsigned char*);extern "C" void* memset(void*,int,unsigned);extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);extern "C" void LoadToMainBG1CharacterData(const void*,unsigned,unsigned);extern "C" void* _Z11GetBTRandomv();extern "C" char* GameState_GetIndexList(void*);extern "C" char* GameState_GetObjectWithFlag100(void*,int);extern "C" char* GameObject_GetLinkedIndexedState(void*);extern "C" int Random_ScaleIntegerByRandFraction(int);struct Descriptor{unsigned pad;unsigned value:10,rest:22;};
// Original: arm9/ov017 @ 0x021970A0; symbol: GameState_RollTwoOutcomesFromMaximumPartyDescriptor; size: 0x124.
extern "C" int Field_RollEncounterOpeningOutcome(int mode){void* game=_ZN9GameState11GetInstanceEv();_Z11GetBTRandomv();char* list=GameState_GetIndexList(game);unsigned maximum=0;for(int i=0;i<B(list,0xf7c);i++){char* actor=GameState_GetObjectWithFlag100(game,B(list+i,0xf78));if(!actor)continue;if(W(P(actor,304),0)&1)continue;char* descriptor=GameObject_GetLinkedIndexedState(actor);if(!descriptor)continue;unsigned value=((Descriptor*)descriptor)->value;if(maximum<value)maximum=value;}if(mode!=2){float extra=mode==1?10.0f:0.0f;int chance=(int)((2.0f+0.05f*(float)(int)maximum)+extra);if(Random_ScaleIntegerByRandFraction(100)<chance)return 1;}if(mode!=1){float extra=mode==2?10.0f:0.0f;int chance=(int)(2.0f+extra);if(Random_ScaleIntegerByRandFraction(100)<chance)return 2;}return 0;}
