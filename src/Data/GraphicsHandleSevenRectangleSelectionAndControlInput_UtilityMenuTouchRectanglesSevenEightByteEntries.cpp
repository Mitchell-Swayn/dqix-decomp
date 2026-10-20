// Utility menu touch rectangles, seven eight-byte entries; Graphics_HandleSevenRectangleSelectionAndControlInput iterates them.
struct TouchRectangle { unsigned short left, top, right, bottom; };
// Original data: arm9/ov031 @ 0x224909a; symbol: data_ov031_0224909a.
// Utility menu touch rectangles, seven eight-byte entries; Graphics_HandleSevenRectangleSelectionAndControlInput iterates them.
// Initial values: hex 08002000540056005a002000a6005600ac002000f800560008007800f800a00008005400540070005a005400a6007000ac005400f8007000.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" const TouchRectangle GraphicsHandleSevenRectangleSelectionAndControlInput_UtilityMenuTouchRectanglesSevenEightByteEntries[7] = {
    { 8, 32, 84, 86 },
    { 90, 32, 166, 86 },
    { 172, 32, 248, 86 },
    { 8, 120, 248, 160 },
    { 8, 84, 84, 112 },
    { 90, 84, 166, 112 },
    { 172, 84, 248, 112 },
};
