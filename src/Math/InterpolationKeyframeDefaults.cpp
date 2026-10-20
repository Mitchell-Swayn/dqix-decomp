// Original data: arm9/main @ 0x020E8D0C; symbol: data_020e8d0c; size: 48.
// Owner: src/Math/Math_InterpolateAdjacentTableValues.cpp.
// Retain the existing external linker identity pending semantic renaming.
// Three interpolation keyframes. The caller copies the complete table and
// interpolates the x, y, z and w fields between adjacent entries. The second
// short is the existing owning type's explicit padding field and is zero.
struct Values { int x,y; float z; unsigned short w,pad; };
struct ValueTable { Values entries[3]; };
extern "C" {
extern const ValueTable MathInterpolateAdjacentTableValues_UnknownRoleInitializedBytes = {
    { {128,96,1.3f,0,0}, {128,96,1.0f,0,0}, {211,33,1.0f,5800,0} }
};
}
