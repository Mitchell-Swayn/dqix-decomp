// Original data: arm9/ov031 @ 0x224a5c4; symbol: data_ov031_0224a5c4.
// Root certification authority descriptor. RSA integer buffers use big-endian octets.
// Observed values: hex d8a524028000000028a6240203000000c0a52402.
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
extern char ProgramData_TextUSGTECorporationGTECyberTrustSolutionsIncGTECyberTrustGlobalRoot[];
// Original data: arm9/ov031 @ 0x224a628; symbol: data_ov031_0224a628.
// US, GTE Corporation, GTE CyberTrust Solutions, Inc., GTE CyberTrust Global Root RSA public modulus, big-endian octets. Active length 128 bytes.
// Initial values: hex 950fa0b6f0509ce87ac788cddd170e2eb094d01b3d0ef694c08a94c706c89097c8b8641a7a7e6c3c53e1372873607fb29753079f53f96d5894d2af8d6d886780 ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateUSGTECorporationGTECyberTrustSolutionsIncGTECyberTrustGlobalRootPublicModulus[];
// Original data: arm9/ov031 @ 0x224a5c0; symbol: data_ov031_0224a5c0.
// US, GTE Corporation, GTE CyberTrust Solutions, Inc., GTE CyberTrust Global Root RSA public exponent 65537 (01 00 01), followed by zero alignment byte.
// Initial values: hex 01000100.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateUSGTECorporationGTECyberTrustSolutionsIncGTECyberTrustGlobalRootPublicExponent[];
WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy4 = {
    ProgramData_TextUSGTECorporationGTECyberTrustSolutionsIncGTECyberTrustGlobalRoot, 128, SharedData_CertificateUSGTECorporationGTECyberTrustSolutionsIncGTECyberTrustGlobalRootPublicModulus, 3, SharedData_CertificateUSGTECorporationGTECyberTrustSolutionsIncGTECyberTrustGlobalRootPublicExponent
};
}
