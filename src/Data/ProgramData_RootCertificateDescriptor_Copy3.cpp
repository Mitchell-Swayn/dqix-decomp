// Original data: arm9/ov031 @ 0x224a474; symbol: data_ov031_0224a474.
// Root certification authority descriptor. RSA integer buffers use big-endian octets.
// Observed values: hex 88a4240200010000c0a424020300000070a42402.
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
extern char ProgramData_TextIEBaltimoreCyberTrustBaltimoreCyberTrustRoot[];
// Original data: arm9/ov031 @ 0x224a4c0; symbol: data_ov031_0224a4c0.
// IE, Baltimore, CyberTrust, Baltimore CyberTrust Root RSA public modulus, big-endian octets. Active length 256 bytes.
// Initial values: hex a304bb22ab983d57e826729ab579d429e2e1e89580b1b0e35b8e2b299a64dfa15dedb009056ddb282ece62a262feb488da12eb38eb219dc0412b01527b8877d3 ...; full span in module reference.
// Observed span: 256 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateIEBaltimoreCyberTrustBaltimoreCyberTrustRootPublicModulus[];
// Original data: arm9/ov031 @ 0x224a470; symbol: data_ov031_0224a470.
// IE, Baltimore, CyberTrust, Baltimore CyberTrust Root RSA public exponent 65537 (01 00 01), followed by zero alignment byte.
// Initial values: hex 01000100.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateIEBaltimoreCyberTrustBaltimoreCyberTrustRootPublicExponent[];
WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy3 = {
    ProgramData_TextIEBaltimoreCyberTrustBaltimoreCyberTrustRoot, 256, SharedData_CertificateIEBaltimoreCyberTrustBaltimoreCyberTrustRootPublicModulus, 3, SharedData_CertificateIEBaltimoreCyberTrustBaltimoreCyberTrustRootPublicExponent
};
}
