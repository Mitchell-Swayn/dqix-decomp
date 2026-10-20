/* Record one input byte in the shared 32-byte ring and fold its bits into
 * the shared entropy halfword. Storage belongs to existing system state. */
#pragma dont_inline on
typedef struct { unsigned char prefix[0x574]; volatile unsigned int index; } WirelessStatePrefix;
extern WirelessStatePrefix ARM7_WirelessState;
#define WIRELESS_STATE ARM7_WirelessState
extern volatile unsigned char ARM7_WirelessEntropyRing[32];
#define WIRELESS_ENTROPY_RING ARM7_WirelessEntropyRing
#define WIRELESS_ENTROPY_STATE (*(volatile unsigned short*)0x027fff98)
// Original: arm7/mainram @ 0x027E0520; symbol: ARM7_RecordWirelessEntropy.
void ARM7_RecordWirelessEntropy(unsigned int value) {
 WIRELESS_ENTROPY_RING[WIRELESS_STATE.index]=value;
 WIRELESS_STATE.index=(WIRELESS_STATE.index+1)&31;
 value^=WIRELESS_ENTROPY_STATE<<1;
 value^=value>>16;
 WIRELESS_ENTROPY_STATE=value;
}
