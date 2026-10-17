#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" char* ReadWordFieldAtOffset150(void*);
extern "C" int _Z13NextRandomMaxP6Randomi(void*,int);
extern "C" int Object_ReadIndexedBitAtOffset8EC(unsigned char*,int);
extern "C" int Object_TestPositiveCountAndOffset2F4Bit5(char*);
extern "C" int Combat_TestCombatantBlockingFlags(void*,int,int);
extern "C" float Combat_ComputeObjectAttributeWeight(unsigned char*,int);
struct Descriptor { unsigned pad; unsigned id:12,other:20; unsigned pad2[2]; unsigned flags; };
// Original: arm9/ov000 @ 0x02156E30; symbol: func_ov000_02156e30; size: 0x168.
extern "C" int Combat_TestDescriptorAttributeRoll(unsigned char* self,int sourceIndex,int targetIndex,Descriptor* descriptor) {
 void* game=_ZN9GameState11GetInstanceEv();
 if(!(descriptor->flags&0x40)) return 0;
 if(Combat_TestCombatantBlockingFlags(self,targetIndex,0)) return 0;
 int valid;
 if(sourceIndex>=0 && sourceIndex<=3) valid=1; else valid=0;
 if(valid) {
 char* obj=GameState_GetObjectWithFlag100(game,sourceIndex);
 if(obj && (descriptor->flags&0x80000)) {
 if(Object_TestPositiveCountAndOffset2F4Bit5(*(char**)(obj+0x150))) return 0;
 }
 }
 if(!_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),targetIndex)) return 0;
 float rate=Combat_ComputeObjectAttributeWeight(self,targetIndex);
 if(targetIndex>=0 && targetIndex<=3) valid=1; else valid=0;
 if(valid) {
 if(descriptor->id==0xf4 || descriptor->id==0xf5) {
 char* obj=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),targetIndex);
 char* state=ReadWordFieldAtOffset150(obj);
 if(obj && state && *(short*)(state+0x2cc)>0) {
 if(Object_ReadIndexedBitAtOffset8EC(*(unsigned char**)(obj+0x150),40)) rate=100.0f;
 }
 }
 }
 return (float)_Z13NextRandomMaxP6Randomi(self,100)<rate;
}
