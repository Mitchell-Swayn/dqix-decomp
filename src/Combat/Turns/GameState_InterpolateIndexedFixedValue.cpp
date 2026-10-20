#include <globaldefs.h>
ARM
struct GameState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* GameState_FindIndexedObjectWithFlag400(GameState*,unsigned);
inline int MultiplyFixed(int a,int b) {return (int)(((long long)a*b+0x800)>>12);}
// Original: arm9/ov000 @ 0x0216352C; symbol: func_ov000_0216352c; size: 0xB8.
extern "C" int GameState_InterpolateIndexedFixedValue(int index,float threshold,float factor) {
GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
bool valid;
if(index>=0xc0 && index<=0xc7) valid=true;else valid=false;
if(!valid || !state) return 266;
unsigned char* object=GameState_FindIndexedObjectWithFlag400(state,index);
if(!object) return 266;
int value=*(short*)(object+0x18e);
int lower=(int)(4096.0f*threshold);
if(value<=lower) return value;
int scale=(int)(4096.0f*factor);
return (short)(lower+MultiplyFixed(value-lower,scale));
}
