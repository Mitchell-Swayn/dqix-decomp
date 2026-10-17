#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *);
extern "C" void WriteByteAtOffset63D6(int, unsigned char);
// Original: arm9/ov001 @ 0x021618D0; symbol: func_ov001_021618d0; size: 0x30.
extern "C" int GameState_SetByteAtOffset63D6FromScript(IntegerParameterView *parameter) {
    void *gameState = _ZN9GameState11GetInstanceEv();
    WriteByteAtOffset63D6((int)gameState, (unsigned char)ReadScriptParameterAsInteger(parameter));
    return 1;
}
