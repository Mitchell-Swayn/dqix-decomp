#pragma thumb off
// Field layout is established by instructions; object semantics remain uncertain.
extern "C" signed char* data_ov031_02250ba8;
// Original: arm9/ov031 @ 0x02222E0C; symbol: func_ov031_02222e0c; size: 0x14.
extern "C" int ReadSharedSignedByteAtOffset22() {
    return data_ov031_02250ba8[22];
}
