// Field widths and exact relocation-backed globals/callee contracts reviewed against original ARM.
#include <globaldefs.h>
#include <Resource/Script.h>
ARM
#pragma force_active on
struct Triple{unsigned x,y,z;};typedef void(*Callback)(void*);extern "C" {char* strcpy(char*,const char*);char* GameState_GetIndexList(void*);int GameState_ReadOffset5721ByteBufferLength(void*);unsigned CountSetBitsInWord(unsigned);extern char data_020fdc4c[],data_02111684[],data_02109404[];}
// Original: arm9/main @ 0x0201FA00; symbol: func_0201fa00; size: 0x2C.
extern "C" void InitializeFlagsAndDoublePrecisionConstant(char* p){p[0]=1;p[1]=0;*(short*)(p+4)=0;*(unsigned*)(p+16)=0x43300000;*(int*)(p+8)=0;*(int*)(p+12)=0;}
