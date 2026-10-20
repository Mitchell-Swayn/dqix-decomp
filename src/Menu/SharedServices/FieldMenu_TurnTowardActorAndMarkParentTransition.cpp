#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct GameState;struct GameResources;struct Object3D;extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* Zone3D_GetMainInstance();extern "C" void* Network_GetConnectionManager();extern "C" bool Network_IsParentOrOffline(unsigned*);struct Entry;struct Table;struct Object;struct Vec{int x,y,z;};extern "C" unsigned TextContext_GetSharedInstance();extern "C" void* ActorPool_GetGlobalInstance();extern "C" Entry* ActorPool_FindActiveActorById(Table*,unsigned);extern "C" Object3D* _ZN9GameState20GetUnknownGameObjectEv(void*);extern "C" void Actor_GetRepresentationPositionOrZero(Vec*,Object*);extern "C" int FindChildIndexByHalfwordKeyExcludingFlag8000(char*,int);extern "C" void* Actor_GetRepresentationEffectiveYawOrZero(unsigned char*);extern "C" int fix32_Atan2(int,int);extern "C" int _Z22fix32ReduceAngle0To2Pii(int);extern "C" void SetObjectAngleAndClearFlagC48000(Object3D*,int);extern "C" int GameState_TestTransitionRequestFlags(void*,unsigned);extern "C" void GameState_AddTransitionRequestFlags(void*,unsigned char);extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x021688D4; symbol: World_FaceActiveEntrySixAndSetConnectionFlag; size: 0x104.
extern "C" int FieldMenu_TurnTowardActorAndMarkParentTransition(void){char* text=(char*)TextContext_GetSharedInstance();Table* table=(Table*)ActorPool_GetGlobalInstance();Entry* entry=ActorPool_FindActiveActorById(table,6);if(entry){Object3D* object=_ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());/* Explicit output argument is ABI-equivalent to hidden aggregate return. */Vec target=((Vec(*)(Object*))Actor_GetRepresentationPositionOrZero)((Object*)entry);Vec source=*(Vec*)((char*)object+68);W(text,0x1838)=FindChildIndexByHalfwordKeyExcludingFlag8000((char*)table,6);P(text,0x183c)=(char*)Actor_GetRepresentationEffectiveYawOrZero((unsigned char*)entry);int angle=_Z22fix32ReduceAngle0To2Pii(fix32_Atan2(target.x-source.x,target.z-source.z));SetObjectAngleAndClearFlagC48000(object,angle);}if(Network_IsParentOrOffline((unsigned*)Network_GetConnectionManager())){void* game=_ZN9GameState11GetInstanceEv();if(GameState_TestTransitionRequestFlags(game,16))SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);GameState_AddTransitionRequestFlags(game,16);}return 0;}
