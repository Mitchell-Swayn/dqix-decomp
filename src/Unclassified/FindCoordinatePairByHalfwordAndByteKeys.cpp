// Cached exact ARM behavior, header-defined VRAM contracts and original relocation globals reviewed.
#include <globaldefs.h>
#include <Graphics/VRAMStaging.h>
#include <GameState/GameState.h>
#include <Resource/Script.h>
ARM
#pragma force_active on
struct Twelve{unsigned count:12,rest:20;};struct Bit13{unsigned short a:13,flag:1,b:2;};struct Flag21{unsigned a:21,flag:1,b:10;};extern "C"{void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);int FindThirtySixByteRecordByWordKey(void*,int);void* GameState_GetObjectWithFlag100(GameState*,int);void* ReadWordFieldAtOffset150(void*);int CountEightPositiveHalfwordSlots(void*);int TestResolvedBitInByteField100C(void*,int);int ReadElement0At021015A0();char* GetRecordAtResolvedIndexWithStride116(void*,int);char* Object_GetBoundedTwentyFourByteEntry(void*,int);extern char data_02110370[];extern char* data_02108ed8[];extern unsigned data_020e7b70[];}
// Original: arm9/main @ 0x02021394; symbol: func_02021394; size: 0x68.
extern "C" int FindCoordinatePairByHalfwordAndByteKeys(char* p,unsigned a,unsigned b,short* x,short* y){for(int i=0;i<*(unsigned short*)(p+2720);++i){char* q=p+2722+i*8;if(*(unsigned short*)q==a&&(unsigned char)q[2]==b){*x=*(short*)(q+4);*y=*(short*)(q+6);return 1;}}return 0;}
