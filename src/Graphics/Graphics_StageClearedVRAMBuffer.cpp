// Cached exact ARM behavior, header-defined VRAM contracts and original relocation globals reviewed.
#include <globaldefs.h>
#include <Graphics/VRAMStaging.h>
#include <GameState/GameState.h>
#include <Resource/Script.h>
ARM
#pragma force_active on
struct Twelve{unsigned count:12,rest:20;};struct Bit13{unsigned short a:13,flag:1,b:2;};struct Flag21{unsigned a:21,flag:1,b:10;};extern "C"{void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);int FindThirtySixByteRecordByWordKey(void*,int);void* GameState_GetObjectWithFlag100(GameState*,int);void* ReadWordFieldAtOffset150(void*);int CountEightPositiveHalfwordSlots(void*);int TestResolvedBitInByteField100C(void*,int);int ReadElement0At021015A0();char* GetRecordAtResolvedIndexWithStride116(void*,int);char* Object_GetBoundedTwentyFourByteEntry(void*,int);extern char data_02110370[];extern char* data_02108ed8[];extern unsigned data_020e7b70[];}
// Original: arm9/main @ 0x0204394C; symbol: func_0204394c; size: 0x64.
extern "C" void Graphics_StageClearedVRAMBuffer(char* p){void* buffer=AllocateVRAMStagingMemory(0x3000);if(buffer){unsigned offset=((*(unsigned*)(p+80)<<16)>>13);memset(buffer,0,0x3000);StageMemoryToVRAM((VRAMSubregion)1,buffer,offset,0x3000,true,false);FreeVRAMStagingMemory(buffer);}}
