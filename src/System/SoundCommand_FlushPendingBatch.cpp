#include <globaldefs.h>
#include <System/Interrupts.h>
#include <System/Cache.h>
#include <System/IPC.h>
ARM

struct SNDCommand;

// Original data: arm9/main @ 0x02112780; symbol: SNDPushCommand_UnknownRoleZeroInitializedStorage.
// NitroSDK sound command list state (free list, reserved list, waiting-queue indices and tags).
struct SoundCommandListState {
    SNDCommand* freeList;
    SNDCommand* freeListEnd;
    SNDCommand* reserveList;
    SNDCommand* reserveListEnd;
    int unknown10;
    int waitingQueueRead;
    int waitingQueueWrite;
    int waitingCount;
    unsigned int currentTag;
};

extern "C" {
extern SoundCommandListState SNDPushCommand_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x021127A4: waiting command list queue (9 entries).
extern SNDCommand* SoundCommandFlushPendingBatch_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x02112A60: 256-record sound command pool (0x1800 bytes).
extern SNDCommand SoundCommandFlushPendingBatch_UnknownRoleZeroInitializedStorage_Variant2[];
int SoundCommand_ReclaimCompletedBatch(int);
void IPC_SendARM7CommandSevenUntilAccepted();
}

// Original: arm9/main @ 0x020D24C4; symbol: SoundCommand_FlushPendingBatch; size: 0x1BC.
// NitroSDK SND_FlushCommand: sends the reserved command list to the ARM7 over the sound FIFO,
// waiting for queue space when flag 1 (block) is set; flag 2 requests immediate processing.
extern "C" int SoundCommand_FlushPendingBatch(unsigned int flags)
{
    int enabled = DisableIRQInterrupts();
    if (SNDPushCommand_UnknownRoleZeroInitializedStorage.reserveList == 0) {
        SetIRQInterruptState(enabled);
        return 1;
    }
    if (SNDPushCommand_UnknownRoleZeroInitializedStorage.waitingCount >= 8) {
        if ((flags & 1) == 0) {
            SetIRQInterruptState(enabled);
            return 0;
        }
        do {
            SoundCommand_ReclaimCompletedBatch(1);
        } while (SNDPushCommand_UnknownRoleZeroInitializedStorage.waitingCount >= 8);
        if (SNDPushCommand_UnknownRoleZeroInitializedStorage.reserveList == 0) {
            SetIRQInterruptState(enabled);
            return 1;
        }
    }
    CleanInvalidateCacheRange(SoundCommandFlushPendingBatch_UnknownRoleZeroInitializedStorage_Variant2, 0x1800);
    if (SendCommandToArm7(7, (int)SNDPushCommand_UnknownRoleZeroInitializedStorage.reserveList, false) < 0) {
        if ((flags & 1) == 0) {
            SetIRQInterruptState(enabled);
            return 0;
        }
        while (SNDPushCommand_UnknownRoleZeroInitializedStorage.waitingCount >= 8
               || SendCommandToArm7(7, (int)SNDPushCommand_UnknownRoleZeroInitializedStorage.reserveList, false) < 0) {
            SetIRQInterruptState(enabled);
            SoundCommand_ReclaimCompletedBatch(0);
            enabled = DisableIRQInterrupts();
            CleanInvalidateCacheRange(SoundCommandFlushPendingBatch_UnknownRoleZeroInitializedStorage_Variant2, 0x1800);
            if (SNDPushCommand_UnknownRoleZeroInitializedStorage.reserveList == 0) {
                SetIRQInterruptState(enabled);
                return 1;
            }
        }
    }
    SoundCommandFlushPendingBatch_UnknownRoleZeroInitializedStorage[SNDPushCommand_UnknownRoleZeroInitializedStorage.waitingQueueWrite] =
        SNDPushCommand_UnknownRoleZeroInitializedStorage.reserveList;
    SNDPushCommand_UnknownRoleZeroInitializedStorage.waitingQueueWrite++;
    if (SNDPushCommand_UnknownRoleZeroInitializedStorage.waitingQueueWrite > 8)
        SNDPushCommand_UnknownRoleZeroInitializedStorage.waitingQueueWrite = 0;
    SNDPushCommand_UnknownRoleZeroInitializedStorage.reserveList = 0;
    SNDPushCommand_UnknownRoleZeroInitializedStorage.reserveListEnd = 0;
    SNDPushCommand_UnknownRoleZeroInitializedStorage.waitingCount++;
    SNDPushCommand_UnknownRoleZeroInitializedStorage.currentTag++;
    SetIRQInterruptState(enabled);
    if (flags & 2)
        IPC_SendARM7CommandSevenUntilAccepted();
    return 1;
}
