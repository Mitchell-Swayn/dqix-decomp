#include <globaldefs.h>
extern "C" unsigned Object_GetGlobalConnectionState();extern "C" int IsFirstWordNonzero(unsigned);extern "C" unsigned char* FindByteKeyAmongEightRecordsWhenContextActive(void*,unsigned);extern "C" unsigned ReadIndexedSignedField1038(unsigned);
struct Object{char pad[32];unsigned char values[8];};
// Original: arm9/main @ 0x020E34BC; symbol: func_020e34bc; size: 0x88.
extern "C" ARM unsigned char ClassifyContextIdStateAndEntryOwnership(Object* p,unsigned id){unsigned state=Object_GetGlobalConnectionState();if(!IsFirstWordNonzero(state))return 1;unsigned char* v=p->values;for(int i=0;i<8;i++,v++)if(*v==id)return 2;unsigned char* e=FindByteKeyAmongEightRecordsWhenContextActive(p,id);if(e){if(*e==ReadIndexedSignedField1038(state))return e[2];return 3;}return 0;}
