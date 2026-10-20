#include <globaldefs.h>
ARM
#include <Graphics/Vector.h>
struct PackedPosition { short x,y,z; };
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState31GetMaybeWanderingMonsterByIndexEi(void*,int);
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" int GameState_ReadProtagonistObjectIndex(void*);
extern "C" void* GameState_GetPendingPartyPositionRecord(void*,int);
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsParentOrOffline(unsigned*);
extern "C" int _Z8fix32absi(int);
extern "C" bool GameObject_IsMovementPauseActive(char*);
extern "C" void GameObject_StartMovementPause(char*,unsigned short);
extern "C" void GameObject_DeferPositionMatch(void*);
extern "C" void GameObject_ClearPositionMatchDeferral(unsigned char*);
extern "C" unsigned GameObject_IsPositionMatchDeferred(unsigned char*);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" void GameObject_RequestMovementInputEnable(void*);
extern "C" int GameObject_GetLadderTraversalActive(void*);
extern "C" void Network_QueueTypeB6PackedPosition(int,unsigned,unsigned short,PackedPosition);
extern "C" void __clear(void*,unsigned);
// Original: arm9/ov017 @ 0x021C2380; symbol: func_ov017_021c2380; size: 0x22C.
extern "C" int GameState_ConsumeNearbyMatchingPositionRecord(int index,int memberIndex) {
 Vector3i target;
 void* state=_ZN9GameState11GetInstanceEv();
 unsigned* connection=(unsigned*)Network_GetConnectionManager();
 unsigned short* record=(unsigned short*)GameState_GetPendingPartyPositionRecord(state,index);
 if(!record) return 0;
 if(!*record) return 0;
 char* object=(char*)_ZN9GameState31GetMaybeWanderingMonsterByIndexEi(state,memberIndex);
 char* member=(char*)_ZN9GameState21GetPartyMemberByIndexEi(state,memberIndex);
 if(!object) return 0;
 unsigned saved=0;
 if(index==GameState_ReadProtagonistObjectIndex(state) && GameObject_IsPositionMatchDeferred((unsigned char*)object)) {
  saved=GameObject_IsPositionMatchDeferred((unsigned char*)object);
  GameObject_ClearPositionMatchDeferral((unsigned char*)object);
 }
 if(GameObject_IsMovementPauseActive(object)) return 0;
 if(member && GameObject_GetLadderTraversalActive(member)) return 0;
 if(*record!=_ZNK8Object3D10GetField06Ev(object)) return 0;
 target.x=((short*)record)[1]<<4; target.y=((short*)record)[2]<<4; target.z=((short*)record)[3]<<4;
 Vector3i position=*(Vector3i*)(object+0x44);
 PackedPosition packed;
 if(_Z8fix32absi(target.x-position.x)>0x800) return 0;
 if(_Z8fix32absi(target.y-position.y)>0x800) return 0;
 if(_Z8fix32absi(target.z-position.z)>0x800) return 0;
 if(Vector3fix_Distance(&target,&position)>0x800) return 0;
 if(saved) {GameObject_DeferPositionMatch(object); return 0;}
 if(Network_IsParentOrOffline(connection)) {
  GameObject_StartMovementPause(object,5000);
  if(member) GameObject_RequestMovementInputEnable(member);
 }
 __clear(&packed,6);
 Network_QueueTypeB6PackedPosition(1,index&0xff,(unsigned short)memberIndex,packed);
 *record=0;
 return 1;
}
