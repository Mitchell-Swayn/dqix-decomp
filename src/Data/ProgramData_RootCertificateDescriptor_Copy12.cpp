// Original data: arm9/ov031 @ 0x224ae4c; symbol: data_ov031_0224ae4c.
// Root certification authority descriptor. RSA integer buffers use big-endian octets.
// Observed values: hex 60ae24027d000000a4ae24020300000048ae2402.
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
extern char ProgramData_TextUSRSADataSecurityIncSecureServerCertificationAuthority[];
// Original data: arm9/ov031 @ 0x224aea4; symbol: data_ov031_0224aea4.
// US, RSA Data Security, Inc., Secure Server Certification Authority RSA public modulus, big-endian octets. Active length 125 bytes.
// Initial values: hex 92ce7ac1ae833e5aaa898357ac2501760cadae8e2c37ceeb3578645403e5844051c9bf8f08e28a8208d216863755e9b12102ad7668819a05a24bc94b25662256 ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateUSRSADataSecurityIncSecureServerCertificationAuthorityPublicModulus[];
// Original data: arm9/ov031 @ 0x224ae48; symbol: data_ov031_0224ae48.
// US, RSA Data Security, Inc., Secure Server Certification Authority RSA public exponent 65537 (01 00 01), followed by zero alignment byte.
// Initial values: hex 01000100.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateUSRSADataSecurityIncSecureServerCertificationAuthorityPublicExponent[];
WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy12 = {
    ProgramData_TextUSRSADataSecurityIncSecureServerCertificationAuthority, 125, SharedData_CertificateUSRSADataSecurityIncSecureServerCertificationAuthorityPublicModulus, 3, SharedData_CertificateUSRSADataSecurityIncSecureServerCertificationAuthorityPublicExponent
};
}
