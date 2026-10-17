// Exact original field widths and relocation-linked data/callee contracts reviewed; no wrapper addresses.
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Matrix.h>
ARM
#pragma force_active on
struct F14{unsigned a:14,flag:1,b:17;};struct F17{unsigned a:17,flag:1,b:14;};struct F21{unsigned a:21,flag:1,b:10;};struct Signed3{unsigned a:6;signed value:3;unsigned b:23;};typedef int(*Reader)(void**);extern "C" {extern signed char data_020e8b48[],data_020e8b7e[],data_020e8b36[];unsigned GameState_ReadUnknownB0(GameState*);void func_02040c2c(void*,unsigned,unsigned,unsigned);unsigned GameState_CopyField571DBufferToDestination(GameState*,void*);void ClearField14Flag1000AndField58Flag1C0AndBytes70And93(void*);void* ReadWordFieldAtOffset150(void*);int GameState_ReadAttributeBits12To19(GameState*,int);}void Vector3fixDivideScalar(const Vector3fix*,int,Vector3fix*);
// Original: arm9/main @ 0x020DCC20; symbol: func_020dcc20; size: 0x78.
extern "C" int Party_TestCountOfMembersWithZoneState(unsigned target,int exclude){GameState* state=GameState::GetInstance();unsigned char count=0;for(signed char i=0;i<4;++i){char* q=(char*)state->GetPartyMemberByIndex(i);if(q){if(exclude&&*(unsigned*)(q+452))continue;if(ReadWordFieldAtOffset150(q))++count;}}return count==target;}
