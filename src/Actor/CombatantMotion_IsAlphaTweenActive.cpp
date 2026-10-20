#include <globaldefs.h>
#pragma optimize_for_size off
struct Object{char pad[0x13c];unsigned char* target;};
// Original: arm9/main @ 0x02049FC0; symbol: func_02049fc0; size: 0x2C.
extern "C" ARM int CombatantMotion_IsAlphaTweenActive(Object* p){unsigned char* target=p->target;if(target==0)return 0;return *(float*)(target+100)!=0.f;}
