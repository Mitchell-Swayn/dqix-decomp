// Numeric keyboard key origins; 10 keys, four-byte stride. Graphics_UpdateTouchSelectionFromThreeButtonGroups iterates 10 entries.
// Negative navigation values are special fallback destinations handled by the consumer.
struct KeyboardKeyOrigin { unsigned short x; unsigned short y; };
// Original data: arm9/ov031 @ 0x2248cda; symbol: data_ov031_02248cda.
// Numeric keyboard key origins; 10 keys, four-byte stride. Graphics_UpdateTouchSelectionFromThreeButtonGroups iterates 10 entries. Negative navigation values are special fallback destinations handled by the consumer.
// Initial values: hex 52004c0072004c0092004c0052006300720063009200630052007a0072007a0092007a0052009100.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" const KeyboardKeyOrigin WfcNumberPadLayoutRow_NumericKeyboardKeyOrigins[10] = {
    { 82, 76 },
    { 114, 76 },
    { 146, 76 },
    { 82, 99 },
    { 114, 99 },
    { 146, 99 },
    { 82, 122 },
    { 114, 122 },
    { 146, 122 },
    { 82, 145 },
};
