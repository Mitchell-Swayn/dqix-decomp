// Original data: arm9/ov031 @ 0x224af28; symbol: data_ov031_0224af28.
// Root certification authority descriptor. RSA integer buffers use big-endian octets.
// Observed values: hex 3caf2402000100006caf24020300000024af2402.
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
extern char ProgramData_TextGlobalSignRootCAR2GlobalSignGlobalSign[];
// Original data: arm9/ov031 @ 0x224af6c; symbol: data_ov031_0224af6c.
// GlobalSign Root CA - R2, GlobalSign, GlobalSign RSA public modulus, big-endian octets. Active length 256 bytes.
// Initial values: hex a6cf240ebe2e6f28994542c4ab3e21549b0bd37f8470fa12b3cbbf875fc67f86d3b2305cd6fdadf17bdce5f86096099210f5d053defb7b7e7388ac52887b4aa6 ...; full span in module reference.
// Observed span: 256 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateGlobalSignRootCAR2GlobalSignGlobalSignPublicModulus[];
// Original data: arm9/ov031 @ 0x224af24; symbol: data_ov031_0224af24.
// GlobalSign Root CA - R2, GlobalSign, GlobalSign RSA public exponent 65537 (01 00 01), followed by zero alignment byte.
// Initial values: hex 01000100.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateGlobalSignRootCAR2GlobalSignGlobalSignPublicExponent[];
WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy13 = {
    ProgramData_TextGlobalSignRootCAR2GlobalSignGlobalSign, 256, SharedData_CertificateGlobalSignRootCAR2GlobalSignGlobalSignPublicModulus, 3, SharedData_CertificateGlobalSignRootCAR2GlobalSignGlobalSignPublicExponent
};
}
