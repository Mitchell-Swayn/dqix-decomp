// Dimensions are computed from the overlay's original floating-point configuration.
#pragma define_section init ".init" RX
extern "C" {
extern float data_ov014_021895a0[4];
extern float data_ov014_02189800[7];
// Original: arm9/ov014 @ 0x02189510; symbol: __sinit_ov014_02189510; size: 0x88.
__declspec(section "init") void __sinit_ov014_02189510() {
 data_ov014_02189800[6]=data_ov014_021895a0[0]+(data_ov014_021895a0[3]+(data_ov014_021895a0[2]+data_ov014_021895a0[1]));
 data_ov014_02189800[2]=data_ov014_02189800[5]+data_ov014_021895a0[2];
 float sum=data_ov014_02189800[2]+data_ov014_021895a0[1];
 float right=data_ov014_021895a0[3];
 data_ov014_02189800[4]=sum;
 data_ov014_02189800[0]=sum+right;
}
}
