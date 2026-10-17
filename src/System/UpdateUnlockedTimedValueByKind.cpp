#include <globaldefs.h>
ARM
#include <System/Timing.h>
struct State{unsigned char kind,status,locked,pad;short value;short pad6;unsigned long long timestamp;};
// Original: arm9/main @ 0x0201FC40; symbol: func_0201fc40; size: 0x60.
extern "C" void UpdateUnlockedTimedValueByKind(State* p,short value){if(p->locked)return;unsigned char kind=p->kind;if(kind==1||kind==4){p->status=3;p->value=value;p->timestamp=GetCurrentTimestamp();return;}if(kind!=3&&kind!=2)return;p->value=value;p->timestamp=GetCurrentTimestamp();}
