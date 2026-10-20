#include <globaldefs.h>
struct Flags { unsigned char low:2; unsigned char rest:6; }; struct Object { unsigned char pad[0xc1]; Flags flags; unsigned char pad2[0x190]; unsigned char a,b; }; extern "C" int GameObject_GetLadderTraversalActive(void *); extern "C" void GameObject_SetMotionStateAndRefreshAnimation(void *,int);
// Original: arm9/main @ 0x020397CC; symbol: func_020397cc; size: 0x54.
 extern "C" void GameObject_DisableMovementInput(Object *p,int reset) { if(reset && p->a && !GameObject_GetLadderTraversalActive(p) && !(p->flags.low&2)) GameObject_SetMotionStateAndRefreshAnimation(p,0); p->b=0;p->a=0; }
