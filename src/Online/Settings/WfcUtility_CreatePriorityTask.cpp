#include <globaldefs.h>
ARM
extern "C" { typedef void WfcTaskCallback(void*, void*); }
// Original data: arm9/ov031 @ 0x2290d9c; symbol: data_ov031_02290d9c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern char* WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage;char* WfcUtility_PopPointerRingBack(void*);unsigned _Z25DisableSpecificInterruptsj(unsigned);void _Z24EnableSpecificInterruptsj(unsigned);void WfcUtility_InsertListNodeBefore(void*,void*);}
// Original: arm9/ov031 @ 0x0223E22C; symbol: AllocateAndInsertPriorityRecord; size: 0x8c.
// Allocates record and inserts before first higher-priority node while interrupt1 is disabled.
extern "C" void* WfcUtility_CreatePriorityTask(unsigned index,WfcTaskCallback* a,void* b,unsigned priority,unsigned char flag){char* record=WfcUtility_PopPointerRingBack(*(void**)(WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage+index*64));*(WfcTaskCallback**)(record+8)=a;*(void**)(record+12)=b;record[16]=priority;record[17]=flag;unsigned irq=_Z25DisableSpecificInterruptsj(1);char* node=*(char**)(WfcUtilityDestroyTaskQueues_UnknownRoleZeroInitializedStorage+index*64+16);for(;;){if(priority<(unsigned char)node[16]){WfcUtility_InsertListNodeBefore(node,record);break;}node=*(char**)(node+4);}_Z24EnableSpecificInterruptsj(irq);return record;}
