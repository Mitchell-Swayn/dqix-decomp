// Two modes of four touch rectangles; func_ov031_02233524 indexes mode*32 + key*8.
struct TouchRectangle { unsigned short left, top, right, bottom; };
// Original data: arm9/ov031 @ 0x2249158; symbol: data_ov031_02249158.
// Two modes of four touch rectangles; func_ov031_02233524 indexes mode*32 + key*8.
// Initial values: hex 08002000f8005c00080064007e00a000000000000000000083006400f800a00008002000f8005c00080064006400a00068006400c400a000c8006400f800a000.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" const TouchRectangle WfcConnectionMethodProcessChooserInput_TwoModesOfFourTouchRectangles[8] = {
    { 8, 32, 248, 92 },
    { 8, 100, 126, 160 },
    { 0, 0, 0, 0 },
    { 131, 100, 248, 160 },
    { 8, 32, 248, 92 },
    { 8, 100, 100, 160 },
    { 104, 100, 196, 160 },
    { 200, 100, 248, 160 },
};
