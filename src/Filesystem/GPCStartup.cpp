#if defined(usa)
// This reconstruction uses USA-specific layout; JPN retains its original range.
#include "Filesystem/GPCImplementation.h"
#include "Filesystem/GPC.h"

#pragma define_section init ".init" RX


// The existing startup table invokes this routine once before archive access.
extern "C" __declspec(section "init") void __sinit_020e6710()
{
    unsigned int signature0;
    unsigned int signature1;
    unsigned int signature2;
    gpcData.runtime.pRevisionNumberString = gpcData.runtime.pRevisionString + 11;
    SetGPCSignatureGPC0(&signature0);
    CopyGPCSignature(&gpcData.runtime.gpc0Signature, &signature0);
    SetGPCSignatureGPC1(&signature1);
    CopyGPCSignature(&gpcData.runtime.gpc1Signature, &signature1);
    SetGPCSignatureGPC2(&signature2);
    CopyGPCSignature(&gpcData.runtime.gpc2Signature, &signature2);
}

#endif // defined(usa)
