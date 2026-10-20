// Access point selection touch rectangles, five eight-byte entries; func_ov031_0222bb58 iterates them.
struct TouchRectangle { unsigned short left, top, right, bottom; };
// Original data: arm9/ov031 @ 0x2248e5c; symbol: data_ov031_02248e5c.
// Access point selection touch rectangles, five eight-byte entries; func_ov031_0222bb58 iterates them.
// Initial values: hex 07003200d0004c0007004e00d000680007006a00d000840007008600d000a00085001b00fd002c00.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" const TouchRectangle WfcUtilityHandleAccessPointListInput_AccessPointSelectionTouchRectanglesFiveEightByteEntries[5] = {
    { 7, 50, 208, 76 },
    { 7, 78, 208, 104 },
    { 7, 106, 208, 132 },
    { 7, 134, 208, 160 },
    { 133, 27, 253, 44 },
};
