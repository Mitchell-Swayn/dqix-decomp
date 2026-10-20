#include <globaldefs.h>
ARM
extern "C" unsigned* DisplayLayout_FindPartById(void*,int);extern "C" unsigned MessageTextTable_FindTextById(void*,int);
// Original: arm9/main @ 0x02080FE0; symbol: func_02080fe0; size: 0x30.
extern "C" void TextCanvas_SetEntryTextFromResourceKey(unsigned char* p,int key,int value){unsigned* q=DisplayLayout_FindPartById(p+4,key);if(!q)return;*q=MessageTextTable_FindTextById(*(void**)p,value);}
