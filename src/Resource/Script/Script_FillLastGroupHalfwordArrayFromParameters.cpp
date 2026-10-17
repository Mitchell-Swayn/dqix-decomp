// Cached exact ARM behavior, header-defined VRAM contracts and original relocation globals reviewed.
#include <globaldefs.h>
#include <Graphics/VRAMStaging.h>
#include <GameState/GameState.h>
#include <Resource/Script.h>
ARM
#pragma force_active on
struct Twelve{unsigned count:12,rest:20;};struct Bit13{unsigned short a:13,flag:1,b:2;};struct Flag21{unsigned a:21,flag:1,b:10;};extern "C"{void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);int FindThirtySixByteRecordByWordKey(void*,int);void* GameState_GetObjectWithFlag100(GameState*,int);void* ReadWordFieldAtOffset150(void*);int CountEightPositiveHalfwordSlots(void*);int TestResolvedBitInByteField100C(void*,int);int ReadElement0At021015A0();char* GetRecordAtResolvedIndexWithStride116(void*,int);char* Object_GetBoundedTwentyFourByteEntry(void*,int);extern char data_02110370[];extern char* data_02108ed8[];extern unsigned data_020e7b70[];}
// Original: arm9/main @ 0x0207EE90; symbol: func_0207ee90; size: 0x68.
extern "C" int Script_FillLastGroupHalfwordArrayFromParameters(const Script::Parameter* p){char* list=data_02108ed8[1];char* q=Object_GetBoundedTwentyFourByteEntry(list,(short)(*(short*)(list+4)-1));short* out=*(short**)q;for(unsigned char i=0;i<(unsigned char)q[19];++i){out[i]=p->ToInt();++p;}return 1;}
