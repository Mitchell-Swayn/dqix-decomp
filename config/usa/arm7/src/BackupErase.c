/* Backup comparison and aligned sector/subsector/chip erase operations. */
#pragma dont_inline on
#include "BackupTransfer.h"
extern int ARM7_CheckBackupReady(void);
extern void ARM7_EnableBackupWrites(void);
extern void ARM7_SendBackupAddress(unsigned int,unsigned int);
extern void ARM7_WaitBackupReady(int,int);
#pragma dont_inline off
static inline unsigned int AlignmentRemainder(unsigned int value,unsigned int alignment) {return (alignment-1)&value;}
void ARM7_CompareBackup(unsigned int address,const unsigned char *source,unsigned int count)
{
 if(ARM7_CheckBackupReady()) {
  BackupRequest *request=ARM7_BackupWorker.request;
  ARM7_BackupCommandState.transfer.matched=1;
  ARM7_BackupCommandState.transfer.remaining=request->addressBytes+1+count;
  ARM7_SendBackupAddress(address,3);
  ARM7_TransferBackupBytes(source,0,count,ARM7_CompareBackupByte);
  if(request->result==0 && !ARM7_BackupCommandState.transfer.matched)request->result=1;
 }
}
void ARM7_EraseBackupSectors(unsigned int address,unsigned int count)
{
 BackupRequest *request=ARM7_BackupWorker.request;
 unsigned int size=request->sectorSize;
 if(AlignmentRemainder(address|count,size)) {request->result=2;return;}
 if(ARM7_CheckBackupReady()) {
  while(count) {
   ARM7_EnableBackupWrites();
   ARM7_BackupCommandState.transfer.remaining=request->addressBytes+1;
   ARM7_SendBackupAddress(address,0xd8);
   ARM7_WaitBackupReady(request->sectorEraseDelay,request->sectorEraseTimeout);
   if(request->result)break;
   address+=size;
   count-=size;
  }
 }
}
void ARM7_EraseBackupSubsectors(unsigned int address,unsigned int count)
{
 BackupRequest *request=ARM7_BackupWorker.request;
 unsigned int size=request->subsectorSize;
 if(AlignmentRemainder(address|count,size)) {request->result=2;return;}
 if(ARM7_CheckBackupReady()) {
  while(count) {
   ARM7_EnableBackupWrites();
   ARM7_BackupCommandState.transfer.remaining=request->addressBytes+1;
   ARM7_SendBackupAddress(address,0x20);
   ARM7_WaitBackupReady(request->subsectorEraseDelay,request->subsectorEraseTimeout);
   if(request->result)break;
   address+=size;
   count-=size;
  }
 }
}

extern const unsigned char ARM7_BackupChipEraseCommand[];
void ARM7_EraseBackupChip(void)
{
 if(ARM7_CheckBackupReady()) {
  BackupRequest *request=ARM7_BackupWorker.request;
  ARM7_EnableBackupWrites();
  ARM7_BackupCommandState.transfer.remaining=1;
  ARM7_TransferBackupBytes(ARM7_BackupChipEraseCommand,0,1,ARM7_WriteBackupByte);
  ARM7_WaitBackupReady(request->chipEraseDelay,request->chipEraseTimeout);
 }
}
