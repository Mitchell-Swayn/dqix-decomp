void SleepCurrentContext(unsigned);
extern "C" unsigned* data_ov031_0224e580;
// Original: arm9/ov031 @ 0x0220FEA0; symbol: func_ov031_0220fea0; size: 0x38.
extern "C" void WaitForSharedObjectWord2C() {
    while(data_ov031_0224e580 && !data_ov031_0224e580[11]) SleepCurrentContext(100);
}
