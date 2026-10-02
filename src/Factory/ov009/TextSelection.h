#ifndef FACTORY_OV009_TEXT_SELECTION_H
#define FACTORY_OV009_TEXT_SELECTION_H

// Eight selection indices; paired indices are reset in the observed order.
struct TextSelectionIndices {
    int first[2];
    int second[2];
    int remaining[4];
};

typedef char TextSelectionSizeCheck[sizeof(TextSelectionIndices) == 0x20 ? 1 : -1];
extern "C" void func_ov009_021847c4(TextSelectionIndices* indices);

#endif
