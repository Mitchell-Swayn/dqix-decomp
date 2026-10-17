// Cached original field widths and exact relocation-backed calls/globals reviewed.
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/Script.h>
#include <System/Matrix.h>
#include <Graphics/VRAMStaging.h>
ARM
#pragma force_active on
struct Triple{int x,y,z;};struct Matrix{unsigned v[12];};struct Transform{Triple a,b,c;Matrix d;};struct Bits{unsigned char a:1,b:7;};struct Packed{unsigned a:10,b:10,c:12;};struct Link{char pad[6];unsigned char kind,rest;unsigned a,b;Link* same;Link* next;};extern "C"{void func_0200f374(void*,unsigned);void InitializeFourWordsWithInvalidIndex(void*);void* GameState_GetObjectWithFlag100(GameState*,int);extern short data_02109950[8][2],data_02109a30[8][2],data_020ee7c8[],data_020ee798[];extern Link* data_02108844[];}
// Original: arm9/main @ 0x020DE1D4; symbol: func_020de1d4; size: 0x60.
extern "C" void InitializePacked999FieldsAndInvalidIndex(char* p){*(int*)p=0;*(int*)(p+4)=0;*(int*)(p+8)=0;*(int*)(p+12)=0;*(short*)(p+20)=0;*(short*)(p+22)=0;*(short*)(p+24)=-1;*(short*)(p+26)=0;*(short*)(p+28)=0;((Packed*)(p+16))->a=999;((Packed*)(p+16))->b=999;}
