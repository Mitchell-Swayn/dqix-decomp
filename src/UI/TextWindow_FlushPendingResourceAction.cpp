#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2107820; symbol: data_02107820.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char Main_UnknownRoleZeroInitializedStorage[],TextWindowFlushPendingResourceAction_UnknownRoleZeroInitializedStorage[];
    void Resource_StopOrFadeSequence(void *,void *,int);
// Original: arm9/main @ 0x02045688; symbol: func_02045688; size: 0x48.
    void TextWindow_FlushPendingResourceAction(unsigned char *p){
        if(!p[6579]||!p[6578])return;
        Resource_StopOrFadeSequence(Main_UnknownRoleZeroInitializedStorage,TextWindowFlushPendingResourceAction_UnknownRoleZeroInitializedStorage,0);
        p[6579]=0;
    }
}
