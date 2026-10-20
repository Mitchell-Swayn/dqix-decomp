// Uses touch state and selected coordinate outputs to classify two observed numeric intervals; semantic meaning is unknown.
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
extern "C" unsigned int ReadSelectedCoordinatePair(void*, int*, int*);
// Original: arm9/ov003 @ 0x02178218; symbol: func_ov003_02178218; size: 0x88.
extern "C" int Shop_ReadQuantityArrowTouch(void)
{
    int first;
    int second;
    unsigned int* state = (unsigned int*)Main_UnknownRoleZeroInitializedStorage_Variant4;
    if (!Main_UnknownRoleZeroInitializedStorage_Variant4[0x5f] || *(unsigned short*)(Main_UnknownRoleZeroInitializedStorage_Variant4 + 0x24) == 0)
        return 0;
    ReadSelectedCoordinatePair(state, &first, &second);
    if (first < 0x94 || first > 0xa7)
        return 0;
    if (second >= 0x24 && second <= 0x2d)
        return 1;
    if (second >= 0x30 && second <= 0x39)
        return -1;
    return 0;
}
