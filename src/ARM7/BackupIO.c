/* Backup reads and page-bounded writes/programming. */
#pragma dont_inline on
#include "BackupTransfer.h"
extern int ARM7_CheckBackupReady(void);
extern void ARM7_EnableBackupWrites(void);
extern void ARM7_SendBackupAddress(unsigned int,unsigned int);
extern void ARM7_WaitBackupReady(int,int);
#pragma dont_inline off
static inline unsigned int Min(unsigned int a,unsigned int b) { return a>b?b:a; }
void ARM7_ReadBackup(unsigned int address,unsigned char *destination,unsigned int count)
{
 if(ARM7_CheckBackupReady()) {
  ARM7_BackupCommandState.transfer.remaining=ARM7_BackupWorker.request->addressBytes+1+count;
  ARM7_SendBackupAddress(address,3);
  ARM7_TransferBackupBytes(0,destination,count,ARM7_ReadBackupByte);
 }
}
void ARM7_WriteBackup(unsigned int address,const unsigned char *source,unsigned int count)
{
 BackupRequest *request;
 unsigned int pageSize,chunk;
 if(ARM7_CheckBackupReady()) {
  request=ARM7_BackupWorker.request;
  pageSize=request->pageSize;

  while(count) {
   chunk=pageSize-(address&(pageSize-1));
   chunk=Min(chunk,count);
   ARM7_EnableBackupWrites();
   ARM7_BackupCommandState.transfer.remaining=request->addressBytes+1+chunk;
   ARM7_SendBackupAddress(address,2);
   ARM7_TransferBackupBytes(source,0,chunk,ARM7_WriteBackupByte);
   ARM7_WaitBackupReady(request->writeDelay,0);
   if(request->result)break;
   source+=chunk;
   address+=chunk;
   count-=chunk;
  }
 }
}
void ARM7_ProgramBackup(unsigned int address,const unsigned char *source,unsigned int count)
{
 BackupRequest *request;
 unsigned int pageSize,chunk;
 if(ARM7_CheckBackupReady()) {
  request=ARM7_BackupWorker.request;
  pageSize=request->pageSize;

  while(count) {
   chunk=pageSize-(address&(pageSize-1));
   chunk=Min(chunk,count);
   ARM7_EnableBackupWrites();
   ARM7_BackupCommandState.transfer.remaining=request->addressBytes+1+chunk;
   ARM7_SendBackupAddress(address,10);
   ARM7_TransferBackupBytes(source,0,chunk,ARM7_WriteBackupByte);
   ARM7_WaitBackupReady(request->programDelay,request->programTimeout);
   if(request->result)break;
   source+=chunk;
   address+=chunk;
   count-=chunk;
  }
 }
}
