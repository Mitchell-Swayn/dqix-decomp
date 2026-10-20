#include <globaldefs.h>
extern "C" void GameResources_GetInstance();extern "C" unsigned short* Zone3D_GetMainInstance();struct Object {char pad[0xac];unsigned zone,result;};
// Original: arm9/main @ 0x0208B4D4; symbol: func_0208b4d4; size: 0x34.
extern "C" ARM unsigned PartyProgress_ReadRecoveryZoneGate(Object* p){GameResources_GetInstance();unsigned zone=*Zone3D_GetMainInstance();if(zone!=p->zone){p->result=0;p->zone=-1;}return p->result;}
