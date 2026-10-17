#include <globaldefs.h>
ARM
struct GameState;struct IntegerParameterView;struct FloatParameterView;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadUnknownB0(GameState*);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" float ReadScriptParameterAsFloat(FloatParameterView*);
// Original: arm9/ov001 @ 0x02161E00; symbol: func_ov001_02161e00; size: 0x8C.
extern "C" int GameState_SetScriptFloatAndFixedValues(char* args) {
char* p=(char*)GameState_ReadUnknownB0((GameState*)_ZN9GameState11GetInstanceEv());
int enabled=ReadScriptParameterAsInteger((IntegerParameterView*)args);
float a=ReadScriptParameterAsFloat((FloatParameterView*)(args+8));
float b=ReadScriptParameterAsFloat((FloatParameterView*)(args+16));
int fixed=(int)(4096.0f*b);
if(!p) return 0;
if(!enabled) p[0x1f8]=0;
else {
p[0x1f8]=1;
*(volatile float*)(p+0x200)=1.0f;
*(volatile int*)(p+0x204)=4096;
*(volatile float*)(p+0x200)=a;
*(volatile int*)(p+0x204)=fixed;
}
return 1;
}
