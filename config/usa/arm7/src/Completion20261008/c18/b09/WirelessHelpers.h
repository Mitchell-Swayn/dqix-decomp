#ifndef ARM7_C18_WIRELESS_HELPERS_H
#define ARM7_C18_WIRELESS_HELPERS_H
/* Views of original wireless-owned storage; this header allocates no storage. */
typedef struct WirelessReceiveSlot { unsigned int flags; unsigned char data[12]; } WirelessReceiveSlot;
typedef struct WirelessReceiveContext {
 unsigned char prefix[0x53]; unsigned char signalMode;
 unsigned char padding[0x7c]; WirelessReceiveSlot slots[32];
} WirelessReceiveContext;
typedef struct WirelessBufferControl {
 unsigned char prefix[0x30];
 unsigned short limitA,limitB,shadowA,shadowB,endA,endB,shadowEndA,shadowEndB;
 unsigned char padding[0x148]; unsigned short bank;
} WirelessBufferControl;
typedef struct WirelessStateView {
 unsigned char prefix[0x54c];
 WirelessReceiveContext *receive;
 volatile WirelessBufferControl *buffer;
 unsigned char samples[32]; volatile unsigned int sampleIndex;
} WirelessStateView;
typedef struct WirelessRootView {
 unsigned char prefix[0x1000]; WirelessStateView state;
} WirelessRootView;
extern WirelessRootView ARM7_WirelessRoot;
extern WirelessStateView ARM7_WirelessState;
extern unsigned char ARM7_WirelessSamples[32];
extern unsigned short ARM7_WirelessSampleChecksum;
extern int ARM7_DisableInterrupts(void);
extern void ARM7_RestoreInterrupts(int previous);
extern unsigned int ARM7_WirelessSignalClassify(unsigned int sample);
#endif
