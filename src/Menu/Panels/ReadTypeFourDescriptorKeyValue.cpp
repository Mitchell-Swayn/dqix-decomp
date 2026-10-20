#include <globaldefs.h>
ARM
struct State;struct T;
extern "C" void* Menu_GetDisplayRecordRegistry(State*);
extern "C" void* MenuRecordList_LocateByKey(void**,unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" void* Menu_GetRecordMessageTable(void*);
extern "C" unsigned MessageTextTable_FindTextById(T*,int);
// Original: arm9/ov023 @ 0x021F63AC; symbol: func_ov023_021f63ac; size: 0x4C.
// Finds a type-four descriptor and reads the embedded record value for a signed halfword key.
extern "C" unsigned ReadTypeFourDescriptorKeyValue(State* state,unsigned short id,int key){
 void* descriptor=MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(state),id);
 if(!descriptor)return 0;if(MenuRecord_GetType(descriptor)!=4)return 0;
 return MessageTextTable_FindTextById((T*)Menu_GetRecordMessageTable(descriptor),(short)key);
}
