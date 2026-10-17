#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int Combat_TestCombatantBlockingFlags(void*,int,int);
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" int func_ov000_02156404(void*);
extern "C" float GameState_CalculateIndexedObjectWeightedValue(void*,int);
extern "C" int _Z13NextRandomMaxP6Randomi(void*,int);
// Original: arm9/ov000 @ 0x02156F98; symbol: func_ov000_02156f98; size: 0xB4.
extern "C" int Combat_TestDescriptorThresholdChance(char* self,int index,const char* descriptor) {
_ZN9GameState11GetInstanceEv();
if(!(*(const unsigned*)(descriptor+16)&0x20)) return 0;
if(Combat_TestCombatantBlockingFlags(self,index,0)) return 0;
void* object=_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),index);
if(!object) return 0;
if(func_ov000_02156404(object)) return *(short*)(self+0x8e6e)<50;
float threshold=GameState_CalculateIndexedObjectWeightedValue(self,index);
int random=_Z13NextRandomMaxP6Randomi(self,100);
return random<(int)threshold;
}
