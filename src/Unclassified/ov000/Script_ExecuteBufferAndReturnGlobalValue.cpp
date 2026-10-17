#include <globaldefs.h>
ARM
struct Script { unsigned char storage[0x430]; };
struct ScriptOpcodeLookupEntry;
extern "C" volatile unsigned int data_ov000_02184264[];
extern "C" unsigned char data_ov000_02183b5c[];
extern "C" void _ZN6Script10InitializeEv(Script *);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(Script *, ScriptOpcodeLookupEntry *);
extern "C" void _ZN6Script4LoadEPKvj(Script *, const void *, unsigned int);
extern "C" void _ZN6Script7ExecuteEv(Script *);
// Original: arm9/ov000 @ 0x0216D1C4; symbol: func_ov000_0216d1c4; size: 0x70.
extern "C" void Script_ExecuteBufferAndReturnGlobalValue(unsigned int globalValue, const void *program, unsigned int length, unsigned int *result) {
    Script script;
    data_ov000_02184264[2] = globalValue;
    data_ov000_02184264[1] = 0;
    data_ov000_02184264[0] = 0;
    _ZN6Script10InitializeEv(&script);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(&script, (ScriptOpcodeLookupEntry *)data_ov000_02183b5c);
    _ZN6Script4LoadEPKvj(&script, program, length);
    _ZN6Script7ExecuteEv(&script);
    *result = data_ov000_02184264[0];
}
