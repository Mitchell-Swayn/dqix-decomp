#include <globaldefs.h>
ARM
#pragma always_inline on
#pragma opt_arithtransformation off
#pragma opt_propagation off
struct Vec {int x,y,z;};
extern "C" void* ReadGlobalAt020FDD44();
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" char* FindRecordAmongFourByNonnegativeKey(void*,int);
extern "C" char* FindSixteenByteEntryByKey(char*,int);
extern "C" void Vector3fix_Subtract(const Vec*,const Vec*,Vec*);
extern "C" int Vector3fix_Length(const Vec*);
extern "C" void Vector3fix_Normalize(const Vec*,Vec*);
extern "C" int fix32_Atan2(int,int);
extern "C" void SetObjectAngleAndClearFlagC48000(void*,int);
extern "C" void ChangeCurrentValueAndNotifyUpdate(void*,unsigned);
extern "C" void _ZN8Object3D10EnableFlagEi(void*,int);
extern "C" void _ZN8Object3D11DisableFlagEi(void*,int);
extern "C" void* Object_GetGlobalConnectionState();
extern "C" int IsFirstWordNonzero(void*);
extern "C" int ReadIndexedSignedField1038(char*);
extern "C" void System_QueueType84Record(int,int,int,int,Vec,Vec,int);
// Original: arm9/main @ 0x02076FDC; symbol: func_02076fdc; size: 0x220.
extern "C" int Object_BeginMovementTowardIndexedRecord(char* p) {
 Vec direction;
 void* global=ReadGlobalAt020FDD44();
 char* group=FindRecordAmongFourByNonnegativeKey(global,_ZNK8Object3D10GetField06Ev(p));
 if(!group)return 0;
 group+=0x18;
 if(!group)return 0;
 char* entry=FindSixteenByteEntryByKey(group,*(unsigned short*)(p+0x164));
 if(!entry)return 0;
 *(int*)(p+0x158)=*(short*)(entry+4)<<12;
 *(int*)(p+0x15c)=*(short*)(entry+6)<<12;
 *(int*)(p+0x160)=*(short*)(entry+8)<<12;
 Vector3fix_Subtract((Vec*)(p+0x158),(Vec*)(p+0x44),&direction);
 if(Vector3fix_Length(&direction)<4096)return 0;
 Vector3fix_Normalize(&direction,&direction);
 SetObjectAngleAndClearFlagC48000(p,fix32_Atan2(direction.x,direction.z));
 *(unsigned char*)(p+0x17d)|=64;
 switch(*(unsigned char*)(p+0x139)) {
 case 0:*(short*)(p+0xb4)=0;*(short*)(p+0xb2)=0;break;
 case 1:*(short*)(p+0xb4)=154;*(short*)(p+0xb2)=154;break;
 case 2:*(short*)(p+0xb4)=230;*(short*)(p+0xb2)=230;break;
 case 3:*(short*)(p+0xb4)=450;*(short*)(p+0xb2)=450;break;
 }
 ChangeCurrentValueAndNotifyUpdate(p,1);
 if(*(int*)(p+0x134)==4||*(int*)(p+0x134)==5||*(int*)(p+0x134)==6)_ZN8Object3D11DisableFlagEi(p,128);
 else _ZN8Object3D10EnableFlagEi(p,128);
 char* connection=(char*)Object_GetGlobalConnectionState();
 if(IsFirstWordNonzero(connection)&&ReadIndexedSignedField1038(connection)==0) {
  int id=_ZNK8Object3D10GetField06Ev(p);
  int kind=*(volatile short*)(p+4);
  int field=*(short*)(p+2);
  Vec position=*(Vec*)(p+0x44);
  Vec rotation=*(Vec*)(p+0x50);
  int remainder=(kind-112)%12;
  if(remainder>=0&&remainder<12)System_QueueType84Record(id,remainder,field,*(unsigned char*)entry,position,rotation,-1);
 }
 return 1;
}
