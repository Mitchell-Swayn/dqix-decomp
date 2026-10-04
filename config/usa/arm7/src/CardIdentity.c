/* Cartridge control flags, empty hook and raw/serialized ID reads. */
#pragma dont_inline on
#include "BackupTransfer.h"
typedef struct {unsigned char unknown0[0x60];unsigned int cardControl;} CardHeader;
extern const CardHeader *ARM7_CardHeader;
extern void ARM7_SetCardCommand(unsigned int,unsigned int);
extern void ARM7_BeginCardOperation(BackupWorker*,void(*)(void*),void*);
extern void ARM7_CompleteCardOperation(void);
#define ROMCTRL (*(volatile unsigned int*)0x040001a4)
#define CARDDATA (*(volatile unsigned int*)0x04100010)
unsigned int ARM7_GetCardControl(unsigned int transferSize)
{
 return (ARM7_CardHeader->cardControl&~0x07000000)|transferSize|0xa0000000;
}
void ARM7_CardNoOp(void) {}
unsigned int ARM7_ReadCardId(void)
{
 ARM7_SetCardCommand(0xb8000000,0);
 ROMCTRL=ARM7_GetCardControl(0x07000000)&~0x1fff;
 while(!(ROMCTRL&0x00800000)) {}
 return CARDDATA;
}
unsigned int ARM7_ReadCardIdLocked(void)
{
 unsigned int result;
 ARM7_BeginCardOperation(&ARM7_BackupWorker,0,0);
 result=ARM7_ReadCardId();
 ARM7_CompleteCardOperation();
 return result;
}
