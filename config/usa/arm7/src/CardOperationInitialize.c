/* Initialize cartridge operation state, the worker and removal detection. */
#pragma dont_inline on
#pragma opt_propagation off
#include "BackupTransfer.h"
typedef struct { unsigned int state,unknown4[7]; void (*hook)(void); } CardOperationInterface;
extern CardOperationInterface ARM7_CardOperationInterface;
extern void ARM7_InitializeCardWorker(void);
extern void ARM7_CardNoOp(void);
extern void ARM7_InitializeCardRemoval(void);
// Original: arm7/wram @ 0x03803840; symbol: ARM7_InitializeCardOperations.
void ARM7_InitializeCardOperations(void) {
 BackupWorker *worker=&ARM7_BackupWorker;
 if(!worker->flags) {
  worker->flags=1;
  worker->unknown20[2]=0;
  worker->unknown20[1]=0;
  worker->unknown20[0]=0;
  worker->unknown20[3]=-1;
  worker->callback=0;
  worker->userData=0;
  ARM7_CardOperationInterface.state=0;
  ARM7_InitializeCardWorker();
  ARM7_CardOperationInterface.hook=ARM7_CardNoOp;
  ARM7_InitializeCardRemoval();
 }
}
