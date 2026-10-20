#pragma opt_common_subs off
#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv(); extern "C" unsigned char* _ZN9GameState20GetGameObjectByIndexEi(void*,int); extern "C" int _ZNK8Object3D9IsVisibleEv(void*); extern "C" void Object3D_DrawOrProcessWhenCountdownExpired(void*);
// Original: arm9/main @ 0x020D7638; symbol: func_020d7638; size: 0x80.
extern "C" ARM void GameState_ProcessTwelveVisibleIndexedObjects(char* state) { void* game=_ZN9GameState11GetInstanceEv(); for(int i=0;i<12;++i) { int offset=i*216; if(*(int*)(state+offset+208)<0) continue; int index=i; if(i>3) index+=188; unsigned char* object=_ZN9GameState20GetGameObjectByIndexEi(game,index); if(object && _ZNK8Object3D9IsVisibleEv(object) && (((unsigned)object[0x41]<<26)>>31)) Object3D_DrawOrProcessWhenCountdownExpired(state+offset); } }
