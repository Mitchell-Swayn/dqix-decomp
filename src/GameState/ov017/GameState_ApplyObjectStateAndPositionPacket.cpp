#include <globaldefs.h>
ARM
#pragma opt_arithtransformation off
#include <Graphics/Vector.h>
struct Zone3D; struct Object3D; struct Object;
struct Mode { unsigned char index:6,flagA:1,flagB:1; };
struct SignedNibble { signed char low:4,high:4; };
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" void* _ZN8Vector3iaSERKS_(void*,const void*);
extern "C" int Zone3D_FindGroundHeightBelowPosition(Zone3D*,const Vector3i*);
extern "C" bool TestActiveWordAndGlobalStateNonzero(unsigned*);
extern "C" void SetObjectAngleAndClearFlagC48000(Object3D*,int);
extern "C" int Object_GetOffsetE4RecordWhenBit6Set(int);
extern "C" bool Object_InvokeStateMethodAndRecordSuccessfulTransition(Object*,int);
extern "C" int GameState_ResolveMonsterRecordAndTestState(void*,void*,int);
// Original: arm9/ov017 @ 0x021C96C0; symbol: func_ov017_021c96c0; size: 0x234.
extern "C" void GameState_ApplyObjectStateAndPositionPacket(void*,char* packet,void*,void*,unsigned* connection) {
 void* info[3]; Vector3i position;
 char* zone=(char*)ReadGlobalValueAt020FB3F0();
 if(!GameState_ResolveMonsterRecordAndTestState(packet+4,info,((Mode*)(packet+6))->index)) return;
 if(((Mode*)(packet+6))->index==10) *(short*)((char*)info[2]+0x166)=((SignedNibble*)(packet+7))->high;
 if(((Mode*)(packet+6))->index==1) {
  position.x=*(int*)(packet+0xc); position.y=*(short*)(packet+0xa)<<4; position.z=*(int*)(packet+0x10);
  unsigned short id=*(unsigned short*)(packet+4);
  int angle=*(short*)(packet+8);
  int flagA=((Mode*)(packet+6))->flagA?1:0;
  int flagB=((Mode*)(packet+6))->flagB?1:0;
  if(!(id==*(unsigned short*)zone && *(int*)((char*)info[2]+0x130)==1)) {
   if(position.x || position.y || position.z) {
    if(TestActiveWordAndGlobalStateNonzero(connection)) {
     if(!Object_GetOffsetE4RecordWhenBit6Set((int)info[2])) _ZN8Vector3iaSERKS_((char*)info[2]+0x44,&position);
     else *(Vector3i*)((char*)info[2]+0x44)=position;
    } else *(Vector3i*)((char*)info[2]+0x44)=position;
   }
  }
  if(*(unsigned short*)(packet+4)==*(unsigned short*)zone && !*(int*)(zone+0x424) && *(int*)((char*)info[2]+0x130)!=1 && (position.x || position.y || position.z)) {
   if(Object_GetOffsetE4RecordWhenBit6Set((int)info[2])) position=*(Vector3i*)((char*)info[2]+0x44);
   position.y=Zone3D_FindGroundHeightBelowPosition((Zone3D*)zone,&position);
   *(Vector3i*)((char*)info[2]+0x44)=position;
  }
  if(angle) SetObjectAngleAndClearFlagC48000((Object3D*)info[2],angle);
  if(flagA) *(unsigned char*)((char*)info[2]+0x17b)=1;
  if(flagB) *(unsigned char*)((char*)info[2]+0x17c)=1;
  int state=*(int*)((char*)info[2]+0x130);
  switch(state) { case 4: case 5: case 6: *(int*)((char*)info[2]+0x154)=0; break; }
 }
 Object_InvokeStateMethodAndRecordSuccessfulTransition((Object*)info[2],((Mode*)(packet+6))->index);
}
