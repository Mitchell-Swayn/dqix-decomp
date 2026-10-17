#include <globaldefs.h>
#pragma always_inline on
struct Offset50VectorWords { unsigned words[3]; };

// Original: arm9/ov023 @ 0x021E613C; symbol: func_ov023_021e613c; size: 0x14.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM void CopyVectorAtOffset50(Offset50VectorWords* out, char* p)
{
    *out=*(Offset50VectorWords*)(p+0x50);
}
