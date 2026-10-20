#include <globaldefs.h>
ARM
extern "C" int Vector3fix_Add(...);
extern "C" int Vector3fix_Subtract(...);
extern "C" int _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int _ZNK9GameState12GetTickCountEv(...);
extern "C" int fix32_Divide(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov001 @ 0x02157F10; symbol: AdvanceTimedObjectPositionVector.
extern "C" int CutsceneCamera_AdvanceTimedEyePosition(char*self,char*object){
int state=_ZN9GameState11GetInstanceEv();int tick=_ZNK9GameState12GetTickCountEv(state)<<12;int duration=W(self,28);if(!duration){memcpy(object+76,self+4,12);W(object,56)=0;return 0;}struct Vec{int x,y,z;};Vec difference;if(W(object,56)<=0){int divisor=duration<<13;Vector3fix_Subtract(self+4,object+76,&difference);W(object,180)=fix32_Divide(difference.x,divisor);W(object,184)=fix32_Divide(difference.y,divisor);W(object,188)=fix32_Divide(difference.z,divisor);}Vec delta=*(Vec*)(object+180);_Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&delta,tick,&delta);Vector3fix_Add(object+76,&delta,object+76);W(object,56)+=_ZNK9GameState12GetTickCountEv(state);if(W(object,56)>=W(self,28)*2){W(object,56)=0;return 0;}return 1;
}
