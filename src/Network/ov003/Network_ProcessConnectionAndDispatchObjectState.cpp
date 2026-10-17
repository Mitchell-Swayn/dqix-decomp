#include <globaldefs.h>
ARM
struct Owner;
extern "C" void* Object_GetGlobalConnectionState();
extern "C" void* ReadGlobalAt02100044();
extern "C" unsigned WaitForStateThreeThenProcessOwnerWithTimeout(Owner*);
extern "C" unsigned ReadValue_Main0202BA00(void*);
extern "C" void Network_RestartOperationAndTrackFailure();
extern "C" void Network_DispatchEnabledPendingRecords();
struct DispatchObject {unsigned char state;};
typedef void (DispatchObject::*Method)();
extern "C" unsigned data_ov003_02180cc4;
extern "C" Method data_020e6d5c;
extern "C" Method data_ov003_0218070c[];
// Original: arm9/ov003 @ 0x021714A0; symbol: func_ov003_021714a0; size: 0xB0.
extern "C" int Network_ProcessConnectionAndDispatchObjectState(DispatchObject* p){
 void* connection=Object_GetGlobalConnectionState();
 ReadGlobalAt02100044();Network_DispatchEnabledPendingRecords();
 if(ReadValue_Main0202BA00(connection)==(unsigned)-1){
 Network_RestartOperationAndTrackFailure();
 WaitForStateThreeThenProcessOwnerWithTimeout((Owner*)connection);
 return 0;
 }
 if(!(data_ov003_02180cc4&1)){
 data_ov003_0218070c[11]=data_020e6d5c;
 data_ov003_02180cc4|=1;
 }
 (p->*data_ov003_0218070c[p->state])();
 return 1;
}
