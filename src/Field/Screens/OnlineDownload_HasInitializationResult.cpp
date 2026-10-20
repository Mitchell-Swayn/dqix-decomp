// ReadNestedByte439OrZero: describes the directly observed offset-level operation; field roles remain unknown.
// Original: arm9/ov017 @ 0x021B2060; symbol: func_ov017_021b2060; size: 0x14.
extern "C" unsigned int OnlineDownload_HasInitializationResult(void* object)
{
    unsigned char* nested = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x24);
    return nested ? nested[0x439] : 0;
}
