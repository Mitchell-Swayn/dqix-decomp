#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" char* ReadWordFieldAtOffset150(void*);
extern "C" int _Z13NextRandomMaxP6Randomi(void*,int);
extern "C" float _Z17CalculateCritRateifffh(int,float,float,float,unsigned char);
extern "C" float Float_ComputeScaledZeroProduct(float,unsigned);
extern "C" int Object_ReadIndexedBitAtOffset8EC(unsigned char*,int);
extern "C" float SumActiveLinkedWordCBits20To29DividedByTen(char*);
extern "C" int ReadDescriptorDependentStateValue(char*,void*);
extern "C" float Object_GetHalfwordRatioAt138(void*);
struct Descriptor { unsigned pad[2]; unsigned a:29,always:1,b:2; unsigned pad2[2]; unsigned c:21,rate:7,d:4; };
struct StateWord { unsigned value:10,other:22; };
// Original: arm9/ov000 @ 0x02156CC4; symbol: func_ov000_02156cc4; size: 0x16C.
extern "C" int Combat_TestCriticalHitRoll(void* random,int index,Descriptor* descriptor,unsigned bonus) {
 if(descriptor->always) return 1;
 void* game=_ZN9GameState11GetInstanceEv();
 float rate;
 int valid;
 if(index>=0 && index<=3) valid=1; else valid=0;
 if(valid) {
 char* obj=GameState_GetObjectWithFlag100(game,index);
 char* state=ReadWordFieldAtOffset150(obj);
 int value=((StateWord*)(state+4))->value;
 float linked=SumActiveLinkedWordCBits20To29DividedByTen(state);
 float dependent=(float)ReadDescriptorDependentStateValue(state,descriptor);
 rate=_Z17CalculateCritRateifffh(value,linked,dependent,(float)descriptor->rate/100.0f,(unsigned char)bonus);
 if(Object_ReadIndexedBitAtOffset8EC(*(unsigned char**)(obj+0x150),0x11d)) {
 if(Object_GetHalfwordRatioAt138(obj)<0.25f) rate*=2.0f;
 }
 } else rate=Float_ComputeScaledZeroProduct((float)descriptor->rate/100.0f,(unsigned char)bonus);
 float scaled=100.0f*rate;
 int roll=_Z13NextRandomMaxP6Randomi(random,10000);
 return roll<(int)scaled;
}
