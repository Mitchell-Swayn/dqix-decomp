struct WirelessChannelState {
 unsigned short reserved0;
 volatile unsigned short selectedChannel;
 unsigned char reserved4[8];
 unsigned short channelMask;
 unsigned short reservedE;
 int state;
 unsigned char reserved14[12];
 unsigned int seed;
};
extern "C" WirelessChannelState data_021015a0;
// Original: arm9/main @ 0x0202D8E8; symbol: func_0202d8e8; size: 0xF8.
// Marks ready and chooses a 1-based channel from the mask, randomizing when several are set.
// Proposed descriptive name: Network_SelectRandomMaskedChannel.
extern "C" unsigned short Network_SelectRandomMaskedChannel()
{
 unsigned short mask; unsigned short count; short bit; short selected;
 data_021015a0.state=1;
 selected=0;count=0;mask=data_021015a0.channelMask;
 for(bit=0;bit<16;++bit) {
  if(mask&(1<<bit)) {selected=bit+1;count++;}
 }
 if(count>1) {
  unsigned int nextSeed=data_021015a0.seed*0x10dcd+0x3039;
  unsigned short rank=(unsigned short)((count*(nextSeed&255))>>8);
  data_021015a0.seed=nextSeed;
  for(bit=0;bit<16;++bit) {
   if(mask&1) {
    if(rank==0) { selected=bit+1;goto selected_channel; }
    rank--;
   }
   mask>>=1;
  }
  selected=0;
 }
selected_channel:
 data_021015a0.selectedChannel=selected;
 return data_021015a0.selectedChannel;
}
