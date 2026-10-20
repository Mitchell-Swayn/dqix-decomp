#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
// Original: arm9/ov002 @ 0x021549C8; symbol: func_ov002_021549c8; size: 0x6C.
// Clears the requested status bits from a resolved actor and reports whether they were present.
extern "C" int PartyMenu_ClearTargetStatusMask(void*,int key,unsigned mask,unsigned char* result) {
 char* actor=(char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),key);
 if(!actor)return 0;
 unsigned* status=*(unsigned**)(actor+0x130);
 if(*status&mask){*status=(unsigned short)(*status&~mask);*result=3;}
 else {*result=0;return 0;}
 return 1;
}
