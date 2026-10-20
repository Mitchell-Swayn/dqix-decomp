#include <globaldefs.h>
ARM
#include <Graphics/Vector.h>
struct GameState;
struct ZoneTintState;
struct State;
struct Record { unsigned char a,b,c,d;unsigned short e;short f,g,h;Vector3i vectors[5];int i,j;short k;unsigned char l,m,n,pad[3];int o,p,q; };
struct Flags { unsigned char bit0:1,rest:7; };
extern "C" void _ZN8Object3D10SetField06Et(void*,unsigned short);
extern "C" void Object3D_SetNormalizedAngleAndUpdatePosition(char*,int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" ZoneTintState* GameState_ReadUnkF8(GameState*);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void* GameObject_ResetFollowTrail(unsigned char*);
extern "C" void InitializeRecordWithEnabledAndPercentDefaults(char*);
extern "C" void _ZN8Object3D11DisableFlagEi(void*,int);
extern "C" void _ZN8Object3D10EnableFlagEi(void*,int);
extern "C" void GameObject_SetMotionStateAndRefreshAnimation(unsigned char*,unsigned char);
extern "C" void Field_QueuePartyAnimationCommand(void*,int,int);
extern "C" void Field_QueuePartyAnimationReset(int);
extern "C" unsigned char* _ZN12ZoneFeatures14FindType9EntryEi(void*,int);
extern "C" void GameObject_CopyLadderTraversalState(State*,Record*);
extern "C" void _ZN8Object3D18SetAnimationByNameEPKci(void*,const char*,int);
extern "C" void GameObject_DisableMovementInput(void*,int);
extern "C" char GameObject_AdvanceLadderTraversal_TextHasigoLoop[];
// Original: arm9/main @ 0x020399B0; symbol: func_020399b0; size: 0x374.
extern "C" void World_InitializeObjectFromLinkedZoneFeatures(unsigned char* object,unsigned short field,const Vector3i* position,int angle) {
_ZN8Object3D10SetField06Et(object,field);
*(Vector3i*)(object+0x44)=*position;
Object3D_SetNormalizedAngleAndUpdatePosition((char*)object,angle);
*(short*)(object+0xb2)=0;
if(*(char*)(object+0x1c9)>0) object[0x1ce]|=4;
*(char*)(object+0x1cb)=-1;
object[0x1cc]=0;
unsigned char* state=(unsigned char*)GameState_ReadUnkF8((GameState*)_ZN9GameState11GetInstanceEv());
unsigned char* zone=(unsigned char*)Zone3D_GetMainInstance();
GameObject_ResetFollowTrail(object);
if(state[0x66]) {
InitializeRecordWithEnabledAndPercentDefaults((char*)object+0x26c);
((Flags*)(object+0xe0))->bit0=0;
_ZN8Object3D11DisableFlagEi(object,0x1180);
GameObject_SetMotionStateAndRefreshAnimation(object,0);
Field_QueuePartyAnimationCommand(object+0x26c,0,1);
}
if(*(short*)(state+0x6c)<0) {GameObject_SetMotionStateAndRefreshAnimation(object,0);return;}
if(*(short*)(state+0x6c)==9999) {
_ZN8Object3D11DisableFlagEi(object,0x1000);
Field_QueuePartyAnimationReset(-1);
Field_QueuePartyAnimationCommand(object+0x26c,0,1);
return;
}
Record record;
InitializeRecordWithEnabledAndPercentDefaults((char*)&record);
unsigned char* source=_ZN12ZoneFeatures14FindType9EntryEi(zone+0x6c,*(short*)(state+0x6c));
if(!source) return;
int cosine=fix32cos(*(short*)(source+0x20));
Vector3i direction;
direction.x=fix32sin(*(short*)(source+0x20));direction.y=0;direction.z=cosine;
Vector3fix_Normalize(&direction,&direction);
unsigned char* target=_ZN12ZoneFeatures14FindType9EntryEi(zone+0x6c,*(unsigned short*)(source+0x2e));
if(!target) return;
if(source[0x31]&1) {
record.p=(int)source;record.o=(int)target;
record.vectors[0]=*(Vector3i*)(target+8);
record.vectors[1]=*(Vector3i*)(source+8);
record.vectors[3]=*(Vector3i*)(target+8);
record.vectors[4]=*(Vector3i*)(source+8);
record.g=*(short*)(target+0x20);
record.h=*(short*)(source+0x20);
record.g-=0x3243;
record.d=1;
record.vectors[4].x+=direction.x;
record.vectors[4].z+=direction.z;
record.vectors[1].y-=0x1000;
if(record.g<0) record.g+=0x6487;
} else {
record.p=(int)target;record.o=(int)source;
record.vectors[0]=*(Vector3i*)(source+8);
record.vectors[1]=*(Vector3i*)(target+8);
record.vectors[3]=*(Vector3i*)(source+8);
record.vectors[4]=*(Vector3i*)(target+8);
record.g=*(short*)(source+0x20);
record.h=*(short*)(target+0x20);
record.g-=0x3243;
record.d=0;
record.vectors[4].x+=direction.x;
record.vectors[4].z+=direction.z;
record.vectors[1].y-=0x1000;
if(record.g<0) record.g+=0x6487;
}
record.b=2;record.a=1;record.f=*(short*)(source+0x20);
GameObject_CopyLadderTraversalState((State*)object,&record);
int difference=record.vectors[1].y-record.vectors[0].y;
int factor=*(short*)(state+0x6a);
int y=record.vectors[0].y+(int)(((long long)difference*factor+0x800)>>12);
Vector3i current;
current=*(Vector3i*)(object+0x44);
current.y=y;
*(Vector3i*)(object+0x44)=current;
Object3D_SetNormalizedAngleAndUpdatePosition((char*)object,*(short*)(source+0x20));
_ZN8Object3D18SetAnimationByNameEPKci(object,GameObject_AdvanceLadderTraversal_TextHasigoLoop,0);
_ZN8Object3D10EnableFlagEi(object,0x180);
((Flags*)(object+0xe0))->bit0=1;
GameObject_DisableMovementInput(object,1);
}
