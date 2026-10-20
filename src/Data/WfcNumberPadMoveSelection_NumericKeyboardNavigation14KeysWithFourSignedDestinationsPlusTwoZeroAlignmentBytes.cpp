// Numeric keyboard navigation: 14 keys with four signed destinations, plus two zero alignment bytes. MoveEffectSelectionThroughTransitionTable indexes key*4+direction and ldrsb.
// Negative navigation values are special fallback destinations handled by the consumer.
struct NumericKeyboardNavigation { signed char destinations[14][4]; unsigned short alignmentPadding; };
// Original data: arm9/ov031 @ 0x2248d3a; symbol: data_ov031_02248d3a.
// Numeric keyboard navigation: 14 keys with four signed destinations, plus two zero alignment bytes. MoveEffectSelectionThroughTransitionTable indexes key*4+direction and ldrsb. Negative navigation values are special fallback destinations handled by the consumer.
// Initial values: hex 020c0103000d0204010d0005050004060301050704020308080307090604080a0705060b0b060a0c09070b0d0a08090d0d090d000cff0cfe0000.
// Observed span: 58 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" const NumericKeyboardNavigation WfcNumberPadMoveSelection_NumericKeyboardNavigation14KeysWithFourSignedDestinationsPlusTwoZeroAlignmentBytes = { {
    { 2, 12, 1, 3 },
    { 0, 13, 2, 4 },
    { 1, 13, 0, 5 },
    { 5, 0, 4, 6 },
    { 3, 1, 5, 7 },
    { 4, 2, 3, 8 },
    { 8, 3, 7, 9 },
    { 6, 4, 8, 10 },
    { 7, 5, 6, 11 },
    { 11, 6, 10, 12 },
    { 9, 7, 11, 13 },
    { 10, 8, 9, 13 },
    { 13, 9, 13, 0 },
    { 12, -1, 12, -2 },
}, 0 };
