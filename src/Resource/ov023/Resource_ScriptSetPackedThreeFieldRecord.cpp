#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
struct Packed { char pad[0xf4]; unsigned field0 : 12; unsigned field1 : 4; unsigned field2 : 5; unsigned rest : 11; };
struct Context { unsigned char a,b,enabled,c; unsigned words[2]; Packed *record; };
extern "C" Context data_ov023_021fff08;
// Original: arm9/ov023 @ 0x021F55E8; symbol: func_ov023_021f55e8; size: 0x98.
extern "C" int Resource_ScriptSetPackedThreeFieldRecord(char *params) {
    if (!data_ov023_021fff08.enabled) return 1;
    data_ov023_021fff08.record->field0 = _ZNK6Script9Parameter5ToIntEv(params);
    data_ov023_021fff08.record->field1 = _ZNK6Script9Parameter5ToIntEv(params + 8);
    data_ov023_021fff08.record->field2 = _ZNK6Script9Parameter5ToIntEv(params + 16);
    return 1;
}
