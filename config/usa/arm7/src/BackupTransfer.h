#ifndef ARM7_BACKUP_TRANSFER_H
#define ARM7_BACKUP_TRANSFER_H

typedef struct {
 unsigned int remaining;
 const unsigned char *source;
 unsigned char *destination;
 int matched;
} BackupTransfer;
typedef struct {
 unsigned int unknown0;
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
} BackupRequest;
/* Only the request pointer at the start of the worker state is recovered here. */
typedef struct { BackupRequest *request; } BackupWorker;
typedef char BackupTransferSizeCheck[sizeof(BackupTransfer)==16?1:-1];
extern BackupTransfer ARM7_BackupTransfer;
extern BackupCommandState ARM7_BackupCommandState;
extern BackupWorker ARM7_BackupWorker;
void ARM7_TransferBackupBytes(const unsigned char*,unsigned char*,unsigned int,void(*)(BackupTransfer*));
void ARM7_ReadBackupByte(BackupTransfer*);
void ARM7_WriteBackupByte(BackupTransfer*);
void ARM7_CompareBackupByte(BackupTransfer*);
#endif
