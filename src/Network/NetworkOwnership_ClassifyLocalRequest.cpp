#include <globaldefs.h>
extern "C" unsigned Network_GetConnectionManager();extern "C" int Network_IsSessionActive(unsigned);extern "C" unsigned char* NetworkOwnership_FindEntryByKey(void*,unsigned);extern "C" unsigned Network_GetLocalMemberId(unsigned);
struct Object{char pad[32];unsigned char values[8];};
// Original: arm9/main @ 0x020E34BC; symbol: func_020e34bc; size: 0x88.
extern "C" ARM unsigned char NetworkOwnership_ClassifyLocalRequest(Object* p,unsigned id){unsigned state=Network_GetConnectionManager();if(!Network_IsSessionActive(state))return 1;unsigned char* v=p->values;for(int i=0;i<8;i++,v++)if(*v==id)return 2;unsigned char* e=NetworkOwnership_FindEntryByKey(p,id);if(e){if(*e==Network_GetLocalMemberId(state))return e[2];return 3;}return 0;}
