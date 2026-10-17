// Field widths and exact relocation-backed globals/callee contracts reviewed against original ARM.
#include <globaldefs.h>
#include <Resource/Script.h>
ARM
#pragma force_active on
struct Triple{unsigned x,y,z;};typedef void(*Callback)(void*);extern "C" {char* strcpy(char*,const char*);char* GameState_GetIndexList(void*);int GameState_ReadOffset5721ByteBufferLength(void*);unsigned CountSetBitsInWord(unsigned);extern char data_020fdc4c[],data_02111684[],data_02109404[];}
// Original: arm9/main @ 0x02049B20; symbol: func_02049b20; size: 0x34.
extern "C" void Object_WriteNestedPositionXZAndClearFlag2(char* p,const unsigned* v){char* q=*(char**)(p+316);if(!q)return;*(unsigned*)(q+4)=v[0];*(unsigned*)(*(char**)(p+316)+12)=v[2];*(unsigned*)(*(char**)(p+316)+32)&=~2;}
