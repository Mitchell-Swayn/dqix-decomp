#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void* memset(void*,int,unsigned);
extern "C" int _ffix(unsigned);
extern "C" unsigned _fflt(int);
extern "C" unsigned _fsub(unsigned,unsigned);
extern "C" int ReadWordAtOffset70(void*);
extern "C" void GameState_CopyObjectValueAndUpdateTwoModeFlags(unsigned*,unsigned,unsigned);
extern "C" void Object_SelectNamedAnimationIfEntryPresent(unsigned char*,const char*);
extern "C" void Object_SetWordAtOffset23CTo1(void*);
extern "C" void ClearWordAtOffset23C(void*);
extern "C" signed char data_020efc18;
extern "C" char data_020efd54[],data_020efd60[],data_020efd6c[],data_020efd78[],data_020efd84[];
// Original: arm9/main @ 0x0203CA24; symbol: func_0203ca24; size: 0x1B4.
extern "C" void Motion_SelectAnimationFromAngleAndTickState(char* self,void* other) {
 ClearWordAtOffset23C(other);
 int angle=ReadWordAtOffset70(other);
 int upper=_ffix(_fsub(0x46c91000,_fflt(0x648)));
 char name[20];
 memset(name,0,19);
 int mode=data_020efc18;
 if((mode>-1 && mode==0)||angle<0x648||upper<=angle) {
  if(*(int*)(self+0x98)>*(int*)(self+4))memcpy(name,data_020efd54,11);
  else memcpy(name,data_020efd60,11);
  data_020efc18=0;
 } else if((mode>-1 && mode==1)||angle<0x3244) {
  memcpy(name,data_020efd6c,11);data_020efc18=1;
 } else {
  memcpy(name,data_020efd78,11);data_020efc18=2;
 }
 if(*(unsigned*)(self+0x5c)&0x20) {
  memcpy((void*)((unsigned)name+11),data_020efd84,7);
  name[19]=0;
  --*(unsigned char*)(self+0x94);
  if(!*(unsigned char*)(self+0x94)) {
   GameState_CopyObjectValueAndUpdateTwoModeFlags((unsigned*)self,0,0);
   *(unsigned char*)(self+0x94)=15;
   Object_SetWordAtOffset23CTo1(other);
   data_020efc18=-1;
  }
 }
 Object_SelectNamedAnimationIfEntryPresent((unsigned char*)self,name);
}
