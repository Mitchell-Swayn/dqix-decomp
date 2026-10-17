#include <globaldefs.h>
#include <Grotto/Main/ActiveGrottoClass.h>
#include <World/ZonePredicates.h>
extern "C" unsigned char* ReadGlobalValueAt020FB3F0();extern "C" void SetNestedSecondWordForTypeThree(unsigned,int);
// Original: arm9/main @ 0x0209DA48; symbol: func_0209da48; size: 0x5C.
extern "C" ARM int Grotto_WriteCurrentOrBossFloorIndexThroughOutput(unsigned value){int floor=(signed char)ReadGlobalValueAt020FB3F0()[0x23ba];ActiveGrottoClass* grotto=(ActiveGrottoClass*)(ReadGlobalValueAt020FB3F0()+0x23ec);if(!grotto)floor=0;else if(IsGrottoBossFloorZone(*(unsigned short*)ReadGlobalValueAt020FB3F0()))floor=grotto->GetFloorCount()+1;SetNestedSecondWordForTypeThree(value,floor);return 1;}
