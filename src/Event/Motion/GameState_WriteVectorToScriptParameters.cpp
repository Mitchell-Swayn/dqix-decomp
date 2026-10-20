#include <globaldefs.h>
ARM
struct GameState;
struct FixedVector { int x,y,z; };
extern "C" unsigned _fdiv(unsigned,unsigned);
extern "C" int _fflt(int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadUnknownB0(GameState*);
extern "C" void Script_WriteFloatReferenceOutput(unsigned*,unsigned);
// Original: arm9/ov001 @ 0x0215DB3C; symbol: func_ov001_0215db3c; size: 0x94.
extern "C" int GameState_WriteVectorToScriptParameters(char* args) {
char* obj=(char*)GameState_ReadUnknownB0((GameState*)_ZN9GameState11GetInstanceEv());
if(!obj) return 0;
FixedVector v=*(FixedVector*)(obj+0x70);
Script_WriteFloatReferenceOutput((unsigned*)args,_fdiv(_fflt(v.x),0x45800000));
Script_WriteFloatReferenceOutput((unsigned*)(args+8),_fdiv(_fflt(v.y),0x45800000));
Script_WriteFloatReferenceOutput((unsigned*)(args+16),_fdiv(_fflt(v.z),0x45800000));
return 1;
}
