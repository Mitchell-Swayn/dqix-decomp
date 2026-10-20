// Original data: arm9/main @ 0x020E7A20; symbol: data_020e7a20; size: 48.
// Owner: src/World/Object_DispatchRandomStepWithinBounds.cpp.
// Retain the existing external linker identity pending semantic renaming.
// Initial fixed-point unit steps in +X, +Z, -X, -Z order. The caller copies
// the four vectors, optionally rotates them, and retains directions allowed by
// the configured position bounds before selecting a random candidate.
struct Vec {int x,y,z;};struct Directions {Vec vectors[4];};
extern "C" {
extern const Directions ObjectDispatchRandomStepWithinBounds_UnknownRoleInitializedBytes = {
    { {4096,0,0}, {0,0,4096}, {-4096,0,0}, {0,0,-4096} }
};
}
