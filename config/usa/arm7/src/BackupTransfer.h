#ifndef ARM7_BACKUP_TRANSFER_H
#define ARM7_BACKUP_TRANSFER_H
#include "ThreadContext.h"

typedef struct {
 unsigned int remaining;
 const unsigned char *source;
 unsigned char *destination;
 int matched;
} BackupTransfer;
typedef struct {
 unsigned int statusInitialized;
 BackupTransfer transfer;
} BackupCommandState;
/* Request prefix through the per-operation delay values. */
typedef struct {
 int result;
 unsigned int unknown4[6];
 unsigned int sectorSize,subsectorSize;
 unsigned int pageSize,addressBytes;
 int writeDelay,programDelay,programTimeout;
 int chipEraseDelay,chipEraseTimeout;
 int sectorEraseDelay,sectorEraseTimeout;
 int subsectorEraseDelay,subsectorEraseTimeout;
 unsigned int unknown50;
 unsigned char initialStatus;
} BackupRequest;
typedef struct {
 BackupRequest *request;
 unsigned int command,receivedCount;
 int unknownC;
 unsigned int unknown10,unknown14,unknown18,unknown1C,unknown20[7];
 void (*callback)(void*);
 void *userData;
 unsigned int unknown44;
 ProcessorContext thread;
 ProcessorContext *waitingThread;
 unsigned int priority;
 BlockedContextList waiters;
 volatile unsigned int flags;
} BackupWorker;
typedef char BackupWorkerSizeCheck[sizeof(BackupWorker)==0x100?1:-1];
typedef char BackupTransferSizeCheck[sizeof(BackupTransfer)==16?1:-1];
extern BackupTransfer ARM7_BackupTransfer;
extern BackupCommandState ARM7_BackupCommandState;
extern BackupWorker ARM7_BackupWorker;
void ARM7_TransferBackupBytes(const unsigned char*,unsigned char*,unsigned int,void(*)(BackupTransfer*));
void ARM7_ReadBackupByte(BackupTransfer*);
void ARM7_WriteBackupByte(BackupTransfer*);
void ARM7_CompareBackupByte(BackupTransfer*);
#endif
