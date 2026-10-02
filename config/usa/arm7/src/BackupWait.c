/* Polling of backup status with bounded sleep intervals. */
#pragma dont_inline on
#include "BackupTransfer.h"
extern void ARM7_SleepThread(int);
extern unsigned int ARM7_ReadBackupStatus(void);
#pragma dont_inline off
static inline int IsReady(void) { return (ARM7_ReadBackupStatus()&1)==0; }
void ARM7_WaitBackupReady(int initialDelay,int timeout)
{
 if(initialDelay+timeout==0)return;
 if(initialDelay)ARM7_SleepThread(initialDelay);
 if(timeout) {
  int remaining=timeout-initialDelay;
  while(!IsReady() && remaining>0) {
   int interval=remaining<5?remaining:5;
   ARM7_SleepThread(interval);
   remaining-=interval;
  }
 }
 if(!IsReady())ARM7_BackupWorker.request->result=4;
}
