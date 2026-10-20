#include <globaldefs.h>
extern "C" {
    unsigned char *Resource_GetActiveGraphicCacheEntry(unsigned int,int);
    unsigned char *ActorSpriteResource_GetAnimation(void *,int);
// Original data: arm9/main @ 0x2114e50; symbol: data_02114e50.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern int FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage_Variant2;
// Original: arm9/main @ 0x0203F138; symbol: func_0203f138; size: 0x90.
    void ActorSprite_SelectAnimation(unsigned char *p,int i){
        if(*(short *)(p+40)<0)return;
        unsigned char *q=Resource_GetActiveGraphicCacheEntry(*(unsigned int *)p,*(short *)(p+40));
        if(!q||!*(unsigned int *)(q+40))return;
        if(i<0||*(unsigned int *)(q+40)<=(unsigned int)i)return;
        if(*(int *)(p+48)==i)return;
        unsigned char *entry=ActorSpriteResource_GetAnimation(q+16,i);
        if(!entry)return;
        *(int *)(p+52)=0;
        *(int *)(p+48)=i;
        *(int *)(p+56)=FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage_Variant2;
        *(int *)(p+60)=(*(int **)(entry+12))[*(int *)(p+52)];
    }
}
