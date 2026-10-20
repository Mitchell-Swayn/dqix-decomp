/* Process cartridge IPC commands or execute the current local operation.
 * Busy/pending flags and waiting-thread selection are protected by IRQ state. */
#pragma dont_inline on
#pragma opt_propagation off
#include "BackupTransfer.h"
typedef struct {
 int result;
 unsigned int unknown4,cardId,source,destination,count;
 unsigned char backupParameters[0x40];
 unsigned int supportedCommands;
} CardWorkerRequest;
typedef char CardWorkerRequestMaskOffsetCheck[sizeof(CardWorkerRequest)==0x5c?1:-1];
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern void ARM7_BlockCurrentThread(BlockedContextList*);
extern void ARM7_UnblockThreads(BlockedContextList*);
extern void ARM7_MarkThreadReady(ProcessorContext*);
extern int ARM7_SendIpcCommand(int,unsigned int,int);
extern void ARM7_InitializeBackupStatus(void);
extern unsigned int ARM7_ReadCardId(void);
extern void ARM7_ReadBackup(unsigned int,unsigned char*,unsigned int);
extern void ARM7_ProgramBackup(unsigned int,const unsigned char*,unsigned int);
extern void ARM7_WriteBackup(unsigned int,const unsigned char*,unsigned int);
extern void ARM7_CompareBackup(unsigned int,const unsigned char*,unsigned int);
extern void ARM7_EraseBackupSectors(unsigned int,unsigned int);
extern void ARM7_EraseBackupSubsectors(unsigned int,unsigned int);
extern void ARM7_EraseBackupChip(void);
extern unsigned int ARM7_ReadBackupStatus(void);
extern void ARM7_WriteBackupStatus(unsigned int);
// Original: arm7/wram @ 0x03803990; symbol: ARM7_CardWorkerMain.
void ARM7_CardWorkerMain(void *argument) {
 BackupWorker *worker=&ARM7_BackupWorker;
 for(;;) {
  int pending=0;
  int state=ARM7_DisableIRQInterrupts();
  BlockedContextList *queue=0;
  ProcessorContext *thread=&worker->thread;
  for(;;) {
   if(!(worker->flags&4)) {
    if(worker->flags&0x10) {
     pending=1;
     worker->flags|=4;
     worker->flags&=~0x10;
     break;
    }
   } else if(worker->flags&8)break;
   worker->waitingThread=thread;
   ARM7_BlockCurrentThread(queue);
  }
  ARM7_SetIRQInterruptState(state);
  if(pending) {
   CardWorkerRequest *request;
   unsigned int command;
   worker->request->result=0;
   request=(CardWorkerRequest*)worker->request;
   command=worker->command;
   if(!(request->supportedCommands&(1u<<command)))request->result=3;
   else switch(command) {
   case 0:case 1:break;
   case 2:ARM7_InitializeBackupStatus();break;
   case 3:worker->request->unknown4[1]=ARM7_ReadCardId();break;
   case 4:request->result=3;break;
   case 6:ARM7_ReadBackup(request->source,(unsigned char*)request->destination,request->count);break;
   case 7:ARM7_ProgramBackup(request->destination,(const unsigned char*)request->source,request->count);break;
   case 8:ARM7_WriteBackup(request->destination,(const unsigned char*)request->source,request->count);break;
   case 9:ARM7_CompareBackup(request->destination,(const unsigned char*)request->source,request->count);break;
   case 11:ARM7_EraseBackupSectors(request->destination,request->count);break;
   case 15:ARM7_EraseBackupSubsectors(request->destination,request->count);break;
   case 12:ARM7_EraseBackupChip();break;
   case 13:*(unsigned char*)worker->request->unknown4[3]=ARM7_ReadBackupStatus();break;
   case 14:ARM7_WriteBackupStatus(*(const unsigned char*)request->source);break;
   default:request->result=3;break;
   }
   while(ARM7_SendIpcCommand(11,1,1)<0) {}
   { int completionState=ARM7_DisableIRQInterrupts();
   worker->flags&=~0x4c;
   ARM7_UnblockThreads(&worker->waiters);
   if(worker->flags&0x10)ARM7_MarkThreadReady(&worker->thread);
   ARM7_SetIRQInterruptState(completionState); }
  } else ((void(*)(BackupWorker*))worker->unknown44)(worker);
 }
}
