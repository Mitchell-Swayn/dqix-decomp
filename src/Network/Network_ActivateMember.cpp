#include <globaldefs.h>
ARM
extern "C" int Network_FindWirelessSlotByMemberId();extern "C" void Network_UpdateMemberCountAndSessionTime(void*);
// Original: arm9/main @ 0x0202C1E8; symbol: func_0202c1e8; size: 0x34.
extern "C" void Network_ActivateMember(unsigned char* object){int bit=Network_FindWirelessSlotByMemberId();if(bit<0)return;object[0x100c]|=1<<bit;Network_UpdateMemberCountAndSessionTime(object);}
