#pragma thumb off
#pragma always_inline on
int fix32ReduceAngle0To2Pi(int);
struct Position{int x,y,z;inline Position(int a,int b,int c):x(a),y(b),z(c){};};
// Original: arm9/main @ 0x02033874; symbol: func_02033874; size: 0x3C.
extern "C" void Object3D_SetNormalizedAngleAndUpdatePosition(char* object,int value){*(short*)(object+0xae)=fix32ReduceAngle0To2Pi(value);Position p(*(int*)(object+0x50),*(short*)(object+0xae),*(int*)(object+0x58));*(Position*)(object+0x50)=p;*(unsigned short*)(object+0xc4)&=~0x8000;}
