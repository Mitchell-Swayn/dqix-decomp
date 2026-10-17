#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_0224e528[];
extern "C" unsigned char data_ov031_0224e3b0;
extern "C" void InitializeSha1FiveWordDigestState(unsigned int *);
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" void func_ov031_0220b8f4(void *, const void *, unsigned);
extern "C" void func_ov031_0220b9ac(void *, const void *);
// Original: arm9/ov031 @ 0x02209E28; symbol: func_ov031_02209e28; size: 0x70.
extern "C" void Crypto_HashInputWithStaticSeed(const void *data, unsigned length) {
    unsigned int state[23];
    InitializeSha1FiveWordDigestState(state);
    int irq = _Z20DisableIRQInterruptsv();
    func_ov031_0220b8f4(state, data_ov031_0224e528, 0x14);
    func_ov031_0220b8f4(state, data, length);
    func_ov031_0220b9ac(state, data_ov031_0224e528);
    _Z20SetIRQInterruptStatei(irq);
    data_ov031_0224e3b0 = 1;
}
