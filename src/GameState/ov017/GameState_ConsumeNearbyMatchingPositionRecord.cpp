#include <globaldefs.h>
ARM
#include <Graphics/Vector.h>
struct PackedPosition { short x,y,z; };
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState31GetMaybeWanderingMonsterByIndexEi(void*,int);
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" int GameState_ReadProtagonistObjectIndex(void*);
extern "C" void* Object_GetBoundedEightByteRecordAtOffset74DE(void*,int);
extern "C" void* Object_GetGlobalConnectionState();
extern "C" bool TestInactiveOrPrimaryIndexState(unsigned*);
extern "C" int _Z8fix32absi(int);
extern "C" bool TestFieldAtOffsetC4(char*);
extern "C" void Object_SetPackedOffsetC4ValueAndNotifyCurrentZone(char*,unsigned short);
extern "C" void SetMaskedFlagsAtOffsetC2WithMask80(void*);
extern "C" void Object_ClearElement194Mask80(unsigned char*);
extern "C" unsigned ReadFieldC2HighBit(unsigned char*);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" void SetByteFieldAtOffset253ToOne(void*);
extern "C" int ReadByteFieldAtOffset26C(void*);
extern "C" void Network_QueueTypeB6PackedPosition(int,unsigned,unsigned short,PackedPosition);
extern "C" void __clear(void*,unsigned);
// Original: arm9/ov017 @ 0x021C2380; symbol: func_ov017_021c2380; size: 0x22C.
extern "C" int GameState_ConsumeNearbyMatchingPositionRecord(int index,int memberIndex) {
 Vector3i target;
 void* state=_ZN9GameState11GetInstanceEv();
 unsigned* connection=(unsigned*)Object_GetGlobalConnectionState();
 unsigned short* record=(unsigned short*)Object_GetBoundedEightByteRecordAtOffset74DE(state,index);
 if(!record) return 0;
 if(!*record) return 0;
 char* object=(char*)_ZN9GameState31GetMaybeWanderingMonsterByIndexEi(state,memberIndex);
 char* member=(char*)_ZN9GameState21GetPartyMemberByIndexEi(state,memberIndex);
 if(!object) return 0;
 unsigned saved=0;
 if(index==GameState_ReadProtagonistObjectIndex(state) && ReadFieldC2HighBit((unsigned char*)object)) {
  saved=ReadFieldC2HighBit((unsigned char*)object);
  Object_ClearElement194Mask80((unsigned char*)object);
 }
 if(TestFieldAtOffsetC4(object)) return 0;
 if(member && ReadByteFieldAtOffset26C(member)) return 0;
 if(*record!=_ZNK8Object3D10GetField06Ev(object)) return 0;
 target.x=((short*)record)[1]<<4; target.y=((short*)record)[2]<<4; target.z=((short*)record)[3]<<4;
 Vector3i position=*(Vector3i*)(object+0x44);
 PackedPosition packed;
 if(_Z8fix32absi(target.x-position.x)>0x800) return 0;
 if(_Z8fix32absi(target.y-position.y)>0x800) return 0;
 if(_Z8fix32absi(target.z-position.z)>0x800) return 0;
 if(Vector3fix_Distance(&target,&position)>0x800) return 0;
 if(saved) {SetMaskedFlagsAtOffsetC2WithMask80(object); return 0;}
 if(TestInactiveOrPrimaryIndexState(connection)) {
  Object_SetPackedOffsetC4ValueAndNotifyCurrentZone(object,5000);
  if(member) SetByteFieldAtOffset253ToOne(member);
 }
 __clear(&packed,6);
 Network_QueueTypeB6PackedPosition(1,index&0xff,(unsigned short)memberIndex,packed);
 *record=0;
 return 1;
}
