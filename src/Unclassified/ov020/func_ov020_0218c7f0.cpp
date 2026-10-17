// The two grid descriptors occupy 0x50-byte reservations at offsets 0x20/0x70.
struct Overlay20GridDescriptor {
    int count, unknown04, columns, rows;
    unsigned char orientation;
    unsigned char remaining[0x3f];
};
struct Overlay20Grids { unsigned char preceding[0x20]; Overlay20GridDescriptor first, second; };
extern "C" void Grid_SetOrientationAndCoordinatePointers(Overlay20GridDescriptor*, int columns, int rows, unsigned char orientation);
extern "C" void SetNonnegativeValueAndClampSelection(Overlay20GridDescriptor*, int count);
// Original: arm9/ov020 @ 0x0218C7F0; symbol: func_ov020_0218c7f0; size: 0x50.
extern "C" void func_ov020_0218c7f0(Overlay20Grids* grids, int columns, int rows)
{
    Grid_SetOrientationAndCoordinatePointers(&grids->first, columns, rows, 0);
    Grid_SetOrientationAndCoordinatePointers(&grids->second, columns, rows, 0);
    int count = columns * rows;
    SetNonnegativeValueAndClampSelection(&grids->first, count);
    SetNonnegativeValueAndClampSelection(&grids->second, count);
}
