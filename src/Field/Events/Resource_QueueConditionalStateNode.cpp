#include <globaldefs.h>
ARM
struct MapGameObject;struct State;
extern "C" unsigned int TextContext_GetSharedInstance();
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void* GameState_GetSerializedProgressState();
extern "C" unsigned int BitArray_ReadNonnegativeIndexMask(void*,unsigned char*,int);
extern "C" bool LinkedQueue_IsEmpty(const int*);
extern "C" int GameObject_GetMovementInputEnabled(void*);
extern "C" bool GameObject_HasQueuedActions(signed char*);
extern "C" bool GameObject_IsMovementPauseActive(char*);
extern "C" bool SystemState_TestAnyFlags(const unsigned int*,unsigned int);
extern "C" int GameObject_GetLadderTraversalActive(void*);
extern "C" int Graphics_DecodeSignedBrightness(volatile unsigned short*);
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned int);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);
extern "C" void* Script_ReadGlobalExecutionValue();
extern "C" void TimedMessageQueue_CancelAndClear(State*);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void _ZN6Zone3D20RecordBMDJFlag4StateEv(void*);
extern "C" void Resource_InitializeConditionalStateNode(unsigned char*,unsigned char);
extern "C" void LinkedQueue_InsertAfterHeadAndMarkLinked(char*,char*);
// Original: arm9/ov017 @ 0x021C05F4; symbol: func_ov017_021c05f4; size: 0x16C.
// Applies readiness/input gates, cleans script state and initializes/enqueues a resource node.
extern "C" void Resource_QueueConditionalStateNode(unsigned char *resources,unsigned char enabled,unsigned char value,int gated){
 unsigned char *owner=(unsigned char*)TextContext_GetSharedInstance();
 if(gated){
 unsigned char *object=(unsigned char*)_ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());
 unsigned int *state=(unsigned int*)SystemState_GetGlobalFlags();
 unsigned char *bits=(unsigned char*)GameState_GetSerializedProgressState();
 if(!BitArray_ReadNonnegativeIndexMask(bits,bits+0x8c,0x119a))return;
 if(!LinkedQueue_IsEmpty(*(int**)(resources+0x36fc)))return;
 if(!GameObject_GetMovementInputEnabled(object))return;
 if(GameObject_HasQueuedActions((signed char*)object))return;
 if(*(unsigned*)(object+0x18c)&1)return;
 if(GameObject_IsMovementPauseActive((char*)object)||*(short*)(object+0xac)||*(int*)(owner+0x998))return;
 if(SystemState_TestAnyFlags(state,0x800))return;
 if(GameObject_GetLadderTraversalActive(object))return;
 if(Graphics_DecodeSignedBrightness((volatile unsigned short*)0x0400006c))return;
 if(!Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,4))return;
 *(short*)(object+0xb2)=0;
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
 }else{if(*(int*)(owner+0x998))TextWindow_ResetGlyphBuffersAndFrameContexts(owner);}
 TimedMessageQueue_CancelAndClear((State*)Script_ReadGlobalExecutionValue());
 _ZN6Zone3D20RecordBMDJFlag4StateEv(Zone3D_GetMainInstance());
 Resource_InitializeConditionalStateNode(*(unsigned char**)(resources+0x3b3c),enabled);
 (*(unsigned char**)(resources+0x3b3c))[0x24]=value;
 LinkedQueue_InsertAfterHeadAndMarkLinked(*(char**)(resources+0x36fc),*(char**)(resources+0x3b3c));
}
