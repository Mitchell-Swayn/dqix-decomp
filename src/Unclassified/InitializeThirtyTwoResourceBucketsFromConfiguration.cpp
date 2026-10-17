#include <globaldefs.h>
#pragma optimize_for_size off
struct Entry{unsigned char count,pad;unsigned short value;void* resource;};extern "C" void ReadGlobalAt02110370();extern "C" Entry* ReadBoundedGlobalTableEntryAtHeader18(int);extern "C" void SetIndexedGlobalHalfwordValue(int,int);extern "C" void ResourceManager_SetIndexedThirtySixByteRecordValue(int,unsigned);extern "C" int AllocateHeaderAndInitializePayload(int,void*,void*);
// Original: arm9/main @ 0x020BE6C4; symbol: func_020be6c4; size: 0x9C.
extern "C" ARM int InitializeThirtyTwoResourceBucketsFromConfiguration(void* owner){ReadGlobalAt02110370();int i=0;do{Entry* e=ReadBoundedGlobalTableEntryAtHeader18(i);if(e){SetIndexedGlobalHalfwordValue(i,e->count);ResourceManager_SetIndexedThirtySixByteRecordValue(i,e->value);if(e->resource&&owner){int j=0;if((int)e->count>0)do{if(!AllocateHeaderAndInitializePayload(i,owner,e->resource))return 0;++j;}while(j<e->count);}}++i;}while(i<32);return 1;}
