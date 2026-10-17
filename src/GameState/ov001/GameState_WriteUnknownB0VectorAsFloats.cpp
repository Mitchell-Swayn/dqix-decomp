#include <globaldefs.h>
ARM
struct Vector { int x,y,z; };
extern "C" { unsigned _fdiv(unsigned,unsigned); int _fflt(int); void* _ZN9GameState11GetInstanceEv(); unsigned char* GameState_ReadUnknownB0(void*); void SetKindThreeIndirectWord4(unsigned*,unsigned); }
// Original: arm9/ov001 @ 0x0215DA14; symbol: func_ov001_0215da14; size: 0x94.
extern "C" int GameState_WriteUnknownB0VectorAsFloats(unsigned* output) {
 unsigned char* object=GameState_ReadUnknownB0(_ZN9GameState11GetInstanceEv());
 if(!object) return 0;
 Vector vector=*(Vector*)(object+4);
 SetKindThreeIndirectWord4(output,_fdiv(_fflt(vector.x),0x45800000));
 SetKindThreeIndirectWord4(output+2,_fdiv(_fflt(vector.y),0x45800000));
 SetKindThreeIndirectWord4(output+4,_fdiv(_fflt(vector.z),0x45800000));
 return 1;
}
