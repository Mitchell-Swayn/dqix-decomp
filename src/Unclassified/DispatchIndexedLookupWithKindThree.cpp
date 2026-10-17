#include <globaldefs.h>
ARM
extern "C" unsigned short func_0208a370(void*,int,int,void**,int);
// Original: arm9/main @ 0x0208A50C; symbol: func_0208a50c; size: 0x20.
extern "C" unsigned short DispatchIndexedLookupWithKindThree(void* owner,int index,void** out,int kind) {
    return func_0208a370(owner,3,index,out,kind);
}
