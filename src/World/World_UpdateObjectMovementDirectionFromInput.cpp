#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* GameState_ReadUnknownB0(void*);
void* GameResources_GetInstance();
char* ReadGlobalValueAt020FB3F0();
int Input_IsKeyBitSixSet(void*);
int Object_TestInitialHalfwordMask20(void*);
int TestInputFlag10(void*);
int Object_TestInitialHalfwordMask80(void*);
unsigned char* ReadWordAtOverlayOffset4328(void*);
int ReadSelectedCoordinatePair(void*,int*,int*);
int Vector3fix_Distance(const void*,const void*);
int _Z32IsMainBrightnessTransitionActiveP13GameResources(void*);
void ShiftCurrentByteValueToPreviousAndRefresh(unsigned char*,unsigned char);
void ChangeCurrentValueAndNotifyUpdate(void*,unsigned);
void Object_SetByteBEAndSavePreviousInBF(void*,int);
int ReadWordAtOffset70(void*);
int _Z22fix32ReduceAngle0To2Pii(int);
char* _ZN12ZoneFeatures19FindContainingEntryEPK8Vector3i(void*,const void*);
int _Z24fix32SignedAngleDistanceii(int,int);
int _Z8fix32absi(int);
void SetObjectAngleAndClearFlagC48000(void*,int);
int Object_ReadShortAtOffset22E(void*);
extern char data_02114e30[],data_02114e54[];
extern int data_020e780c[];
}
struct Vec { int x,y,z; };
// Original: arm9/main @ 0x02038138; symbol: func_02038138; size: 0x3C8.
extern "C" void World_UpdateObjectMovementDirectionFromInput(unsigned char* self) {
char* zone;void* origin;void* resources;
origin=GameState_ReadUnknownB0(_ZN9GameState11GetInstanceEv());
resources=GameResources_GetInstance();
zone=ReadGlobalValueAt020FB3F0();
int mode=0;
if(Input_IsKeyBitSixSet(data_02114e30) && Object_TestInitialHalfwordMask20(data_02114e30)) {self[0x250]=12;mode=1;}
else if(Input_IsKeyBitSixSet(data_02114e30) && TestInputFlag10(data_02114e30)) {self[0x250]=13;mode=1;}
else if(Object_TestInitialHalfwordMask80(data_02114e30) && Object_TestInitialHalfwordMask20(data_02114e30)) {self[0x250]=14;mode=1;}
else if(Object_TestInitialHalfwordMask80(data_02114e30) && TestInputFlag10(data_02114e30)) {self[0x250]=15;mode=1;}
else if(Input_IsKeyBitSixSet(data_02114e30)) {self[0x250]=8;mode=1;}
else if(Object_TestInitialHalfwordMask80(data_02114e30)) {self[0x250]=9;mode=1;}
else if(Object_TestInitialHalfwordMask20(data_02114e30)) {self[0x250]=10;mode=1;}
else if(TestInputFlag10(data_02114e30)) {self[0x250]=11;mode=1;}
unsigned char* touch=ReadWordAtOverlayOffset4328(resources);
int x,y;
if(*(int*)(data_02114e54+64)>=5 && touch[0x225] && touch[0x224]) {
mode=2;ReadSelectedCoordinatePair(data_02114e54,&x,&y);
Vec current;current.x=x<<12;current.y=y<<12;current.z=0;
x=*(int*)(data_02114e54+48);y=*(int*)(data_02114e54+52);
Vec previous;previous.x=x<<12;previous.y=y<<12;previous.z=0;
if(Vector3fix_Distance(&current,&previous)<0x8000) mode=0;
}
if(!self[0x252] || _Z32IsMainBrightnessTransitionActiveP13GameResources(resources)) mode=0;
if(mode==0) {
if(self[0x250]>=8) self[0x250]-=8;
if(self[0x252] && self[0xbe]==1) ShiftCurrentByteValueToPreviousAndRefresh(self,0);
*(signed char*)(self+0x255)=-1;
} else if(mode==1) {
if(self[0xc0]==0 || self[0xc0]==10) ChangeCurrentValueAndNotifyUpdate(self,1);
else Object_SetByteBEAndSavePreviousInBF(self,1);
int angleOffset=data_020e780c[self[0x250]-8];
int angle=_Z22fix32ReduceAngle0To2Pii(angleOffset+ReadWordAtOffset70(origin));
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
if(self[0xc0]==0) ChangeCurrentValueAndNotifyUpdate(self,1);
else Object_SetByteBEAndSavePreviousInBF(self,1);
if(touch[0x224]) SetObjectAngleAndClearFlagC48000(self,Object_ReadShortAtOffset22E(touch));
*(signed char*)(self+0x255)=-1;
}
}
