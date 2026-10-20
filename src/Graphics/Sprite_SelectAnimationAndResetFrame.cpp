#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2114e50; symbol: data_02114e50.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern int FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage_Variant2;
// Original: arm9/main @ 0x02076928; symbol: func_02076928; size: 0x60.
    void Sprite_SelectAnimationAndResetFrame(unsigned char *p,int id){
        if(!p[95])return;
        if(*(int *)(p+84)<=0)return;
        if(*(int *)(p+100)==id||id==0)return;
        *(int *)(p+96)=0;
        *(int *)(p+100)=id;
        *(int *)(p+104)=FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage_Variant2;
        *(int *)(p+108)=(*(int ***)(p+32))[*(int *)(p+100)][*(int *)(p+96)];
    }
}
