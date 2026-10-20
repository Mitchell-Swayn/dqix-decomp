#include <globaldefs.h>
ARM
struct GameState;
struct GameResources;
struct Object;
struct Object3D;
struct Owner;
struct ZoneTintState;
struct MapGameObject;
struct Vector3fix { int x,y,z; };
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* Network_GetConnectionManager();
extern "C" GameResources* GameResources_GetInstance();
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void GameObject_DisableMovementInput(Object*,int);
extern "C" void _ZN8Object3D10EnableFlagEi(void*,int);
extern "C" void _ZN8Object3D11DisableFlagEi(void*,int);
extern "C" int _Z22fix32ReduceAngle0To2Pii(int);
extern "C" int _Z8fix32sini(int);
extern "C" int _Z8fix32cosi(int);
extern "C" void Vector3fix_Normalize(const Vector3fix*,Vector3fix*);
extern "C" void Vector3fix_Add(const Vector3fix*,const Vector3fix*,Vector3fix*);
extern "C" void Vector3fix_Subtract(const Vector3fix*,const Vector3fix*,Vector3fix*);
extern "C" int Vector3fix_Length(const Vector3fix*);
extern "C" int fix32_Atan2(int,int);
extern "C" void SetObjectAngleAndClearFlagC48000(Object3D*,int);
extern "C" void GameObject_ChangeMotionStateAndRefreshAnimation(Owner*,unsigned);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void*);
extern "C" void GameObject_SetMotionState(void*,int);
extern "C" int GameState_CopyProtagonistPartySlotList(void*,void*);
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" ZoneTintState* GameState_ReadUnkF8(GameState*);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" void* _ZN8Vector3iaSERKS_(void*,const void*);
extern "C" void GameState_ReplacePendingFieldTransition(void*,void*);
extern "C" void Field_InitializeZoneTransitionCommand(void*,int);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned*,unsigned);
struct Transition { unsigned char pad[8]; int state,ticks; unsigned char* config; Vector3fix target; };
// Original: arm9/ov017 @ 0x021AB280; symbol: func_ov017_021ab280; size: 0x3FC.
extern "C" void World_AdvanceObjectBrightnessTransition(Transition* self) {
void* gs=_ZN9GameState11GetInstanceEv();
Network_GetConnectionManager();
GameResources* resources=GameResources_GetInstance();
unsigned char* obj=(unsigned char*)_ZN9GameState20GetUnknownGameObjectEv(gs);
unsigned char* global=(unsigned char*)Zone3D_GetMainInstance();
if(self->state==0) {
GameObject_DisableMovementInput((Object*)obj,1);
_ZN8Object3D10EnableFlagEi(obj,0x1000080);
Vector3fix direction;
Vector3fix position=*(Vector3fix*)(obj+0x44);
int angle=_Z22fix32ReduceAngle0To2Pii(*(short*)(self->config+0x20)-0x323d);
direction.x=_Z8fix32sini(angle);
direction.y=0;
direction.z=_Z8fix32cosi(angle);
Vector3fix_Normalize(&direction,&direction);
Vector3fix_Add((Vector3fix*)(self->config+8),&direction,&self->target);
Vector3fix_Subtract(&self->target,&position,&direction);
Vector3fix_Normalize(&direction,&direction);
SetObjectAngleAndClearFlagC48000((Object3D*)obj,fix32_Atan2(direction.x,direction.z));
GameObject_ChangeMotionStateAndRefreshAnimation((Owner*)obj,1);
_Z13SetBrightnessP13GameResourcesii(resources,-16,15);
self->state++;
self->ticks=0;
} else if(self->state==1) {
int phase=global[0x830];
if(phase<=4) {
self->state++;
self->ticks=0;
GameObject_SetMotionState(obj,1);
}
} else if(self->state==2) {
Vector3fix direction;
Vector3fix position=*(Vector3fix*)(obj+0x44);
Vector3fix_Subtract(&self->target,&position,&direction);
Vector3fix_Length(&direction);
Vector3fix_Subtract(&self->target,&position,&direction);
Vector3fix_Normalize(&direction,&direction);
SetObjectAngleAndClearFlagC48000((Object3D*)obj,fix32_Atan2(direction.x,direction.z));
GameObject_SetMotionState(obj,1);
*(unsigned short*)(obj+0xb2)=0xa3;
if(!_Z28IsBrightnessTransitionActiveP13GameResources(resources)) {self->state=4;self->ticks=0;}
} else if(self->state==3) {
Vector3fix direction;
Vector3fix position=*(Vector3fix*)(obj+0x44);
Vector3fix_Subtract(&self->target,&position,&direction);
Vector3fix_Normalize(&direction,&direction);
SetObjectAngleAndClearFlagC48000((Object3D*)obj,fix32_Atan2(direction.x,direction.z));
GameObject_SetMotionState(obj,1);
*(unsigned short*)(obj+0xb2)=0xa3;
if(!_Z28IsBrightnessTransitionActiveP13GameResources(resources)) {self->state++;self->ticks=0;}
} else if(self->state==4) {
_ZN8Object3D11DisableFlagEi(obj,0x1000080);
unsigned char indices[4];
int count=GameState_CopyProtagonistPartySlotList(gs,indices);
for(int i=0;i<count;i++) {
void* object=_ZN9GameState20GetGameObjectByIndexEi(gs,indices[i]);
if(object) _ZN8Object3D11DisableFlagEi(object,0x1000000);
}
char* data=(char*)GameState_ReadUnkF8((GameState*)gs);
GameState_ReadProtagonistObjectIndex((GameState*)gs);
VectorizedMemset(data,0,0x70);
data[4]=1;data[8]=1;data[9]=1;data[0xb]=-1;
*(int*)(data+0x20)=-1;*(int*)(data+0x24)=-1;*(int*)(data+0x28)=-1;*(int*)(data+0x2c)=-1;
*(short*)(data+0x1e)=-1;data[0xc]=0;*(short*)(data+0x6c)=-1;
*(unsigned short*)data=*(unsigned short*)(self->config+0x30);
_ZN8Vector3iaSERKS_(data+0x10,self->config+0x38);
*(short*)(data+0x1c)=*(short*)(self->config+0x68);
data[0xb]=*(short*)(self->config+0x6a);
_ZN8Vector3iaSERKS_(data+0x30,self->config+0x38);
_ZN8Vector3iaSERKS_(data+0x3c,self->config+0x44);
_ZN8Vector3iaSERKS_(data+0x48,self->config+0x50);
_ZN8Vector3iaSERKS_(data+0x54,self->config+0x5c);
data[0xc]=1;data[7]=1;
GameState_ReplacePendingFieldTransition(gs,data);
Field_InitializeZoneTransitionCommand(*(void**)((unsigned char*)resources+0x370c),0);
LinkedQueue_AppendAndMarkActive(*(unsigned**)((unsigned char*)resources+0x36fc),*(unsigned*)((unsigned char*)resources+0x370c));
((unsigned char*)self)[1]=1;
}
self->ticks++;
}
