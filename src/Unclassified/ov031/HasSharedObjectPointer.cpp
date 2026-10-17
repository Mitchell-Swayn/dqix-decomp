#pragma thumb off
// Field layout is established by instructions; object semantics remain uncertain.
extern "C" void* data_ov031_02290d10;
// Original: arm9/ov031 @ 0x02237EB0; symbol: func_ov031_02237eb0; size: 0x1c.
extern "C" int HasSharedObjectPointer() {
    return data_ov031_02290d10!=0;
}
