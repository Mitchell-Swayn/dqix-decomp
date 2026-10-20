#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Object3D.h>
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(void*,int,int);extern "C" void GameObject_GetAuthorityPosition(Vector3fix*,void*);extern "C" void SetObjectAngleAndClearFlagC48000(Object3D*,unsigned);extern "C" void GameObject_ChangeMotionStateAndRefreshAnimation(Object3D*,unsigned char);
// Original: arm9/main @ 0x02078898; symbol: func_02078898; size: 0x100.
extern "C" ARM int Object3D_FaceWanderingMonsterAndResetAlpha(Object3D* p){GameState* game=GameState::GetInstance();void* monster=game->GetMaybeWanderingMonsterByIndex(*(unsigned short*)((char*)p+0x166));int result;if(!monster)result=0;else{unsigned char* info=*(unsigned char**)((char*)GameResources_GetInstance()+0x3734);Object3D* protagonist=(Object3D*)game->GetProtagonist();unsigned a=protagonist->GetField06(),b=p->GetField06();if(a==b&&!info[3])SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,6,0);struct Vectors{int position[3],delta[3],copy[3];} v;GameObject_GetAuthorityPosition((Vector3fix*)v.position,monster);COPY_ARRAY(v.copy,v.position);Vector3fix_Subtract((Vector3fix*)v.copy,(Vector3fix*)((char*)p+0x44),(Vector3fix*)v.delta);Vector3fix_Normalize((Vector3fix*)v.delta,(Vector3fix*)v.delta);SetObjectAngleAndClearFlagC48000(p,fix32_Atan2(v.delta[0],v.delta[2]));*(unsigned short*)((char*)p+0xb2)=0;GameObject_ChangeMotionStateAndRefreshAnimation(p,0);p->DisableFlag(128);p->SetInheritedAlpha(31);*((char*)p+0x17c)=0;result=1;}return result;}
