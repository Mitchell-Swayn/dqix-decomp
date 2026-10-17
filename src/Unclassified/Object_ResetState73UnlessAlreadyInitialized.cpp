// Cached original field widths and exact relocation-backed calls/globals reviewed.
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/Script.h>
#include <System/Matrix.h>
#include <Graphics/VRAMStaging.h>
ARM
#pragma force_active on
struct Triple{int x,y,z;};struct Matrix{unsigned v[12];};struct Transform{Triple a,b,c;Matrix d;};struct Bits{unsigned char a:1,b:7;};struct Packed{unsigned a:10,b:10,c:12;};struct Link{char pad[6];unsigned char kind,rest;unsigned a,b;Link* same;Link* next;};extern "C"{void func_0200f374(void*,unsigned);void InitializeFourWordsWithInvalidIndex(void*);void* GameState_GetObjectWithFlag100(GameState*,int);extern short data_02109950[8][2],data_02109a30[8][2],data_020ee7c8[],data_020ee798[];extern Link* data_02108844[];}
// Original: arm9/main @ 0x020D9DEC; symbol: func_020d9dec; size: 0x58.
extern "C" void Object_ResetState73UnlessAlreadyInitialized(char* p,int force){if(!force&&*(unsigned char*)(p+2))return;InitializeFourWordsWithInvalidIndex(p);p[0]=73;*(short*)(p+8)=0;p[10]=0;for(int i=0;i<1;++i)*(int*)(p+12+i*4)=-1;}
