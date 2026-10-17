#include <globaldefs.h>
ARM
#include <System/Mutex.h>
extern "C" {extern int data_02112750;extern Mutex data_02112754;void func_020d2220();void InitializeEightCallbackRecords();
// Original: arm9/main @ 0x020D21C0; symbol: func_020d21c0; size: 0x38.
void InitializeGlobalCommandMutexAndTablesOnce(){if(data_02112750)return;data_02112750=1;ZeroInitializeMutex(&data_02112754);func_020d2220();InitializeEightCallbackRecords();}}
