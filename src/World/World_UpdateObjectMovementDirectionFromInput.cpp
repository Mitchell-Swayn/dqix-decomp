#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* GameState_ReadUnknownB0(void*);
void* GameResources_GetInstance();
char* Zone3D_GetMainInstance();
int Input_IsKeyBitSixSet(void*);
int Input_IsLeftHeld(void*);
int Input_IsRightHeld(void*);
int Input_IsDownHeld(void*);
unsigned char* GameResources_GetTouchMovementController(void*);
int ReadSelectedCoordinatePair(void*,int*,int*);
int Vector3fix_Distance(const void*,const void*);
int _Z32IsMainBrightnessTransitionActiveP13GameResources(void*);
void GameObject_SetMotionStateAndRefreshAnimation(unsigned char*,unsigned char);
void GameObject_ChangeMotionStateAndRefreshAnimation(void*,unsigned);
void GameObject_SetMotionState(void*,int);
int Camera_GetOrbitHeading(void*);
int _Z22fix32ReduceAngle0To2Pii(int);
char* _ZN12ZoneFeatures19FindContainingEntryEPK8Vector3i(void*,const void*);
int _Z24fix32SignedAngleDistanceii(int,int);
int _Z8fix32absi(int);
void SetObjectAngleAndClearFlagC48000(void*,int);
int TouchMovement_GetDirectionAngle(void*);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[],Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original data: arm9/main @ 0x20e780c; symbol: data_020e780c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 4432000000000000664b000022190000d53e0000b3250000f7570000910c000005000000.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern int WorldUpdateObjectMovementDirectionFromInput_UnknownRoleInitializedBytes[];
}
struct Vec { int x,y,z; };
// Original: arm9/main @ 0x02038138; symbol: func_02038138; size: 0x3C8.
extern "C" void World_UpdateObjectMovementDirectionFromInput(unsigned char* self) {
char* zone;void* origin;void* resources;
origin=GameState_ReadUnknownB0(_ZN9GameState11GetInstanceEv());
resources=GameResources_GetInstance();
zone=Zone3D_GetMainInstance();
int mode=0;
if(Input_IsKeyBitSixSet(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage) && Input_IsLeftHeld(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage)) {self[0x250]=12;mode=1;}
else if(Input_IsKeyBitSixSet(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage) && Input_IsRightHeld(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage)) {self[0x250]=13;mode=1;}
else if(Input_IsDownHeld(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage) && Input_IsLeftHeld(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage)) {self[0x250]=14;mode=1;}
else if(Input_IsDownHeld(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage) && Input_IsRightHeld(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage)) {self[0x250]=15;mode=1;}
else if(Input_IsKeyBitSixSet(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage)) {self[0x250]=8;mode=1;}
else if(Input_IsDownHeld(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage)) {self[0x250]=9;mode=1;}
else if(Input_IsLeftHeld(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage)) {self[0x250]=10;mode=1;}
else if(Input_IsRightHeld(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage)) {self[0x250]=11;mode=1;}
unsigned char* touch=GameResources_GetTouchMovementController(resources);
int x,y;
if(*(int*)(Main_UnknownRoleZeroInitializedStorage_Variant4+64)>=5 && touch[0x225] && touch[0x224]) {
mode=2;ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);
Vec current;current.x=x<<12;current.y=y<<12;current.z=0;
x=*(int*)(Main_UnknownRoleZeroInitializedStorage_Variant4+48);y=*(int*)(Main_UnknownRoleZeroInitializedStorage_Variant4+52);
Vec previous;previous.x=x<<12;previous.y=y<<12;previous.z=0;
if(Vector3fix_Distance(&current,&previous)<0x8000) mode=0;
}
if(!self[0x252] || _Z32IsMainBrightnessTransitionActiveP13GameResources(resources)) mode=0;
if(mode==0) {
if(self[0x250]>=8) self[0x250]-=8;
if(self[0x252] && self[0xbe]==1) GameObject_SetMotionStateAndRefreshAnimation(self,0);
*(signed char*)(self+0x255)=-1;
} else if(mode==1) {
if(self[0xc0]==0 || self[0xc0]==10) GameObject_ChangeMotionStateAndRefreshAnimation(self,1);
else GameObject_SetMotionState(self,1);
int angleOffset=WorldUpdateObjectMovementDirectionFromInput_UnknownRoleInitializedBytes[self[0x250]-8];
int angle=_Z22fix32ReduceAngle0To2Pii(angleOffset+Camera_GetOrbitHeading(origin));
if(*(signed char*)(self+0x255)==self[0x250]) angle=*(short*)(self+0x256);
else {
char* entry=_ZN12ZoneFeatures19FindContainingEntryEPK8Vector3i(zone+108,self+68);
if(entry) {
if(_Z8fix32absi(_Z24fix32SignedAngleDistanceii(angle,*(short*)(entry+24)))<0xc91) {
self[0x255]=self[0x250];*(short*)(self+0x256)=*(short*)(entry+24);
} else {
short opposite=_Z22fix32ReduceAngle0To2Pii(*(short*)(entry+24)+0x3244);
if(_Z8fix32absi(_Z24fix32SignedAngleDistanceii(angle,opposite))<0xc91) {
self[0x255]=self[0x250];*(short*)(self+0x256)=opposite;angle=*(short*)(self+0x256);
}}
} else *(signed char*)(self+0x255)=-1;
}
SetObjectAngleAndClearFlagC48000(self,angle);
} else if(mode==2) {
if(self[0xc0]==0) GameObject_ChangeMotionStateAndRefreshAnimation(self,1);
else GameObject_SetMotionState(self,1);
if(touch[0x224]) SetObjectAngleAndClearFlagC48000(self,TouchMovement_GetDirectionAngle(touch));
*(signed char*)(self+0x255)=-1;
}
}
