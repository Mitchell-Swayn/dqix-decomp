// Menu grid layout by state ID; state 255 terminates the scan.
// SelectTableDrivenPanelLayout scans with a seven-byte stride and copies the
// unsigned dimensions, signed offsets and cell dimensions into the menu.
struct MenuGridLayout {
    unsigned char state, columns, rows;
    signed char xOffset, yOffset;
    unsigned char cellWidth, cellHeight;
};
// Original data: arm9/ov002 @ 0x216cb48; symbol: data_ov002_0216cb48.
// Menu grid layout by state ID; state 255 terminates the scan. SelectTableDrivenPanelLayout scans with a seven-byte stride and copies the unsigned dimensions, signed offsets and cell dimensions into the menu.
// Initial values: hex 010c080e060a0e030c0809080a10020c0a09040a0d040c0809080a0d050c0812100a0d060c04090a0a0d070c0809010a0d08070409040a0d090c0809010a0d0a ...; full span in module reference.
// Observed span: 318 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" const MenuGridLayout PartyMenuConfigurePanelLayout_MenuGridLayoutByStateID[45] = {
    { 1, 12, 8, 14, 6, 10, 14 },
    { 3, 12, 8, 9, 8, 10, 16 },
    { 2, 12, 10, 9, 4, 10, 13 },
    { 4, 12, 8, 9, 8, 10, 13 },
    { 5, 12, 8, 18, 16, 10, 13 },
    { 6, 12, 4, 9, 10, 10, 13 },
    { 7, 12, 8, 9, 1, 10, 13 },
    { 8, 7, 4, 9, 4, 10, 13 },
    { 9, 12, 8, 9, 1, 10, 13 },
    { 10, 12, 8, 18, 16, 10, 13 },
    { 11, 12, 8, 9, 1, 10, 13 },
    { 12, 12, 10, 1, 1, 10, 13 },
    { 13, 12, 8, 18, 16, 10, 13 },
    { 14, 12, 10, 9, 1, 10, 13 },
    { 15, 1, 1, 8, 18, 10, 1 },
    { 16, 12, 8, 9, 6, 10, 14 },
    { 17, 12, 8, 16, 16, 10, 13 },
    { 18, 5, 6, 16, 7, 10, 12 },
    { 19, 7, 4, 9, 4, 10, 13 },
    { 20, 12, 6, 15, 14, 10, 13 },
    { 21, 12, 8, 12, 19, 10, 14 },
    { 22, 7, 4, 12, 10, 10, 12 },
    { 24, 4, 9, 30, 1, 10, 13 },
    { 25, 12, 8, 15, 12, 10, 14 },
    { 26, 11, 4, 16, 9, 10, 12 },
    { 27, 6, 8, 14, 11, 10, 12 },
    { 28, 0, 0, 17, 17, 0, 0 },
    { 29, 6, 4, 9, 9, 10, 11 },
    { 30, 1, 1, 1, 1, 1, 1 },
    { 31, 11, 8, 9, 1, 10, 13 },
    { 32, 11, 3, 1, 1, 10, 13 },
    { 33, 24, 5, 19, 21, 10, 13 },
    { 34, 12, 7, 28, 19, 10, 16 },
    { 35, 12, 7, 30, 9, 10, 13 },
    { 36, 8, 14, 32, 8, 10, 12 },
    { 37, 12, 10, 1, 1, 10, 13 },
    { 38, 8, 16, 32, 9, 12, 14 },
    { 40, 8, 4, 10, 4, 8, 9 },
    { 41, 8, 2, 10, 2, 8, 9 },
    { 44, 1, 1, 8, 18, 10, 1 },
    { 45, 1, 1, 8, 18, 10, 1 },
    { 46, 1, 1, 8, 18, 10, 1 },
    { 47, 1, 1, 8, 18, 10, 1 },
    { 39, 12, 10, 1, 1, 10, 13 },
    { 255, 1, 1, 1, 1, 1, 1 },
};
