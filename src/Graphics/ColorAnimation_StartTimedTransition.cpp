#include <globaldefs.h>
struct State{unsigned char active;char pad[3];unsigned char ready;char gap[3];int time;};
// Original: arm9/main @ 0x020708C8; symbol: func_020708c8; size: 0x38.
extern "C" ARM void ColorAnimation_StartTimedTransition(State* p,unsigned ticks){p->time=(int)(16.667f*(float)ticks);p->ready=1;p->active=1;}
