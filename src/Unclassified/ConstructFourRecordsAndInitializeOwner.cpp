#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void Object_InitializeFourEmbeddedRecords(void*);
extern "C" void FinalizeEmbeddedObjectsAtOffsets18And60And124And304(void*);
extern "C" void func_0200ee94(void*,unsigned,unsigned,void(*)(void*),void(*)(void*));
extern "C" void Object_InitializeFour318ByteRecords(void*);
// Original: arm9/main @ 0x02028C8C; symbol: func_02028c8c; size: 0x40.
extern "C" void* ConstructFourRecordsAndInitializeOwner(void* p){
    func_0200ee94(p,4,0x318,Object_InitializeFourEmbeddedRecords,FinalizeEmbeddedObjectsAtOffsets18And60And124And304);
    Object_InitializeFour318ByteRecords(p);
    return p;
}
