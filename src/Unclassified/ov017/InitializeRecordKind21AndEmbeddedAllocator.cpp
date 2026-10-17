// InitializeRecordKind21AndEmbeddedAllocator; field roles are uncertain, so the name describes the recorded initialization only.
extern "C" void InitializeFourWordsWithInvalidIndex(void*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
// Original: arm9/ov017 @ 0x021ADC58; symbol: func_ov017_021adc58; size: 0x58.
extern "C" void InitializeRecordKind21AndEmbeddedAllocator(void* object) {
    unsigned char* p = static_cast<unsigned char*>(object);
    InitializeFourWordsWithInvalidIndex(object);
    p[0] = 0x21; p[9] = 0; *reinterpret_cast<unsigned short*>(p + 14) = 0;
    p[10] = 0; p[12] = 0x0f; p[32] = 0; p[33] = 0;
    *reinterpret_cast<unsigned short*>(p + 40) = 0;
    *reinterpret_cast<unsigned int*>(p + 36) = 0;
    *reinterpret_cast<unsigned int*>(p + 20) = 0;
    *reinterpret_cast<unsigned int*>(p + 24) = 0;
    *reinterpret_cast<unsigned int*>(p + 28) = 0;
    p[11] = 0;
    _ZN13SafeAllocator21ResetAllocatorPointerEv(p + 44);
}
