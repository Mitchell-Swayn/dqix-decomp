// Numeric keyboard key origins; 10 keys, four-byte stride. Graphics_UpdateTouchSelectionFromThreeButtonGroups iterates 10 entries.
// Negative navigation values are special fallback destinations handled by the consumer.
struct KeyboardKeyOrigin { unsigned short x; unsigned short y; };
extern "C" const KeyboardKeyOrigin data_ov031_02248cda[10] = {
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
