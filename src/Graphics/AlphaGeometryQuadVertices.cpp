// Original data: arm9/main @ 0x020E8804; symbol: data_020e8804; size: 48.
// Owner: src/Graphics/Graphics_DrawColoredAlphaGeometry.cpp.
// Retain the existing external linker identity pending semantic renaming.
// Four fixed-point vertices for the colored alpha quad, in submission order.
// The caller copies all four XYZ triples before sending each coordinate to GX.
struct VertexTable { int xyz[4][3]; };
extern "C" {
extern const VertexTable GraphicsDrawColoredAlphaGeometry_UnknownRoleInitializedBytes = {
    { {4096,4096,0}, {-4096,4096,0}, {-4096,-4096,0}, {4096,-4096,0} }
};
}
