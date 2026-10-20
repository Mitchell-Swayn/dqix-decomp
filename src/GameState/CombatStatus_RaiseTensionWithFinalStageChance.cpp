#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int Object_AdvanceFourStageCounterWithRandomThirdStage(void*,void*);
// Original: arm9/main @ 0x02088208; symbol: func_02088208; size: 0x18.
extern "C" int CombatStatus_RaiseTensionWithFinalStageChance(unsigned char* p,void* context){*(unsigned*)(p+20)|=0x800000;return Object_AdvanceFourStageCounterWithRandomThirdStage(p,context);}
