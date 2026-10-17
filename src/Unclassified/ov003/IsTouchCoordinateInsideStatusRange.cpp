// Uses touch state and selected coordinate outputs to classify two observed numeric intervals; semantic meaning is unknown.
extern "C" unsigned char data_02114e54[];
extern "C" unsigned int ReadSelectedCoordinatePair(void*, int*, int*);
// Original: arm9/ov003 @ 0x02178218; symbol: func_ov003_02178218; size: 0x88.
extern "C" int IsTouchCoordinateInsideStatusRange(void)
{
    int first;
    int second;
    unsigned int* state = (unsigned int*)data_02114e54;
    if (!data_02114e54[0x5f] || *(unsigned short*)(data_02114e54 + 0x24) == 0)
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
