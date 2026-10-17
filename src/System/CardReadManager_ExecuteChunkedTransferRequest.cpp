#include <globaldefs.h>
#include <System/Cache.h>
#include <System/Interrupts.h>
#include <System/Memory.h>
#include <System/ProcessorContext.h>

extern "C" {
void OSi_ReferSymbol(const void*);
unsigned int ReadElement7();
int CardReadManager_SendSharedCommandWithRetries(void*, int, unsigned int);
extern unsigned char* data_021118e0;
}

// Original: arm9/main @ 0x020D03FC; symbol: func_020d03fc; size: 0x1F0.
extern "C" ARM void CardReadManager_ExecuteChunkedTransferRequest(unsigned int* request)
{
    unsigned int direction = request[0xd];
    unsigned int maxTransfer = 0x100;
    unsigned int* dma;
    unsigned int channel = request[0xb];
    unsigned int mode = request[0xc];
    OSi_ReferSymbol((const void*)0x02000bc4);
    if (channel == 0xb) maxTransfer = ReadElement7();
    else if (channel == 0xf) maxTransfer = *(unsigned int*)(data_021118e0 + 0x20);

    dma = request + 0x48;
    do {
        unsigned int length = request[9];
        if (maxTransfer < length) length = maxTransfer;
        *(unsigned int*)(request[0] + 0x14) = length;
        volatile unsigned int* flags = request + 0x45;
        if ((*flags & 0x40) != 0) {
            *flags &= ~0x40u;
            *(unsigned int*)request[0] = 7;
            break;
        }

        switch (direction) {
        case 0:
            InvalidateDataCacheRange(dma, length);
            *(unsigned int*)(request[0] + 0x0c) = request[7];
            *(unsigned int*)(request[0] + 0x10) = (unsigned int)dma;
            break;
        case 1:
        case 2:
            MI_CpuCopy8((const void*)request[7], dma, length);
            CleanInvalidateCacheRange(dma, length);
            DrainWriteBuffer();
            *(unsigned int*)(request[0] + 0x0c) = (unsigned int)dma;
            *(unsigned int*)(request[0] + 0x10) = request[8];
            break;
        case 3:
            *(unsigned int*)(request[0] + 0x0c) = request[7];
            *(unsigned int*)(request[0] + 0x10) = request[8];
            break;
        }

        if (!CardReadManager_SendSharedCommandWithRetries(request, (int)channel, mode)) break;
        if (direction == 2) {
            if (!CardReadManager_SendSharedCommandWithRetries(request, 9, 1)) break;
        } else if (direction == 0) {
            MI_CpuCopy8(dma, (void*)request[8], length);
        }
        request[7] += length;
        request[8] += length;
        request[9] -= length;
    } while (request[9] != 0);

    int irqState;
    int callbackArg;
    void (*callback)(int) = (void (*)(int))request[0xe];
    callbackArg = (int)request[0xf];
    irqState = DisableIRQInterrupts();
    request[0x45] &= ~0x4cu;
    UnblockContexts((BlockedContextList*)(request + 0x43));
    if ((request[0x45] & 0x10) != 0)
        MarkContextReadyAndSwitch((ProcessorContext*)(request + 0x11));
    SetIRQInterruptState(irqState);
    if (callback != 0) callback(callbackArg);
}
