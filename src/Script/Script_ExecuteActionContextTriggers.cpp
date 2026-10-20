#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);extern "C" char* GameObject_GetActionContextValue(void*);extern "C" void Script_ExecuteFirstSatisfiedTriggerGroup(void*,int,void*);
// Original: arm9/main @ 0x02064A9C; symbol: func_02064a9c; size: 0x5C.
extern "C" ARM void Script_ExecuteActionContextTriggers(char* p,int* out){char* obj=GameObject_GetActionContextValue(_ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv()));if(obj){if(*(int*)(obj+4)==3)out[1]=(unsigned char)obj[0x2c];}else{int value=(signed char)p[0x491];if(value>-1)out[1]=value;}Script_ExecuteFirstSatisfiedTriggerGroup(p,19,out);}
