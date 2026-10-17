struct State {
    unsigned a,b;
};
extern "C" State data_ov031_0224e5a4;
// Original: arm9/ov031 @ 0x02211B08; symbol: func_ov031_02211b08; size: 0x18.
extern "C" void SetSharedWordPairUnlessStateNine(unsigned a,unsigned b) {
    if(data_ov031_0224e5a4.a!=9) {
        data_ov031_0224e5a4.a=a;
        data_ov031_0224e5a4.b=b;
    }
}
