// Cached exact ARM behavior, header-defined VRAM contracts and original relocation globals reviewed.
#include <globaldefs.h>
#include <Graphics/VRAMStaging.h>
#include <GameState/GameState.h>
#include <Resource/Script.h>
ARM
#pragma force_active on
struct Twelve{unsigned count:12,rest:20;};struct Bit13{unsigned short a:13,flag:1,b:2;};struct Flag21{unsigned a:21,flag:1,b:10;};extern "C"{void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);int FindThirtySixByteRecordByWordKey(void*,int);void* GameState_GetObjectWithFlag100(GameState*,int);void* ReadWordFieldAtOffset150(void*);int CountEightPositiveHalfwordSlots(void*);int TestResolvedBitInByteField100C(void*,int);int ReadElement0At021015A0();char* GetRecordAtResolvedIndexWithStride116(void*,int);char* Object_GetBoundedTwentyFourByteEntry(void*,int);extern char data_02110370[];extern char* data_02108ed8[];extern unsigned data_020e7b70[];}
// Original: arm9/main @ 0x0207218C; symbol: func_0207218c; size: 0x6C.
extern "C" char* FindFlaggedRecordWithSmallestValueAboveThreshold(char* p,int threshold){unsigned short count=*(unsigned short*)(p+10);char* data=*(char**)(p+4);char* out=0;short best=32767;for(unsigned short i=0;i<count;++i){char* q=data+i*32;if(((Flag21*)(q+16))->flag){short n=*(short*)(q+24);if(n>threshold&&best>n&&*(short*)(q+22)<=0){best=n;out=q;}}}return out;}
