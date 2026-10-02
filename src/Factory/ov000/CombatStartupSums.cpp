// Startup partial sums of the overlay's floating-point configuration tables.
// Table semantics remain unresolved; definitions belong to separate data ranges.
extern float data_ov000_021838c8[];
extern float data_ov000_021838e8[];
extern float data_ov000_02183b0c[];
extern float data_ov000_02184220[];
extern float data_ov000_0218423c[];
extern float data_ov000_02184250[];

#pragma define_section init ".init" RX
extern "C" __declspec(section "init") void __sinit_ov000_02183710()
{
    data_ov000_02184220[6] = data_ov000_021838c8[2] + (data_ov000_021838c8[3] + (data_ov000_021838c8[0] + data_ov000_021838c8[1]));
    data_ov000_02184220[4] = data_ov000_02184220[5] + data_ov000_021838c8[0];
    data_ov000_02184220[3] = data_ov000_02184220[4] + data_ov000_021838c8[1];
    data_ov000_02184220[2] = data_ov000_02184220[3] + data_ov000_021838c8[3];
}

extern "C" __declspec(section "init") void __sinit_ov000_02183794()
{
    data_ov000_0218423c[4] = data_ov000_021838e8[1] + (data_ov000_021838e8[0] + (data_ov000_021838e8[3] + data_ov000_021838e8[2]));
    data_ov000_0218423c[3] = data_ov000_0218423c[0] + data_ov000_021838e8[3];
    data_ov000_0218423c[2] = data_ov000_0218423c[3] + data_ov000_021838e8[2];
    data_ov000_0218423c[1] = data_ov000_0218423c[2] + data_ov000_021838e8[0];
}

extern "C" __declspec(section "init") void __sinit_ov000_0218381c()
{
    data_ov000_02184250[4] = data_ov000_02183b0c[1] + (data_ov000_02183b0c[2] + (data_ov000_02183b0c[4] + data_ov000_02183b0c[3]));
    data_ov000_02184250[2] = data_ov000_02184250[3] + data_ov000_02183b0c[4];
    data_ov000_02184250[1] = data_ov000_02184250[2] + data_ov000_02183b0c[3];
    data_ov000_02184250[0] = data_ov000_02184250[1] + data_ov000_02183b0c[2];
}
