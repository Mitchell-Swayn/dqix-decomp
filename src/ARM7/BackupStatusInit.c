/* Initialize the requested backup status once unless disabled. */
#pragma dont_inline on
#include "BackupTransfer.h"
extern unsigned int ARM7_ReadBackupStatus(void);
extern void ARM7_WriteBackupStatus(unsigned int);
void ARM7_InitializeBackupStatus(void)
{
 unsigned int status=ARM7_BackupWorker.request->initialStatus;
 if(status!=255 && !ARM7_BackupCommandState.statusInitialized) {
  if(status!=ARM7_ReadBackupStatus())ARM7_WriteBackupStatus(status);
  ARM7_BackupCommandState.statusInitialized=1;
 }
}
