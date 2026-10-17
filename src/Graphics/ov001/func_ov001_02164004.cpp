#include <globaldefs.h>
ARM
extern "C" float ReadScriptParameterAsFloat(void*);
extern "C" int ReadScriptParameterAsInteger(void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
extern "C" char* _ZN15LightingManager11GetInstanceEv();
extern "C" void _ZN15LightingManager9BeginFadeEst(void*, int, unsigned);
// Original: arm9/ov001 @ 0x02164004; symbol: func_ov001_02164004; size: 0x7C.
extern "C" int func_ov001_02164004(void* parameters, int count) {
    float amount = ReadScriptParameterAsFloat(parameters);
    int duration = 0;
    void* gameState = _ZN9GameState11GetInstanceEv();
    if (count >= 2)
        duration = ReadScriptParameterAsInteger((char*)parameters + 8);
    unsigned frames = (duration * _ZNK9GameState21GetEffectiveDeltaTimeEv(gameState)) & 0xffff;
    void* manager = _ZN15LightingManager11GetInstanceEv();
    int fade = (int)(amount * 4096.0f);
    _ZN15LightingManager9BeginFadeEst(manager, fade, frames);
    return 1;
}
