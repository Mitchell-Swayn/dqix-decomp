/* Sound IPC transport initialization and interrupt-protected command receipt. */
#pragma dont_inline on
#include "SoundSequence.h"
typedef struct { void *first,*last; } SoundBlockedList;
typedef struct SoundMessageQueue { SoundBlockedList sendWaiters,receiveWaiters; void **messages; int capacity,head,count; } SoundMessageQueue;
typedef struct { SoundMessageQueue queue; void *messages[8]; } SoundCommandState;
typedef char SoundCommandStateSizeCheck[sizeof(SoundCommandState)==64?1:-1];
SoundCommandState ARM7_SoundCommandState;
extern SoundMessageQueue ARM7_SoundCommandQueue;
extern void *ARM7_SoundCommandMessages[8];
extern SoundSharedWork *ARM7_SoundSharedWork;
extern void ARM7_InitializeMessageQueue(SoundMessageQueue*,void**,int);
extern void ARM7_SetIpcHandler(int,void(*)(int,unsigned int,int));
void ARM7_SoundCommandIpcCallback(int,unsigned int,int);
void ARM7_InitializeSoundCommandQueue(void)
{
 ARM7_InitializeMessageQueue(&ARM7_SoundCommandQueue,ARM7_SoundCommandMessages,8);
 ARM7_SetIpcHandler(7,ARM7_SoundCommandIpcCallback);
 ARM7_SoundSharedWork=0;
}
