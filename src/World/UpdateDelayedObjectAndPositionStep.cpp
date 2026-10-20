#include <globaldefs.h>
ARM
#pragma block_assign on
#include <GameState/GameState.h>
#include <World/Object3D.h>
#include <Graphics/Vector.h>
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage[];struct Vec{int x,y,z;};extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(void*,int,int),Object3D_CopyPosition(void*,void*),ObjectPool_ResetDisplayEntry(void*),ResourceTracks_AdvanceBoundPlayback(void*);extern "C" int EffectEmitter_TestCompletionIncludingChildren(unsigned);
// Original: arm9/main @ 0x0205A020; symbol: func_0205a020; size: 0x128.
extern "C" void UpdateDelayedObjectAndPositionStep(unsigned char* object,int delta){Vec position,step;GameState::GetInstance();if(*(short*)(object+0xb0)>0)*(short*)(object+0xb0)-=delta;else if(!*(int*)(object+0xac)){int value=*(int*)(object+0xb8);if(value>0&&*(int*)(object+0x28)<=*(int*)(object+0xbc)&&*(int*)(object+0xbc)<*(int*)(object+0x24))SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,value,0);position=*(Vec*)(object+0x44);Vector3fixMultiplyScalar((Vector3fix*)(object+0xc0),delta<<12,(Vector3fix*)&step);Vector3fix_Add((Vector3fix*)&position,(Vector3fix*)&step,(Vector3fix*)&position);Object3D_CopyPosition(object,&position);((Object3D*)object)->AdvanceEffects();if((object[0x19]&1)&&((Object3D*)object)->HasAnimationStopped())ObjectPool_ResetDisplayEntry(object);if(*(short*)(object+0xb6)>0){*(short*)(object+0xb6)-=delta;if(*(short*)(object+0xb6)<=0)ObjectPool_ResetDisplayEntry(object);}}else if(EffectEmitter_TestCompletionIncludingChildren(*(unsigned*)(object+4))==1)ObjectPool_ResetDisplayEntry(object);else ResourceTracks_AdvanceBoundPlayback(object);}
