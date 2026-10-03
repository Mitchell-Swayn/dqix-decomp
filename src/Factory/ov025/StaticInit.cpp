// Floating-point aggregates initialized by the overlay startup routines.
extern "C" {
extern float data_ov025_021ef3c0[], data_ov025_021ef960[];
extern float data_ov025_021ef464[], data_ov025_021ef988[];
extern float data_ov025_021ef898[], data_ov025_021ef9c4[];
}
#pragma define_section init ".init" RX
extern "C" {
__declspec(section "init") void __sinit_ov025_021ef200()
{
    data_ov025_021ef960[4] = data_ov025_021ef3c0[1] + (data_ov025_021ef3c0[2] + (data_ov025_021ef3c0[0] + data_ov025_021ef3c0[3]));
    data_ov025_021ef960[2] = data_ov025_021ef960[3] + data_ov025_021ef3c0[0];
    data_ov025_021ef960[1] = data_ov025_021ef960[2] + data_ov025_021ef3c0[3];
    data_ov025_021ef960[0] = data_ov025_021ef960[1] + data_ov025_021ef3c0[2];
}
__declspec(section "init") void __sinit_ov025_021ef288()
{
    data_ov025_021ef988[0] = data_ov025_021ef464[1] + (data_ov025_021ef464[3] + (data_ov025_021ef464[2] + data_ov025_021ef464[4]));
    data_ov025_021ef988[6] = data_ov025_021ef988[5] + data_ov025_021ef464[2];
    data_ov025_021ef988[1] = data_ov025_021ef988[6] + data_ov025_021ef464[4];
    data_ov025_021ef988[4] = data_ov025_021ef988[1] + data_ov025_021ef464[3];
}
__declspec(section "init") void __sinit_ov025_021ef310()
{
    data_ov025_021ef9c4[3] = data_ov025_021ef898[4] + (data_ov025_021ef898[3] + (data_ov025_021ef898[6] + data_ov025_021ef898[5]));
    data_ov025_021ef9c4[2] = data_ov025_021ef9c4[1] + data_ov025_021ef898[6];
    data_ov025_021ef9c4[4] = data_ov025_021ef9c4[2] + data_ov025_021ef898[5];
    data_ov025_021ef9c4[0] = data_ov025_021ef9c4[4] + data_ov025_021ef898[3];
}
}
