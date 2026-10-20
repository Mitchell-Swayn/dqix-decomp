#include <globaldefs.h>
extern "C" int ResourceManager_StartResolvedKeyEntry(void*);extern "C" void NNS_SndArcStrmStartPrepared(void*);
// Original: arm9/main @ 0x020BEC30; symbol: func_020bec30; size: 0x28.
extern "C" int NNS_SndArcStrmStart(void* self) {if(!ResourceManager_StartResolvedKeyEntry(self))return 0;NNS_SndArcStrmStartPrepared(self);return 1;}
