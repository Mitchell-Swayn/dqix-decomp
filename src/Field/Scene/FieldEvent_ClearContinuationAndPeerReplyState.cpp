// ClearEmbeddedWordAndHalfwordArrays; field roles are uncertain, so the name describes the recorded initialization only.
extern "C" void* memset(void*, int, unsigned);
// Original: arm9/ov017 @ 0x021BB0C4; symbol: func_ov017_021bb0c4; size: 0x44.
extern "C" void FieldEvent_ClearContinuationAndPeerReplyState(void* object) {
    unsigned char* p = static_cast<unsigned char*>(object);
    p[0xfc] = 0; *reinterpret_cast<unsigned short*>(p + 0x11a) = 0;
    memset(p + 0x13c, 0, 0x12); memset(p + 0x150, 0, 0x0a);
    *reinterpret_cast<unsigned int*>(p + 0x15c) = 0; p[0xfe] = 0;
}
