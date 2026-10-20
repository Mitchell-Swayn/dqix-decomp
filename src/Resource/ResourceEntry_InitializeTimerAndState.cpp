#include <globaldefs.h>

extern "C" void NNSi_SndFaderInit(void *);
extern "C" void NNSi_SndFaderSet(void *, unsigned int, int);

// Original: arm9/main @ 0x020BC610; symbol: func_020bc610; size: 0x48.
extern "C" void ResourceEntry_InitializeTimerAndState(char *state) {
    state[0x2e]=0; state[0x2d]=0; state[0x2f]=0;
    *(unsigned short *)(state+0x34)=0;
    *(unsigned short *)(state+0x3e)=0;
    state[0x40]=0x7f; state[0x41]=0x7f;
    NNSi_SndFaderInit(state+0x1c);
    NNSi_SndFaderSet(state+0x1c,0x7f00,1);
}
