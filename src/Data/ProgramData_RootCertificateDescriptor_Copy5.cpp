// Original data: arm9/ov031 @ 0x224a6ac; symbol: data_ov031_0224a6ac.
// Root certification authority descriptor. RSA integer buffers use big-endian octets.
// Observed values: hex c0a6240280000000eca6240203000000a8a62402.
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
extern char ProgramData_TextUSGTECorporationGTECyberTrustRoot[];
// Original data: arm9/ov031 @ 0x224a6ec; symbol: data_ov031_0224a6ec.
// US, GTE Corporation, GTE CyberTrust Root RSA public modulus, big-endian octets. Active length 128 bytes.
// Initial values: hex b8e64fbadb987c717caf44b7d30f46d964e593c1428ec7ba498d352d7ae78bbde5053159c6b12f0a0cfb9fa73fa2096684561e37291b87e97e0cca9a9fa57ff5 ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateUSGTECorporationGTECyberTrustRootPublicModulus[];
// Original data: arm9/ov031 @ 0x224a6a8; symbol: data_ov031_0224a6a8.
// US, GTE Corporation, GTE CyberTrust Root RSA public exponent 65537 (01 00 01), followed by zero alignment byte.
// Initial values: hex 01000100.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateUSGTECorporationGTECyberTrustRootPublicExponent[];
WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy5 = {
    ProgramData_TextUSGTECorporationGTECyberTrustRoot, 128, SharedData_CertificateUSGTECorporationGTECyberTrustRootPublicModulus, 3, SharedData_CertificateUSGTECorporationGTECyberTrustRootPublicExponent
};
}
