#include <globaldefs.h>
ARM
extern "C" void _ZN6Script10InitializeEv(void*);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void*, void*);
extern "C" void _ZN6Script4LoadEPKvj(void*, const void*, unsigned);
extern "C" void _ZN6Script7ExecuteEv(void*);
extern "C" unsigned data_ov017_021d83cc[];
extern "C" unsigned data_ov017_021d7900[];
// Original: arm9/ov017 @ 0x021ACC8C; symbol: func_ov017_021acc8c; size: 0x58.
extern "C" void Script_InitializeLoadAndExecute(void* context, const void* code, unsigned length, unsigned flags) {
    unsigned char script[0x430];
    data_ov017_021d83cc[0] = (unsigned)context;
    data_ov017_021d83cc[1] = flags;
    _ZN6Script10InitializeEv(script);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(script, data_ov017_021d7900);
    _ZN6Script4LoadEPKvj(script, code, length);
    _ZN6Script7ExecuteEv(script);
}
