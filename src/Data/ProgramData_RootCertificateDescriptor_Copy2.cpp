// Original data: arm9/ov031 @ 0x224a328; symbol: data_ov031_0224a328.
// Root certification authority descriptor. RSA integer buffers use big-endian octets.
// Observed values: hex 3ca324020001000070a324020300000024a32402.
// Span: 20 bytes to next configured symbol; logical object size may differ.
// Root certification authority descriptor. RSA integer buffers use big-endian octets.
struct WifiRootCertificate {
    const char *authorityName;
    unsigned int modulusLength;
    const unsigned char *modulus;
    unsigned int exponentLength;
    const unsigned char *exponent;
};
extern "C" {
extern char ProgramData_TextBEGlobalSignNvSaRootCAGlobalSignRootCA[];
// Original data: arm9/ov031 @ 0x224a370; symbol: data_ov031_0224a370.
// BE, GlobalSign nv-sa, Root CA, GlobalSign Root CA RSA public modulus, big-endian octets. Active length 256 bytes.
// Initial values: hex da0ee6998dcea3e34f8a7efbf18b83256bea481ff12ab0b9951104bdf063d1e26766cf1cddcf1b482bee8d898e9aaf298065abe9c72d12cbab1c4c7007a13d0a ...; full span in module reference.
// Observed span: 256 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateBEGlobalSignNvSaRootCAGlobalSignRootCAPublicModulus[];
// Original data: arm9/ov031 @ 0x224a324; symbol: data_ov031_0224a324.
// BE, GlobalSign nv-sa, Root CA, GlobalSign Root CA RSA public exponent 65537 (01 00 01), followed by zero alignment byte.
// Initial values: hex 01000100.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateBEGlobalSignNvSaRootCAGlobalSignRootCAPublicExponent[];
WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy2 = {
    ProgramData_TextBEGlobalSignNvSaRootCAGlobalSignRootCA, 256, SharedData_CertificateBEGlobalSignNvSaRootCAGlobalSignRootCAPublicModulus, 3, SharedData_CertificateBEGlobalSignNvSaRootCAGlobalSignRootCAPublicExponent
};
}
