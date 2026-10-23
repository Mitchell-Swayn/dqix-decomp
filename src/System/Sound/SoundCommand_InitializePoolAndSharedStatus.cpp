#include <globaldefs.h>
ARM
struct SNDCommand {SNDCommand* next;unsigned command;unsigned arguments[4];};
struct SoundReplyQueueState {SNDCommand* freeList;unsigned finishedTag;SNDCommand* reserveList;SNDCommand* reserveTail;SNDCommand* freeListEnd;int read,write,waitingCount;unsigned currentTag;};
struct SoundSharedSequenceStatus {short variables[16];unsigned ticks;};
struct SoundSharedStatusHeader {unsigned unknownWord0,activeSequences;unsigned short activeChannels,activeCaptures;unsigned char uninterpretedHeaderBytes[20];};
struct SoundDriverSharedStatus {SoundSharedStatusHeader header;SoundSharedSequenceStatus sequences[16];short globalVariables[16];};
extern "C" {
void RegisterCommandSevenAndWaitForArm7Handler();
void SoundCommand_InitializeSharedDriverStatus(char*);
unsigned SoundCommand_AllocateRecordWithOptionalWait(int);
void SND_PushCommand(SNDCommand*);
int SoundCommand_FlushPendingBatch(unsigned);
extern SoundReplyQueueState SNDPushCommand_UnknownRoleZeroInitializedStorage;
extern SNDCommand SoundCommandFlushPendingBatch_UnknownRoleZeroInitializedStorage_Variant2[];
struct PoolTailRegion {unsigned char pad[0xac8];SNDCommand* finalNext;};
extern PoolTailRegion SoundCommandInitializePoolAndSharedStatus_UnknownRoleZeroInitializedStorage_Variant2;
extern SNDCommand SoundCommandInitializePoolAndSharedStatus_UnknownRoleZeroInitializedStorage_Variant3;
extern SoundDriverSharedStatus SoundCommandInitializePoolAndSharedStatus_UnknownRoleZeroInitializedStorage;
extern unsigned* InvalidateAndReadSharedWord_UnknownRoleZeroInitializedStorage;
}
// SDK C source SND_CommandInit: ntrtwl/NitroSDK 9eec6c92c9d7bba9350732b11296ed16aab3a8bc libraries/snd/src/snd_command.c.
// Original: arm9/main @ 0x020D2220; symbol: func_020d2220; size: 0xD4.
extern "C" void SoundCommand_InitializePoolAndSharedStatus() {
 RegisterCommandSevenAndWaitForArm7Handler();
 SNDPushCommand_UnknownRoleZeroInitializedStorage.freeList=&SoundCommandFlushPendingBatch_UnknownRoleZeroInitializedStorage_Variant2[0];
 for(int i=0;i<255;++i)SoundCommandFlushPendingBatch_UnknownRoleZeroInitializedStorage_Variant2[i].next=&SoundCommandFlushPendingBatch_UnknownRoleZeroInitializedStorage_Variant2[i+1];
 // Existing aliases refer into the same 256-record command pool: +0xd20 and +0x17e8.
 // PoolTailRegion is a partial data view, not a separately allocated object.
 // Its finalNext field writes the last command next pointer: 0xd20+0xac8=255*24.
 SoundCommandInitializePoolAndSharedStatus_UnknownRoleZeroInitializedStorage_Variant2.finalNext=0;
 SNDPushCommand_UnknownRoleZeroInitializedStorage.freeListEnd=&SoundCommandInitializePoolAndSharedStatus_UnknownRoleZeroInitializedStorage_Variant3;
 SNDPushCommand_UnknownRoleZeroInitializedStorage.reserveList=0;
 SNDPushCommand_UnknownRoleZeroInitializedStorage.reserveTail=0;
 SNDPushCommand_UnknownRoleZeroInitializedStorage.waitingCount=0;
 SNDPushCommand_UnknownRoleZeroInitializedStorage.read=0;
 SNDPushCommand_UnknownRoleZeroInitializedStorage.write=0;
 SNDPushCommand_UnknownRoleZeroInitializedStorage.currentTag=1;
 SNDPushCommand_UnknownRoleZeroInitializedStorage.finishedTag=0;
 InvalidateAndReadSharedWord_UnknownRoleZeroInitializedStorage=(unsigned*)&SoundCommandInitializePoolAndSharedStatus_UnknownRoleZeroInitializedStorage;
 SoundCommand_InitializeSharedDriverStatus((char*)InvalidateAndReadSharedWord_UnknownRoleZeroInitializedStorage);
 SNDCommand* command=(SNDCommand*)SoundCommand_AllocateRecordWithOptionalWait(1);
 if(command){command->command=29;command->arguments[0]=(unsigned)InvalidateAndReadSharedWord_UnknownRoleZeroInitializedStorage;SND_PushCommand(command);SoundCommand_FlushPendingBatch(1);}
}
