#pragma thumb off
#pragma define_section init ".init" RX
extern "C" float data_020efe5c[4];
extern "C" float data_021077e8[5];
// Initializes total and reverse cumulative sums; slot3 is the existing starting value.
// The next coefficient is read before storing slot2, matching the original access order.
// Original: arm9/main @ 0x020E5CFC; symbol: __sinit_020e5cfc; size: 0x88.
extern "C" __declspec(section "init") void InitializeCumulativeFloatValues(void)
{
 data_021077e8[4]=data_020efe5c[0]+(data_020efe5c[1]+(data_020efe5c[3]+data_020efe5c[2]));
 float value=data_021077e8[3]+data_020efe5c[3];
 float coefficient=data_020efe5c[2];
 data_021077e8[2]=value;
 value+=coefficient;
 data_021077e8[1]=value;
 value+=data_020efe5c[1];
 data_021077e8[0]=value;
}
