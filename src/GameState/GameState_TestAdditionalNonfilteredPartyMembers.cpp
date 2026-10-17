#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void* GameState_FindIndexedObjectWithFlag1000(void*,int);extern "C" int ReadFieldAtOffset2D0(void*);
// Original: arm9/main @ 0x0206867C; symbol: func_0206867c; size: 0x64.
extern "C" int GameState_TestAdditionalNonfilteredPartyMembers(void* p){signed char count=0;for(int i=1;i<4;i++){void* object=GameState_FindIndexedObjectWithFlag1000(p,i);if(object&&!ReadFieldAtOffset2D0(object))++count;}return (signed char)(count+1)!=1;}
