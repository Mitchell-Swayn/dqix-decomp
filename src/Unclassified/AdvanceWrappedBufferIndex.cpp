#include <globaldefs.h>
ARM
struct Buffer {unsigned unknown;unsigned capacity;};
// Original: arm9/main @ 0x020BB964; symbol: func_020bb964; size: 0x20.
extern "C" unsigned short AdvanceWrappedBufferIndex(Buffer* p,unsigned index) {
    return (index+1)%p->capacity;
}
