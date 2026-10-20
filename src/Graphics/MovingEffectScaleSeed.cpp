// Original data: arm9/main @ 0x020E7DA4; symbol: data_020e7da4; size: 12.
// Owner: src/Graphics/UpdateAndDrawMovingEffect.cpp.
// The external linker identity remains unchanged pending semantic renaming.
extern "C" {
// Initial effect scale vector. The caller replaces X and Y with animated
// scale factors and preserves fixed-point Z=4096 (one).
struct EffectVector { int x,y,z; };
extern const EffectVector UpdateAndDrawMovingEffect_UnknownRoleInitializedBytes = {0,0,4096};
}
