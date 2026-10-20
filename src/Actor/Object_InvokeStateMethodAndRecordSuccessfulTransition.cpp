#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20e8994; symbol: data_020e8994.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 346d070200000000a06d070200000000dc6f0702000000000075070200000000a076070200000000347a070200000000807e070200000000e881070200000000 ...; full span in module reference.
// Observed span: 104 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Object {unsigned char pad[0x130];int current,previous;unsigned char unknown[0x14];int value;};typedef bool (Object::*Method)();extern "C" Method ObjectInvokeStateMethodAndRecordSuccessfulTransition_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x02076CCC; symbol: func_02076ccc; size: 0x68.
extern "C" bool Object_InvokeStateMethodAndRecordSuccessfulTransition(Object* object,int index) {if(object->current==index)return true;bool success=(object->*ObjectInvokeStateMethodAndRecordSuccessfulTransition_UnknownRoleProcedureReferenceRecords[index])();bool result=false;if(success){object->previous=object->current;object->current=index;object->value=0;result=true;}return result;}
