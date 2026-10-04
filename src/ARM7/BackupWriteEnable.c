/* Issue the backup write-enable command. */
#pragma dont_inline on
#include "BackupTransfer.h"
extern const unsigned char ARM7_BackupWriteEnableCommand[];
void ARM7_EnableBackupWrites(void)
{
 ARM7_BackupCommandState.transfer.remaining=1;
 ARM7_TransferBackupBytes(ARM7_BackupWriteEnableCommand,0,1,ARM7_WriteBackupByte);
}
