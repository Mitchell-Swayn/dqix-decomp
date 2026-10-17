#include <globaldefs.h>
ARM
struct DispatchOwner { unsigned char pad[0xec]; unsigned char first,second; };
typedef void (DispatchOwner::*Handler)();
struct SevenHandlers { Handler handlers[7]; };
struct HandlerTable { SevenHandlers block; Handler last; };
extern "C" {
void* _ZN9GameState11GetInstanceEv();
unsigned _ZNK9GameState12GetTickCountEv(void*);
extern SevenHandlers data_ov003_0217fa20,data_ov003_0217fa58;
extern Handler data_020e6d5c;
}
// Original: arm9/ov003 @ 0x021727C8; symbol: func_ov003_021727c8; size: 0x134.
extern "C" int System_DispatchTwoIndexedMemberHandlers(DispatchOwner* p) {
_ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
int first=0,second=0;
SevenHandlers a=data_ov003_0217fa20;
a.handlers[6]=data_020e6d5c;
SevenHandlers b=data_ov003_0217fa58;
b.handlers[6]=data_020e6d5c;
if(a.handlers[p->first]) (p->*a.handlers[p->first])(); else first=1;
if(b.handlers[p->second]) (p->*b.handlers[p->second])(); else second=1;
if(first&&second) return 0;
return 1;
}
