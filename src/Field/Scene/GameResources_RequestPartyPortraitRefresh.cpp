#include <globaldefs.h>
// Original data: arm9/ov017 @ 0x21d82e0; symbol: data_ov017_021d82e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned char* FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage[];
extern "C" void PartyStatus_RequestMemberPortraitRefresh(char*,int);
// Original: arm9/ov017 @ 0x0218B5F8; symbol: func_ov017_0218b5f8; size: 0x30.
// Field roles are unresolved; observed offsets are retained.
extern "C" ARM void GameResources_RequestPartyPortraitRefresh(int index)
{
    unsigned char* p = FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage[1];
    if (p)
    {
        p = *(unsigned char**)(p + 0x36d0);
        if (p) PartyStatus_RequestMemberPortraitRefresh((char*)p,index);
    }
}
