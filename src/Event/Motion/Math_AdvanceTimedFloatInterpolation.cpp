#include <globaldefs.h>
ARM
extern "C" unsigned _fadd(unsigned,unsigned);
extern "C" unsigned _fdiv(unsigned,unsigned);
extern "C" int _ffix(unsigned);
extern "C" int _fflt(int);
// Original: arm9/ov001 @ 0x02159820; symbol: func_ov001_02159820; size: 0x9C.
extern "C" int Math_AdvanceTimedFloatInterpolation(unsigned char* settings,unsigned char* p){
 int duration=*(int*)(settings+0x14);
 if(*(int*)(p+0x64)>=duration){
 *(unsigned*)(p+0x8c)=_fflt(*(int*)(settings+0x10));
 *(int*)(p+0x64)=0;return 0;
 }
 if(*(int*)(p+0x64)<=0){
 int current=_ffix(*(unsigned*)(p+0x8c));
 int diff=*(int*)(settings+0x10)-current;
 if(!duration)return 0;
 unsigned numerator=_fflt(diff);
 *(unsigned*)(p+0x114)=_fdiv(numerator,_fflt(duration));
 }else{
 *(unsigned*)(p+0x8c)=_fadd(*(unsigned*)(p+0x8c),*(unsigned*)(p+0x114));
 }
 (*(int*)(p+0x64))++;
 return 1;
}
