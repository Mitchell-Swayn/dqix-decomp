/* Collect cartridge IPC command state and select the thread to wake. */
#pragma dont_inline on
#include "BackupTransfer.h"
extern void ARM7_MarkThreadReady(ProcessorContext*);
void ARM7_CardIpcCallback(int channel,unsigned int message,int flag)
{
 if(channel==11 && flag) {
  BackupWorker *worker=&ARM7_BackupWorker;
  if(worker->receivedCount==0)worker->command=message;
  switch(worker->command) {
  case 0:
   if(worker->receivedCount) {
    if(worker->receivedCount==1) {
     worker->request=(BackupRequest*)message;
     worker->flags|=0x10;
    }
   }
   break;
  case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 12:case 13:case 14:case 15:
   worker->flags|=0x10;
   break;
  }
  if(!(worker->flags&0x10))worker->receivedCount++;
  else {
   worker->receivedCount=0;
   ARM7_MarkThreadReady((worker->flags&4)?worker->waitingThread:&worker->thread);
  }
 }
}
