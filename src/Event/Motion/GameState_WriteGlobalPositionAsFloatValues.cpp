#include <globaldefs.h>
ARM
struct GameState;
extern "C" unsigned _fdiv(unsigned,unsigned);
extern "C" int _fflt(int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadUnknownB0(GameState*);
extern "C" void Script_WriteFloatReferenceOutput(unsigned*,unsigned);
struct Vector { int x,y,z; };
// Original: arm9/ov001 @ 0x0215DAA8; symbol: func_ov001_0215daa8; size: 0x94.
extern "C" int GameState_WriteGlobalPositionAsFloatValues(unsigned* out) {
 char* source=(char*)GameState_ReadUnknownB0((GameState*)_ZN9GameState11GetInstanceEv());
 if(!source) return 0;
 Vector value=*(Vector*)(source+0x10);
 Script_WriteFloatReferenceOutput(out,_fdiv(_fflt(value.x),0x45800000));
 Script_WriteFloatReferenceOutput(out+2,_fdiv(_fflt(value.y),0x45800000));
 Script_WriteFloatReferenceOutput(out+4,_fdiv(_fflt(value.z),0x45800000));
 return 1;
}
