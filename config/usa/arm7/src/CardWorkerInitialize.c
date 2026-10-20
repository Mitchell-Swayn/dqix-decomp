/* Initialize worker bookkeeping, start its thread and install cartridge IPC. */
#pragma dont_inline on
#pragma opt_propagation off
#include "BackupTransfer.h"
extern void ARM7_CreateThread(ProcessorContext*,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
extern void ARM7_MarkThreadReady(ProcessorContext*);
extern void ARM7_SetIpcHandler(int,void(*)(int,unsigned int,int));
extern void ARM7_CardIpcCallback(int,unsigned int,int);
extern void ARM7_CardWorkerMain(void*);
extern unsigned int ARM7_CardBootModeFlag;
#define SHARED_BOOT_MODE (*(volatile unsigned short*)0x027ffc40)
// Original: arm7/wram @ 0x03802CFC; symbol: ARM7_InitializeCardWorker.
void ARM7_InitializeCardWorker(void) {
 BackupWorker *worker=&ARM7_BackupWorker;
 int isMode2;
 *(volatile int*)&worker->unknownC=-3;
 *(volatile unsigned int*)&worker->priority=4;
 worker->unknown10=0;
 worker->unknown1C=0;
 worker->request=0;
 worker->receivedCount=0;
 worker->unknown18=0;
 worker->unknown14=0;
 worker->waiters.last=0;
 worker->waiters.first=0;
 ARM7_CreateThread(&worker->thread,(unsigned int)ARM7_CardWorkerMain,0,(unsigned int)&ARM7_BackupCommandState,0x400,worker->priority);
 ARM7_MarkThreadReady(&worker->thread);
 ARM7_SetIpcHandler(11,ARM7_CardIpcCallback);
 isMode2=SHARED_BOOT_MODE==2;
 if(!isMode2)ARM7_CardBootModeFlag=1;
}
