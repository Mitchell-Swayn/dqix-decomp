#include <globaldefs.h>
struct Object {unsigned char a,b,c,pad,enabled,mask;};
extern "C" void* GameResources_GetInstance();
extern "C" int Object_TestSelectedFloatWithinSixteen(void*,unsigned);
extern "C" char data_02108760[];
extern "C" void InvokeObjectWithStoredFieldC0(void*);
extern "C" void ResourceHandle_ApplyPreviousAndNewStateWithValue(void*,unsigned,unsigned);
extern "C" void DispatchNonnegativeStoredIndexWithTwoArguments(void*,unsigned,unsigned);
extern "C" void* Object_GetGlobalConnectionState();
extern "C" signed char ReadIndexedSignedField1038(void*);
extern "C" void System_QueuePackedRecordAE(unsigned,unsigned,unsigned,unsigned,unsigned char,unsigned,unsigned);
// Original: arm9/main @ 0x020A87D0; symbol: func_020a87d0; size: 0xA4.
extern "C" void Object_EnableAndNotifySelectedNetworkMember(Object* p) {if(p->enabled!=1){p->enabled=1;if(Object_TestSelectedFloatWithinSixteen(GameResources_GetInstance(),0)){InvokeObjectWithStoredFieldC0(data_02108760);ResourceHandle_ApplyPreviousAndNewStateWithValue(data_02108760,0x72,0x72);DispatchNonnegativeStoredIndexWithTwoArguments(data_02108760,0,0);}int index=ReadIndexedSignedField1038(Object_GetGlobalConnectionState());p->mask|=1u<<index;System_QueuePackedRecordAE(p->a,p->b,p->c,1,(unsigned char)index,0,0);}}
