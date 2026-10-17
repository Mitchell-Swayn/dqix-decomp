// Field widths and exact relocation-backed globals/callee contracts reviewed against original ARM.
#include <globaldefs.h>
#include <Resource/Script.h>
ARM
#pragma force_active on
struct Triple{unsigned x,y,z;};typedef void(*Callback)(void*);extern "C" {char* strcpy(char*,const char*);char* GameState_GetIndexList(void*);int GameState_ReadOffset5721ByteBufferLength(void*);unsigned CountSetBitsInWord(unsigned);extern char data_020fdc4c[],data_02111684[],data_02109404[];}
// Original: arm9/main @ 0x020D6884; symbol: func_020d6884; size: 0x30.
extern "C" unsigned ComputeMaskedIndexPopulationStrideAndBase(char* p,unsigned n,unsigned base,unsigned bits){return *(unsigned short*)(p+2064)*CountSetBitsInWord(n&((1<<bits)-1))+base;}
