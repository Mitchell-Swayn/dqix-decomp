#pragma thumb off
// Field layout is established by instructions; object semantics remain uncertain.
// Original: arm9/ov000 @ 0x02159EAC; symbol: func_ov000_02159eac; size: 0x6c.
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long* mask,unsigned bit) {
    if(bit>31)*mask |= ((unsigned long long)(1 << (bit-31)) <<32) & 0xffffffff00000000ULL;
    else *mask |= ((unsigned long long)(1 << bit)) & 0xffffffffULL;
}
