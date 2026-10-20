#pragma once

typedef void(*DMACompletionCallback)(int userdata);

struct DMARegisterSet
{
    unsigned int sourceAddr;
    unsigned int destAddr;
    union {
        unsigned int u32;
        struct {
            unsigned short transferSize;
            unsigned short control;
        };
    } controlAndSize;
};

#if defined(jpn)
#define LoadToSubOAM_UnknownRoleInitializedBytes data_020f23dc
#endif

// DMA channel for general use
// Original data: arm9/main @ 0x20f2270; symbol: data_020f2270.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 03000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern int LoadToSubOAM_UnknownRoleInitializedBytes;

// ITCM functions. The atomic operations are wrapped with DisableIRQInterrupts()
// and SetIRQInterruptState(), 
void ConfigureDMATransferAtomic(int channel, unsigned src, unsigned dst, unsigned ctrl);
void ConfigureDMATransferSafeAtomic(int channel, unsigned src, unsigned dst, unsigned ctrl);
void ConfigureDMATransfer(int channel, unsigned src, unsigned dst, unsigned ctrl);
void ConfigureDMATransferSafe(int channel, unsigned src, unsigned dst, unsigned ctrl);

void DMAMemsetSynchronous(int channel, unsigned int dst, unsigned int value, unsigned int len);
void DMAMemcpySynchronous(int channel, unsigned int src, unsigned int dst, unsigned int len);
void DMAMemcpySynchronous16Bit(int channel, unsigned int src, unsigned int dst, unsigned int len);

// Because immediate mode DMA transfers block the CPU until done, this isn't
// actually async, just set up to look like it
void DMAMemsetAsync(int channel, unsigned int dst, unsigned int value, unsigned int len,
    DMACompletionCallback onCompletion, int callbackUserdata);
void DMAMemcpyAsync(int channel, unsigned int src, unsigned int dst, unsigned int len,
    DMACompletionCallback onCompletion, int callbackUserdata);

void AwaitDMACompletion(int channel);
void ResetDMAChannel(int channel);
void ResetAllDMAChannels();

void VerifyOtherDMATimingCompatibility(int channel, unsigned int newTimingFlags);
void VerifyDMASource(int channel, unsigned int source, unsigned int length, unsigned int sourceCtrlFlags);
