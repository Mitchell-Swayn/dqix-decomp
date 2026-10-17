#include <globaldefs.h>
ARM
struct Script { unsigned char storage[0x430]; };
struct ScriptOpcodeLookupEntry;
struct ScriptGlobals { short first; unsigned short pad; unsigned int second; unsigned int third; unsigned int fourth; };
extern "C" volatile struct ScriptGlobals data_ov023_021ffa34;
extern "C" unsigned char data_ov023_021fdc78[];
extern "C" void _ZN6Script10InitializeEv(Script *);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(Script *, ScriptOpcodeLookupEntry *);
extern "C" void _ZN6Script4LoadEPKvj(Script *, const void *, unsigned int);
extern "C" void _ZN6Script7ExecuteEv(Script *);
// Original: arm9/ov023 @ 0x021E133C; symbol: func_ov023_021e133c; size: 0x74.
extern "C" void Script_ExecuteConfiguredBuffer(unsigned int global0, unsigned int global1, const void *program, unsigned int length, unsigned int global4, short global0short) {
    if (program == 0 || length == 0) return;
    data_ov023_021ffa34.fourth = global0;
    data_ov023_021ffa34.third = global1;
    data_ov023_021ffa34.second = global4;
    data_ov023_021ffa34.first = global0short;
    Script script;
    _ZN6Script10InitializeEv(&script);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(&script, (ScriptOpcodeLookupEntry *)data_ov023_021fdc78);
    _ZN6Script4LoadEPKvj(&script, program, length);
    _ZN6Script7ExecuteEv(&script);
}
