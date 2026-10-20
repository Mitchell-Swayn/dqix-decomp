#include <globaldefs.h>
ARM
extern "C" char* _ZN9GameState11GetInstanceEv();
extern "C" char* Network_GetConnectionManager();
extern "C" unsigned Network_TestMemberDisconnectFlag(char*,int);
extern "C" void Menu_ChargePurchaseAndReduceOfferStock(void*);
extern "C" void Menu_QueueScriptEntry(void*,unsigned);
struct ModeBits {unsigned short low:13;unsigned short mode:3;};
// Original: arm9/ov004 @ 0x0215D670; symbol: DispatchConnectionModeAction; size: 0x88.
// Dispatches mode-specific actions or reports that connection key zero is clear.
extern "C" int Menu_HandleNetworkPurchaseResponse(void* self) {
char* game=_ZN9GameState11GetInstanceEv()+0x26c;
char* connection=Network_GetConnectionManager();
unsigned mode=((ModeBits*)(game+0x5d0c))->mode;
if(mode==1){Menu_ChargePurchaseAndReduceOfferStock(self);return 0;}
if(mode==2){Menu_QueueScriptEntry(self,0x2367);return 0;}
if(!Network_TestMemberDisconnectFlag(connection,0))return 1;
Menu_QueueScriptEntry(self,0x2369);return 0;
}
