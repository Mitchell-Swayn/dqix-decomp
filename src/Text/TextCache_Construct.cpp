#include <globaldefs.h>
extern "C" void TextCache_ConstructEntry(void*),TextCache_DestroyEntry(void*),TextCache_Reset(void*);extern "C" void RuntimeArrays_ConstructElementsWithRollback(void*,unsigned,unsigned,void(*)(void*),void(*)(void*));
// Original: arm9/main @ 0x0203C2C0; symbol: func_0203c2c0; size: 0x44.
extern "C" ARM char* TextCache_Construct(char* p){RuntimeArrays_ConstructElementsWithRollback(p+4,32,40,TextCache_ConstructEntry,TextCache_DestroyEntry);TextCache_Reset(p);return p;}
