#include <globaldefs.h>
ARM
#pragma define_section init ".init" RX
struct DestructorNode { DestructorNode* next; void* (*destroy)(void*, int); void* object; };
extern "C" {
extern unsigned char data_020fefec[], data_02100044[];
extern DestructorNode data_020fefe0, data_020fefd4;
void* FinalizeObjectAndReturnPointer(void*); void* Object_Initialize1500ByteItemArrayAndTrailingRecords(void*);
void* ProcessOwnerWithStateTimeoutAndReturnSelf(void*, int); void* FinalizeThreeEmbeddedRecordsAndReturnPointer(void*, int);
void __register_global_object(void*, void* (*)(void*,int), DestructorNode*);
// Original: arm9/main @ 0x020E5B28; symbol: __sinit_020e5b28; size: 0x50.
__declspec(section "init") void __sinit_020e5b28() {
 FinalizeObjectAndReturnPointer(data_020fefec);
 __register_global_object(data_020fefec, ProcessOwnerWithStateTimeoutAndReturnSelf, &data_020fefe0);
 Object_Initialize1500ByteItemArrayAndTrailingRecords(data_02100044);
 __register_global_object(data_02100044, FinalizeThreeEmbeddedRecordsAndReturnPointer, &data_020fefd4);
}
}
