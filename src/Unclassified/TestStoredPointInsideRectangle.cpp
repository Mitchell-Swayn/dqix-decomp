// Reviewed original ARM fields and signedness; global ownership resolved through original relocation.
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
extern "C" {char* FindThirtyTwoByteRecordByHalfwordKey(void*,int);void* memset(void*,int,unsigned);extern char data_0210f3c0[];}
// Original: arm9/main @ 0x02012734; symbol: func_02012734; size: 0x4C.
extern "C" int TestStoredPointInsideRectangle(char* p,int x,int y,int width,int height){int a=*(unsigned short*)(p+32);int b=*(unsigned short*)(p+34);if(a<x)return 0;if(a>x+width)return 0;if(b<y)return 0;return b<=y+height;}
