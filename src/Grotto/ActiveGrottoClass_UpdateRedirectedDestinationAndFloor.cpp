#include <globaldefs.h>
ARM
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "World/ZonePredicates.h"
struct Destination {unsigned short zone;unsigned char pad[5],changed,pad2[2],unknown,pad3[5];int x,y,z;unsigned short extra;};extern "C" Destination* GameState_ReadUnkF8(GameState*);extern "C" unsigned short* Zone3D_GetMainInstance();
// Original: arm9/main @ 0x0208F944; symbol: func_0208f944; size: 0x148.
extern "C" void ActiveGrottoClass_UpdateRedirectedDestinationAndFloor(ActiveGrottoClass* object){GameState* state=GameState::GetInstance();Destination* dest=GameState_ReadUnkF8(state);signed char* grotto=(signed char*)state->GetGrottoStruct();unsigned short* current=Zone3D_GetMainInstance();int zone=dest->zone;unsigned short oldZone=*current;if(((unsigned char*)object)[0x262]&&zone!=0xc3b5){dest->zone=*(unsigned short*)((unsigned char*)object+0x274);dest->changed=1;dest->extra=0x3244;dest->x=object->unknown_264_[1];dest->y=object->unknown_264_[2];dest->z=object->unknown_264_[3];dest->unknown=0;zone=(unsigned short)object->unknown_274_;}((unsigned char*)object)[0x262]=0;if(!IsGrottoZone(zone)&&IsGrottoZone(oldZone)&&(zone<30000||zone>39999))object->overallMapData_.Clear();if(IsGrottoZone(zone)&&!IsGrottoZone(oldZone)){signed char floor=grotto[8];if(floor!=-1&&!IsGrottoBossFloorZone(zone))dest->zone=(zone%20+0x9c40)+floor*20;}object->unknown_260_[0]=0;}
