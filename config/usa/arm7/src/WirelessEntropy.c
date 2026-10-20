/* Fold input bits into the shared halfword wireless entropy state. */
#pragma dont_inline on
#define ARM7_WirelessEntropyState (*(volatile unsigned short*)0x027fff98)
// Original: arm7/mainram @ 0x027E3910; symbol: ARM7_MixWirelessEntropy.
void ARM7_MixWirelessEntropy(unsigned int value) {
 volatile unsigned short *state=&ARM7_WirelessEntropyState;
 unsigned int previous=*state;
 value=(previous<<1)^value;
 value^=value>>16;
 *state=value;
}
