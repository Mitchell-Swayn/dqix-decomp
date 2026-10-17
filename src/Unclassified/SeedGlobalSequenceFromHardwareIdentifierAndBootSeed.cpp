#include <globaldefs.h>

#pragma opt_lifetimes off
#pragma opt_propagation off
struct State { unsigned char pad0[2]; unsigned short value2; unsigned char pad4[2]; unsigned short sequence; unsigned char pad8[8]; int status; unsigned char pad14[12]; unsigned seed; };
extern "C" State data_021015a0;
extern "C" { void System_ReadHardwareMacAddress(unsigned short*); unsigned short Network_SelectAvailableChannelAndStartRequest(unsigned short); void SetGlobalValueExceptModesNineAndTen(unsigned); }
// Original: arm9/main @ 0x0202D6C8; symbol: func_0202d6c8; size: 0xC0.
extern "C" ARM int SeedGlobalSequenceFromHardwareIdentifierAndBootSeed() {
    unsigned short id[3];
    System_ReadHardwareMacAddress(id);
    int seed = *(int*)0x027ffc3c;
    unsigned sum = (unsigned)(id[0] + seed + id[1] + id[2]);
    data_021015a0.seed = sum * 0x10dcd + 0x3039;
    data_021015a0.value2 = 0;
    data_021015a0.sequence = 101;
    data_021015a0.status = 3;
    int result = Network_SelectAvailableChannelAndStartRequest(1);
    if (result == 24) { SetGlobalValueExceptModesNineAndTen(24); data_021015a0.status = 9; return 0; }
    if (result == 2) return 1;
    SetGlobalValueExceptModesNineAndTen(result); data_021015a0.status = 9; return 0;
}
