#include <globaldefs.h>
extern "C" void MIi_CpuClear32(int, void *, int);
extern "C" void Network_SendAlignedBufferRequest(int, int, int, int, unsigned short, void *);

// Original: arm9/main @ 0x020D5898; symbol: func_020d5898; size: 0x68.
extern "C" void BuildModeThreeHalfwordPairAndDispatchRequest(int first, int second, int third, int fourth,
                               unsigned short fifth, unsigned short sixth) {
    struct Local {
        int word;
        unsigned short firstShort;
        unsigned short secondShort;
        int padding[2];
    } local;
    MIi_CpuClear32(0, &local, 0x10);
    local.word = 3;
    local.firstShort = sixth;
    local.secondShort = sixth;
    Network_SendAlignedBufferRequest(first, second, third, fourth, fifth, &local);
}
