extern "C" { void ClearEachIndexedEntryResource(void*); void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void*); void func_0205da88(void*,int,int,int); void Graphics_ResetCountedThirtyTwoByteTransfers(void*); void func_ov008_0218aee4(void*); void func_ov008_02184878(void*); }
struct Overlay8Activity { unsigned char unknown[0xe9b]; signed char second; unsigned char unknownE9c[0x24]; unsigned char active : 1; unsigned char remaining : 7; };
// Original: arm9/ov008 @ 0x02189404; symbol: func_ov008_02189404; size: 0x68.
extern "C" void func_ov008_02189404(Overlay8Activity* object) {
    unsigned char* base=(unsigned char*)object;
    ClearEachIndexedEntryResource(base+0x18); ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(base+0x18); func_0205da88(base+0x18,1,2,1); Graphics_ResetCountedThirtyTwoByteTransfers(base+0x18);
    func_ov008_0218aee4(object);
    if(object->second && object->active) func_ov008_02184878(base+0x2a8);
}
