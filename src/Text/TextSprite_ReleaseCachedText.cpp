#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2105244; symbol: data_02105244.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char *TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage;
    void TextCache_ReleaseEntryHandle(unsigned char *,short *);
// Original: arm9/main @ 0x0203C198; symbol: func_0203c198; size: 0x30.
    void TextSprite_ReleaseCachedText(unsigned char *p){
        if(!TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage)return;
        TextCache_ReleaseEntryHandle(TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage,(short *)(p+20));
        *(short *)(p+20)=-1;
    }
}
