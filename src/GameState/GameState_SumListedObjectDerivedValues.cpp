// Cached exact ARM behavior, header-defined VRAM contracts and original relocation globals reviewed.
#include <globaldefs.h>
#include <Graphics/VRAMStaging.h>
#include <GameState/GameState.h>
#include <Resource/Script.h>
ARM
#pragma optimization_level 4
#pragma force_active on
struct Twelve{unsigned count:12,rest:20;};struct Bit13{unsigned short a:13,flag:1,b:2;};struct Flag21{unsigned a:21,flag:1,b:10;};extern "C"{void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);int FindThirtySixByteRecordByWordKey(void*,int);void* GameState_GetObjectWithFlag100(GameState*,int);void* ReadWordFieldAtOffset150(void*);int CountEightPositiveHalfwordSlots(void*);int TestResolvedBitInByteField100C(void*,int);int ReadElement0At021015A0();char* GetRecordAtResolvedIndexWithStride116(void*,int);char* Object_GetBoundedTwentyFourByteEntry(void*,int);extern char data_02110370[];extern char* data_02108ed8[];extern unsigned data_020e7b70[];}
// Original: arm9/main @ 0x02086D20; symbol: func_02086d20; size: 0x68.
extern "C" int GameState_SumListedObjectDerivedValues(unsigned char* p){short n=0;GameState* state=GameState::GetInstance();for(int i=0;i<p[3964];++i){void* q=GameState_GetObjectWithFlag100(state,p[3960+i]);if(q){q=ReadWordFieldAtOffset150(q);if(q)n+=CountEightPositiveHalfwordSlots(q);}}return n;}
