#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3DEmbeddedState.h>
ARM
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" void* ZoneState2754_FindPrimaryRecordByKey(ZoneState2754*,int);
extern "C" unsigned Shop_GetAdjustedItemPrice(char*,unsigned short*);
// Original: arm9/ov003 @ 0x021758CC; symbol: Shop_CanAffordItemQuantity; size: 0x58.
// Tests a scaled record value times quantity against index-list word 0xF6C.
// The application meaning of that limit remains unknown.
extern "C" int Shop_CanAffordItemQuantity(char* self,unsigned quantity)
{
 unsigned short* record=(unsigned short*)ZoneState2754_FindPrimaryRecordByKey((ZoneState2754*)(self+0x874),*(short*)(self+0x103a));
 if(!record)return 0;
 unsigned product=quantity*Shop_GetAdjustedItemPrice(self,record);
 int result=0;
 char* list=(char*)GameState_GetIndexList(GameState::GetInstance());
 if(product<=*(unsigned*)(list+0xf6c))result=1;
 return result;
}
