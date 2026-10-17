#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov003_02180cb8;
extern "C" unsigned char data_ov003_0217ff40;
extern "C" void _ZN6Script10InitializeEv(void *);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void *, void *);
extern "C" void _ZN6Script4LoadEPKvj(void *, const void *, unsigned int);
extern "C" void _ZN6Script7ExecuteEv(void *);
// Original: arm9/ov003 @ 0x0215E6F8; symbol: func_ov003_0215e6f8; size: 0x58.
extern "C" void Script_ExecuteBufferWithLookup(void *globalA, void *globalB, const void *buffer, unsigned int size) {
    unsigned char script[0x430];
    *(void **)(&data_ov003_02180cb8 + 4) = globalA;
    *(void **)&data_ov003_02180cb8 = globalB;
    _ZN6Script10InitializeEv(script);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(script, &data_ov003_0217ff40);
    _ZN6Script4LoadEPKvj(script, buffer, size);
    _ZN6Script7ExecuteEv(script);
}
