#include <globaldefs.h>
ARM
#include <Resource/Script.h>
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char*,void*,unsigned*);
extern "C" char *data_ov016_0219d1bc;
extern "C" char data_ov016_0219d054[];
extern "C" char data_0211e33c[];
extern "C" Script::OpcodeLookupEntry data_ov016_0219d044[];
// Original: arm9/ov016 @ 0x0218E098; symbol: func_ov016_0218e098; size: 0x8C.
extern "C" void Script_LoadFileAndExecuteWithOwner(char *self, void *context) {
    *(void **)(self + 8) = context;
    data_ov016_0219d1bc = self;
    _ZN16BackgroundLoader13AddLockGlobalEv();
    unsigned length;
    void *code = _Z18LoadFileIntoMemoryPKcPvPj(data_ov016_0219d054, data_0211e33c, &length);
    if (code) {
        Script script;
        script.Initialize();
        script.SetOpcodeLookup(data_ov016_0219d044);
        script.Load(code, length);
        script.Execute();
    }
    _ZN16BackgroundLoader16RemoveLockGlobalEv();
    *(void **)(self + 8) = 0;
}
