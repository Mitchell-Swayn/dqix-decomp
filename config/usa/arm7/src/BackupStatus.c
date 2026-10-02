/* Read backup status and report readiness through the worker result. */
#pragma dont_inline on
#include "BackupTransfer.h"
extern const unsigned char ARM7_BackupReadStatusCommand[];
unsigned int ARM7_ReadBackupStatus(void)
{
 unsigned char status;
 ARM7_BackupCommandState.transfer.remaining=2;
 ARM7_TransferBackupBytes(ARM7_BackupReadStatusCommand,0,1,ARM7_WriteBackupByte);
 ARM7_TransferBackupBytes(0,&status,1,ARM7_ReadBackupByte);
 return status;
}
extern void ARM7_WaitBackupReady(int,int);
int ARM7_CheckBackupReady(void)
{
 ARM7_WaitBackupReady(0,50);
 if(ARM7_BackupWorker.request->result==4) {
  ARM7_BackupWorker.request->result=6;
  return 0;
 }
 return 1;
}
