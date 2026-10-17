// Numeric keyboard navigation: 14 keys with four signed destinations, plus two zero alignment bytes. func_ov031_02226a64 indexes key*4+direction and ldrsb.
// Negative navigation values are special fallback destinations handled by the consumer.
struct NumericKeyboardNavigation { signed char destinations[14][4]; unsigned short alignmentPadding; };
extern "C" const NumericKeyboardNavigation data_ov031_02248d3a = { {
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
