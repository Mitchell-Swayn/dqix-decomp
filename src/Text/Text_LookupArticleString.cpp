#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original data: arm9/main @ 0x21536ac; symbol: data_021536ac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char TextLookupArticleString_UnknownRoleZeroInitializedStorage[];
    void *ResourceStringTable_GetTextByKey(void *,int);
// Original: arm9/main @ 0x020E51E4; symbol: func_020e51e4; size: 0x18.
    void *Text_LookupArticleString(int id){
        return ResourceStringTable_GetTextByKey(TextLookupArticleString_UnknownRoleZeroInitializedStorage,id);
    }
}
