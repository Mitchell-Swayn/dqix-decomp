/* Retry backup status writes on the observed timeout result. */
#pragma dont_inline on
#include "BackupTransfer.h"
extern int ARM7_CheckBackupReady(void);
extern void ARM7_EnableBackupWrites(void);
extern void ARM7_WaitBackupReady(int,int);
void ARM7_WriteBackupStatus(unsigned int status)
{
 if(ARM7_CheckBackupReady()) {
  unsigned char command[2];
  BackupRequest *request=ARM7_BackupWorker.request;
  int attempts=10;
  command[0]=1;
  command[1]=status;
  do {
   ARM7_EnableBackupWrites();
   ARM7_BackupCommandState.transfer.remaining=2;
   ARM7_TransferBackupBytes(command,0,2,ARM7_WriteBackupByte);
   ARM7_WaitBackupReady(5,0);
   if(request->result!=4)break;
  } while(--attempts>0);
 }
}
