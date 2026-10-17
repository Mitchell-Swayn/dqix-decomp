#include <globaldefs.h>
ARM
#include <Graphics/Vector.h>
struct GameState;
struct ZoneTintState;
struct MapGameObject;
struct Zone3D;
struct Object;
struct Owner;
struct State;
struct Request { int id; unsigned char flag,pad[3]; };
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" void* Object_GetGlobalConnectionState();
extern "C" void* GameState_GetField3B0ObjectWithFlag4(GameState*);
extern "C" void* Object_ReadWordAtOffset330(GameState*);
extern "C" ZoneTintState* GameState_ReadUnkF8(GameState*);
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(GameState*,int);
extern "C" void ProcessCurrentObjectPositionAndZone(void*,int,int);
extern "C" unsigned char* _ZN6Zone3D24FindNearestType11FeatureEPK8Vector3i(void*,const Vector3i*);
extern "C" int Zone3D_FindGroundHeightBelowPosition(Zone3D*,const Vector3i*);
extern "C" void GameState_SetPartyPositionAndNormalizedAngle(Vector3i*,const void*,int);
extern "C" int ResourceLoader_QueueTypedGP1OrFileRequest(State*,unsigned char,const Request*);
extern "C" void UpdateObjectStateAndStoredValue(Object*,unsigned,unsigned short);
extern "C" void WriteHalfwordAtOffset21C(void*,int);
extern "C" void Resource_QueueConnectionRecordB3(int,int);
extern "C" int _ZN6Zone3D16IsZoneInRuleListEi(void*,int);
extern "C" void ObjectTransform_WriteThreeWordComponents(Vector3i*,int,int,int);
extern "C" void Object3D_SetNormalizedAngleAndUpdatePosition(char*,int);
extern "C" void ComputeTwoPositionsBehindObjectDirection(char*);
extern "C" void Object_SetUnsignedIntAtOffset4(int,unsigned);
extern "C" void ClearWordAtOffset4MaskedBits(int,unsigned);
extern "C" void ResourceLoader_RemoveFourTasksAndDestroyAllocator(Owner*);
extern "C" void DispatchStoredResourceHandleAtOffsetC0(unsigned char*);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" unsigned char data_ov017_021d82fc[],data_02108760[];
// Original: arm9/main @ 0x020ACECC; symbol: func_020acecc; size: 0x324.
extern "C" void World_UpdateZoneTransitionResources(unsigned char* self,int source,int destination) {
GameState* gs=(GameState*)_ZN9GameState11GetInstanceEv();
unsigned char* zone=(unsigned char*)ReadGlobalValueAt020FB3F0();
Object_GetGlobalConnectionState();
void* flagged=GameState_GetField3B0ObjectWithFlag4(gs);
unsigned char* object=(unsigned char*)Object_ReadWordAtOffset330(gs);
unsigned char* state=(unsigned char*)GameState_ReadUnkF8(gs);
unsigned char* current=(unsigned char*)_ZN9GameState20GetUnknownGameObjectEv(gs);
_ZN9GameState21GetPartyMemberByIndexEi(gs,0);
ProcessCurrentObjectPositionAndZone(zone,source,destination);
if(state[0x61]) {
unsigned char* feature=_ZN6Zone3D24FindNearestType11FeatureEPK8Vector3i(zone,(Vector3i*)(zone+0x27b8));
if(feature) {
Vector3i point=*(Vector3i*)(feature+8);
point.y=Zone3D_FindGroundHeightBelowPosition((Zone3D*)zone,&point);
*(Vector3i*)(current+0x44)=point;
GameState_SetPartyPositionAndNormalizedAngle(&point,feature+0x20,0);
}
}
if(source==0x2774) {
Request request;
request.id=-1;request.flag=0;
request.id=*(short*)(object+4);
ResourceLoader_QueueTypedGP1OrFileRequest((State*)data_ov017_021d82fc,3,&request);
UpdateObjectStateAndStoredValue((Object*)data_02108760,0xa0,0xa0);
WriteHalfwordAtOffset21C(flagged,0xca);
object[0x19c]=1;
*(int*)(object+0x13c)=0;
Resource_QueueConnectionRecordB3(0,1);
if(_ZN6Zone3D16IsZoneInRuleListEi(zone,destination)) {
Vector3i position;
ObjectTransform_WriteThreeWordComponents(&position,0,0,0);
position.x=*(int*)(zone+0x27c8);
position.z=*(int*)(zone+0x27cc);
if(destination>=20000 && destination<=29999) {
position.x=fix32_Divide(position.x,0x6000);
position.y=fix32_Divide(position.y,0x6000);
position.z=fix32_Divide(position.z,0x6000);
}
*(Vector3i*)(object+0x44)=position;
Object3D_SetNormalizedAngleAndUpdatePosition((char*)object,0x3244);
ComputeTwoPositionsBehindObjectDirection((char*)object);
} else {
*(Vector3i*)(object+0x44)=*(Vector3i*)(zone+0x27b8);
Object3D_SetNormalizedAngleAndUpdatePosition((char*)object,*(int*)(zone+0x27c4));
ComputeTwoPositionsBehindObjectDirection((char*)object);
}
Object_SetUnsignedIntAtOffset4((int)self,0x10044);
ClearWordAtOffset4MaskedBits((int)self,0x40000);
} else if(source>=20000 && source<=29999 && destination==0x2774) {
unsigned short first=*(volatile unsigned short*)(zone+0x27b4);
unsigned short second=*(volatile unsigned short*)(zone+0x27b6);
Resource_QueueConnectionRecordB3((unsigned char)first,(unsigned char)second);
unsigned char* obj=(unsigned char*)_ZN9GameState20GetUnknownGameObjectEv(gs);
WriteHalfwordAtOffset21C(flagged,*(short*)(obj+4));
ClearWordAtOffset4MaskedBits((int)self,0x10044);
Object_SetUnsignedIntAtOffset4((int)self,0x40000);
} else if(source!=0x2774 && destination==0x2774) {
if(data_ov017_021d82fc[14]==3) ResourceLoader_RemoveFourTasksAndDestroyAllocator((Owner*)data_ov017_021d82fc);
DispatchStoredResourceHandleAtOffsetC0(data_02108760);
Resource_QueueConnectionRecordB3((unsigned char)*(unsigned short*)(zone+0x27b4),(unsigned char)*(unsigned short*)(zone+0x27b6));
WriteHalfwordAtOffset21C(flagged,GameState_ReadProtagonistObjectIndex(gs));
ClearWordAtOffset4MaskedBits((int)self,0x10044);
Object_SetUnsignedIntAtOffset4((int)self,0x40000);
}
}
