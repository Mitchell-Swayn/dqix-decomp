#include <globaldefs.h>
ARM
extern "C" unsigned short func_0208a370(void*,int,int,void**,int);
// Original: arm9/main @ 0x0208A4CC; symbol: func_0208a4cc; size: 0x20.
extern "C" unsigned short Object_LookupIndexedResourceInKindOne(void* owner,int index,void** out,int kind) {
    return func_0208a370(owner,1,index,out,kind);
}
