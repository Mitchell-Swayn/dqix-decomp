// InitializeRecordKind06AndFiveWords; field roles are uncertain, so the name describes the recorded initialization only.
extern "C" void InitializeFourWordsWithInvalidIndex(void*);
// Original: arm9/ov017 @ 0x021AB250; symbol: func_ov017_021ab250; size: 0x30.
extern "C" void InitializeRecordKind06AndFiveWords(void* object) {
    unsigned char* p = static_cast<unsigned char*>(object);
    InitializeFourWordsWithInvalidIndex(object);
    p[0] = 6;
    *reinterpret_cast<unsigned int*>(p + 8) = 0;
    *reinterpret_cast<unsigned int*>(p + 12) = 0;
    *reinterpret_cast<unsigned int*>(p + 20) = 0;
    *reinterpret_cast<unsigned int*>(p + 24) = 0;
    *reinterpret_cast<unsigned int*>(p + 28) = 0;
}
