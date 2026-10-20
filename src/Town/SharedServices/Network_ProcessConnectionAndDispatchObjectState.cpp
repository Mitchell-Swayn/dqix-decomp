#include <globaldefs.h>
ARM
struct Owner;
extern "C" void* Network_GetConnectionManager();
extern "C" void* Network_GetCommandRecordPool();
extern "C" unsigned WaitForStateThreeThenProcessOwnerWithTimeout(Owner*);
extern "C" unsigned Network_GetSessionPhase(void*);
extern "C" void Network_RestartOperationAndTrackFailure();
extern "C" void Network_DispatchEnabledPendingRecords();
struct DispatchObject {unsigned char state;};
typedef void (DispatchObject::*Method)();
// Original data: arm9/ov003 @ 0x2180cc4; symbol: data_ov003_02180cc4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" unsigned NetworkProcessConnectionAndDispatchObjectState_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Method ShopUpdateInterface_UnknownRoleInitializedBytes;
// Original data: arm9/ov003 @ 0x218070c; symbol: data_ov003_0218070c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 50151702000000004016170200000000f816170200000000641717020000000054181702000000003c19170200000000f01a170200000000a01b170200000000 ...; full span in module reference.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" Method NetworkProcessConnectionAndDispatchObjectState_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/ov003 @ 0x021714A0; symbol: func_ov003_021714a0; size: 0xB0.
extern "C" int Network_ProcessConnectionAndDispatchObjectState(DispatchObject* p){
 void* connection=Network_GetConnectionManager();
 Network_GetCommandRecordPool();Network_DispatchEnabledPendingRecords();
 if(Network_GetSessionPhase(connection)==(unsigned)-1){
 Network_RestartOperationAndTrackFailure();
 WaitForStateThreeThenProcessOwnerWithTimeout((Owner*)connection);
 return 0;
 }
 if(!(NetworkProcessConnectionAndDispatchObjectState_UnknownRoleZeroInitializedStorage&1)){
 NetworkProcessConnectionAndDispatchObjectState_UnknownRoleProcedureReferenceRecords[11]=ShopUpdateInterface_UnknownRoleInitializedBytes;
 NetworkProcessConnectionAndDispatchObjectState_UnknownRoleZeroInitializedStorage|=1;
 }
 (p->*NetworkProcessConnectionAndDispatchObjectState_UnknownRoleProcedureReferenceRecords[p->state])();
 return 1;
}
