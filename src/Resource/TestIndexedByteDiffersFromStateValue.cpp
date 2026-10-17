// Field widths and exact relocation-backed globals/callee contracts reviewed against original ARM.
#include <globaldefs.h>
#include <Resource/Script.h>
ARM
#pragma force_active on
struct Triple{unsigned x,y,z;};typedef void(*Callback)(void*);extern "C" {char* strcpy(char*,const char*);char* GameState_GetIndexList(void*);int GameState_ReadOffset5721ByteBufferLength(void*);unsigned CountSetBitsInWord(unsigned);extern char data_020fdc4c[],data_02111684[],data_02109404[];}
// Original: arm9/main @ 0x0206852C; symbol: func_0206852c; size: 0x2C.
extern "C" int TestIndexedByteDiffersFromStateValue(void* p){char* q=GameState_GetIndexList(p);return *(unsigned char*)(q+0xf7c)!=GameState_ReadOffset5721ByteBufferLength(p);}
