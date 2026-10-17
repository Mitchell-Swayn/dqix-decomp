extern "C" { void ResetEachIndexedEntryResource(void*); void func_ov008_02184968(void*); }
struct Overlay8Activity { unsigned char unknown[0xe99]; signed char first; unsigned char unknownE9a; signed char second; unsigned char unknownE9c[0x24]; unsigned char active : 1; unsigned char remaining : 7; };
// Original: arm9/ov008 @ 0x0218946C; symbol: func_ov008_0218946c; size: 0x4C.
extern "C" void func_ov008_0218946c(Overlay8Activity* object) {
    if (object->first) ResetEachIndexedEntryResource((unsigned char*)object+0x18);
    if (object->second && object->active) func_ov008_02184968((unsigned char*)object+0x2a8);
}
