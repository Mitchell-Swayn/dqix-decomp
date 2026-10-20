#include <globaldefs.h>

ARM
extern "C" {
struct Key { unsigned short id,flags;unsigned a,b; };
int TextStream_IsControlToken(void *,Key *);void Object3D_InitializeExtendedAnimationWrapper(void *);
// Original: arm9/main @ 0x0206B198; symbol: func_0206b198; size: 0x8C.
void TextEntry_DecrementReferenceAndResetUnusedEntry(unsigned char *p,Key key) {
    if(key.id>=128)return;
    if(TextStream_IsControlToken(p,&key))return;
    unsigned char *entry=p+0x9b8+key.id*28;
    if(*(int *)(entry+8)<0)return;
    unsigned char *count=p+0x17b8+key.id;
    if(!*count)return;
    --*count;
    if(!*count){Object3D_InitializeExtendedAnimationWrapper(entry);*(unsigned *)(p+0x9b4)=(*(unsigned *)(p+0x9b4)-1)&127;}
}
}
