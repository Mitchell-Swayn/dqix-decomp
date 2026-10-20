// Stores one to byte field 1 of the supplied object.
// Original: arm9/ov017 @ 0x021A7C1C; symbol: func_ov017_021a7c1c; size: 0x0C.
extern "C" void Field_CompleteDeferredActorRequest(void* object) {
    ((volatile unsigned char*)object)[1] = 1;
}
