#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* _ZN9GameState14GetProtagonistEv(void*);extern "C" char* ReadWordFieldAtOffset188();extern "C" void FindGroupAndProcessHeadAfterClearingOutputCount(void*,int,void*);
// Original: arm9/main @ 0x02064A40; symbol: func_02064a40; size: 0x5C.
extern "C" void GameState_ReadProtagonistStateAndStatusKindNine(char* p,int* out){_ZN9GameState14GetProtagonistEv(_ZN9GameState11GetInstanceEv());char* e=ReadWordFieldAtOffset188();if(e){if(*(int*)(e+4)==3)out[1]=(unsigned char)e[44];}else{int v=((signed char*)p)[0x491];if(v>-1)out[1]=v;}FindGroupAndProcessHeadAfterClearingOutputCount(p,9,out);}
