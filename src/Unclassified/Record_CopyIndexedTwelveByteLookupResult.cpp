#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void ResolveTwoValuesThroughSharedObject();extern "C" void InitializeSerializedResourceUnlessReady(void*,void*,void*,void(*)());extern "C" void* Util_FindSixteenByteRecordByHalfwordKey(void*,int);
// Original: arm9/main @ 0x020E5334; symbol: func_020e5334; size: 0x88.
extern "C" void* Record_CopyIndexedTwelveByteLookupResult(void* out,void* source,int enabled,int index){if(!out||!source||!enabled||index<0)return 0;unsigned local[3];unsigned state;memset(local,0,12);InitializeSerializedResourceUnlessReady(local,source,&state,ResolveTwoValuesThroughSharedObject);void* data=Util_FindSixteenByteRecordByHalfwordKey(local,index);if(!data)return 0;memcpy(out,data,12);return out;}
