// Keyboard cursor origin table, preserved as split symbols. ConfigureEffectSpriteBySignedIndex
// reads x from 0x2248d02 + key*4 and y from 0x2248d04 + key*4.
struct CursorOrigin { unsigned short x, y; };
struct CursorOriginTail { unsigned short firstY; CursorOrigin remaining[13]; };
// Original data: arm9/ov031 @ 0x2248d04; symbol: data_ov031_02248d04.
// Keyboard cursor origin table, preserved as split symbols. ConfigureEffectSpriteBySignedIndex reads x from 0x2248d02 + key*4 and y from 0x2248d04 + key*4.
// Initial values: hex 4a0070004a0090004a0050006100700061009000610050007800700078009000780050008f0070008f0090008f000200a8008200a800.
// Observed span: 54 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" const CursorOriginTail ConfigureEffectSpriteBySignedIndex_KeyboardCursorOriginTablePreservedAsSplitSymbols_Variant2 = { 74, {
    { 112, 74 },
    { 144, 74 },
    { 80, 97 },
    { 112, 97 },
    { 144, 97 },
    { 80, 120 },
    { 112, 120 },
    { 144, 120 },
    { 80, 143 },
    { 112, 143 },
    { 144, 143 },
    { 2, 168 },
    { 130, 168 },
} };
