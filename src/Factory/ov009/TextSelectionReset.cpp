// Eight selection indices; paired indices are reset in the observed order.
struct TextSelectionIndices {
    int first[2];
    int second[2];
    int remaining[4];
};

extern "C" void func_ov009_021847c4(TextSelectionIndices* indices)
{
    indices->first[1] = -1;
    indices->first[0] = -1;
    indices->second[1] = -1;
    indices->second[0] = -1;
    indices->remaining[0] = -1;
    indices->remaining[1] = -1;
    indices->remaining[2] = -1;
    indices->remaining[3] = -1;
}
