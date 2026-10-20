#include <globaldefs.h>
extern "C" void _ZN8Object3D14AdvanceEffectsEv(void *);
extern "C" void _ZN8Object3D26SetNormalizedAnimationTimeEi(void *, int);
extern "C" void KrakPot_AdvanceRecipePreviewLoad(void *);
extern "C" int ItemDetail_DispatchDisplayState(void *);
// Original: arm9/ov006 @ 0x02156B80; symbol: func_ov006_02156b80; size: 0x58.
extern "C" void KrakPot_UpdatePotAnimationAndRecipePreview(void *object) {
    unsigned short flags = *(unsigned short *)((char *)object + 0xae2);
    if ((flags & 8) == 0) {
        _ZN8Object3D14AdvanceEffectsEv((char *)object + 0x238);
        _ZN8Object3D14AdvanceEffectsEv((char *)object + 0x2e4);
        _ZN8Object3D14AdvanceEffectsEv((char *)object + 0x390);
        _ZN8Object3D26SetNormalizedAnimationTimeEi((char *)object + 0x43c, *(int *)((char *)object + 0x308));
    }
    KrakPot_AdvanceRecipePreviewLoad(object);
    ItemDetail_DispatchDisplayState((char *)object + 0xae4);
}
