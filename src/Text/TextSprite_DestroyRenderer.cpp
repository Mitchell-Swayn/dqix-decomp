#include <globaldefs.h>
extern "C" void TextCache_Reset(void*),TextCache_DestroyEntry(void*);extern "C" void __cxa_vec_cleanup(void*,unsigned,unsigned,void(*)(void*));
// Original: arm9/main @ 0x0203C75C; symbol: func_0203c75c; size: 0x38.
extern "C" ARM char* TextSprite_DestroyRenderer(char* p){TextCache_Reset(p+16);TextCache_Reset(p+16);__cxa_vec_cleanup(p+20,32,40,TextCache_DestroyEntry);return p;}
