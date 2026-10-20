#include <globaldefs.h>
#include <Grotto/Main/ActiveGrottoClass.h>
#include <World/ZonePredicates.h>
extern "C" unsigned char* Zone3D_GetMainInstance();extern "C" void Script_WriteIntegerReferenceOutput(unsigned,int);
// Original: arm9/main @ 0x0209DA48; symbol: func_0209da48; size: 0x5C.
extern "C" ARM int Grotto_WriteCurrentOrBossFloorIndexThroughOutput(unsigned value){int floor=(signed char)Zone3D_GetMainInstance()[0x23ba];ActiveGrottoClass* grotto=(ActiveGrottoClass*)(Zone3D_GetMainInstance()+0x23ec);if(!grotto)floor=0;else if(IsGrottoBossFloorZone(*(unsigned short*)Zone3D_GetMainInstance()))floor=grotto->GetFloorCount()+1;Script_WriteIntegerReferenceOutput(value,floor);return 1;}
