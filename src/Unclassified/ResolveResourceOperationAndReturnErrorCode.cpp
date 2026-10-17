#include <globaldefs.h>
ARM
struct Code {unsigned id:24;unsigned flags:8;};
extern "C" Code* GetBoundedRelocatedBlobIndexEntryFromHeader14(void*);
extern "C" int ReadIndexedSixteenByteTableWord14(unsigned);
extern "C" int ResourceManager_GetOrCreateSecondaryCachedValue(unsigned,int,int);
extern "C" int func_020be2ec(unsigned,int,int);
// Original: arm9/main @ 0x020BE010; symbol: func_020be010; size: 0x8C.
extern "C" int ResolveResourceOperationAndReturnErrorCode(void* resource,unsigned flags,int a,int b,int* out) {
    Code* p=GetBoundedRelocatedBlobIndexEntryFromHeader14(resource);if(!p)return 5;
    int result;
    if(flags&4){if(p->flags&1)result=func_020be2ec(p->id,a,b);else result=ResourceManager_GetOrCreateSecondaryCachedValue(p->id,a,b);if(!result)return 9;}
    else result=ReadIndexedSixteenByteTableWord14(p->id);
    if(out)*out=result;return 0;
}
