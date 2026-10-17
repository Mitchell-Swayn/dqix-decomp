#include <globaldefs.h>
struct Object {char pad[0xc8];unsigned data;char state;};
extern "C" void ApplyScaledValueToChannelIndices(Object*,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x0205E9F4; symbol: func_0205e9f4; size: 0x24.
extern "C" void SetStateWithinOneThroughFiveAndDispatch(Object* p,int state,unsigned c,unsigned d) {if(state<1)return;if(state>5)return;p->state=state;ApplyScaledValueToChannelIndices(p,p->data,c,d);}
