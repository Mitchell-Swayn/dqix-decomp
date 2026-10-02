/* Cartridge backup SPI transfers through AUXSPICNT/AUXSPIDATA.
 * The comparison callback shortens a failed comparison to its final byte. */
#pragma dont_inline on
#include "BackupTransfer.h"
#define CONTROL (*(volatile unsigned short*)0x040001a0)
#define DATA (*(volatile unsigned short*)0x040001a2)
void ARM7_TransferBackupBytes(const unsigned char *source, unsigned char *destination, unsigned int count, void (*transferByte)(BackupTransfer*))
{
 BackupTransfer *transfer=&ARM7_BackupTransfer;
 transfer->source=source;
 transfer->destination=destination;
 CONTROL=0xa040;
 while(count) {
  if(--transfer->remaining==0)CONTROL=0xa000;
  while(CONTROL&0x80) {}
  transferByte(transfer);
  --count;
 }
 if(transfer->remaining==0)CONTROL=0;
}
void ARM7_ReadBackupByte(BackupTransfer *transfer)
{
 DATA=0;
 while(CONTROL&0x80) {}
 *transfer->destination=DATA;
 transfer->destination++;
}
void ARM7_WriteBackupByte(BackupTransfer *transfer)
{
 volatile unsigned short received;
 DATA=*transfer->source;
 transfer->source++;
 while(CONTROL&0x80) {}
 received=DATA;
}
void ARM7_CompareBackupByte(BackupTransfer *transfer)
{
 DATA=0;
 while(CONTROL&0x80) {}
 if((unsigned char)DATA != *transfer->source) {
  transfer->matched=0;
  if(transfer->remaining>1)transfer->remaining=1;
 }
 transfer->source++;
}
