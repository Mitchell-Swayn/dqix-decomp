#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x21707c4; symbol: data_ov004_021707c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" void* MenuRebuildAlternateCatalogueFilteredList_UnknownRoleZeroInitializedStorage;
extern "C" void* Menu_FindAlternateCategoryCounter(void*,int);
#pragma always_inline on
inline short AddRecordValueForKey(short sum,void* records,int key){
 unsigned char* record=(unsigned char*)Menu_FindAlternateCategoryCounter(records,key);
 if(record)sum+=record[5];return sum;
}
// Original: arm9/ov004 @ 0x02155104; symbol: func_ov004_02155104; size: 0x38.
// Returns the byte value at offset 5 of global record key 9, or zero when absent.
extern "C" short Menu_GetCompletedAlternateCategoryNineCount(){return AddRecordValueForKey(0,MenuRebuildAlternateCatalogueFilteredList_UnknownRoleZeroInitializedStorage,9);}
