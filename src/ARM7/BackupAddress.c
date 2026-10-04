/* Encode command/address bytes for the selected backup address width. */
#pragma dont_inline on
#include "BackupTransfer.h"
/* The request must select a supported one-, two- or three-byte address. */
void ARM7_SendBackupAddress(unsigned int address,unsigned int operation)
{
 unsigned int command;
 unsigned int addressBytes=ARM7_BackupWorker.request->addressBytes;
 switch(addressBytes) {
 case 1:command=operation|((address>>5)&8)|((address<<24)>>16);break;
 case 2:command=operation|(address&0xff00)|((address<<24)>>8);break;
 case 3:command=operation|((address>>8)&0xff00)|((address&0xff00)<<8)|(address<<24);break;
 }
 ARM7_TransferBackupBytes((const unsigned char*)&command,0,addressBytes+1,ARM7_WriteBackupByte);
}
