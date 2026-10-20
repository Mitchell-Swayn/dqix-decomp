extern "C" { void Window_ResetResourceTransfers(void*); void RefreshPackedTextUnlessModeSuppressesIt(void*); }
struct Overlay8Activity { unsigned char unknown[0xe99]; signed char first; unsigned char unknownE9a; signed char second; unsigned char unknownE9c[0x24]; unsigned char active : 1; unsigned char remaining : 7; };
// Original: arm9/ov008 @ 0x0218946C; symbol: func_ov008_0218946c; size: 0x4C.
extern "C" void PartyTalk_RefreshProfileSessionRendering(Overlay8Activity* object) {
    if (object->first) Window_ResetResourceTransfers((unsigned char*)object+0x18);
    if (object->second && object->active) RefreshPackedTextUnlessModeSuppressesIt((unsigned char*)object+0x2a8);
}
