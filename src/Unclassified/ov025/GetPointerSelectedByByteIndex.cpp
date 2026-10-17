#pragma thumb off
// Field layout is established by instructions; object semantics remain uncertain.
// Original: arm9/ov025 @ 0x021E8A54; symbol: func_ov025_021e8a54; size: 0x10.
extern "C" void* GetPointerSelectedByByteIndex(char* obj) {
    return ((void**)(obj+16))[(unsigned char)obj[48]];
}
