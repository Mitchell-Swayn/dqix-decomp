// Original data: arm9/ov031 @ 0x224ad70; symbol: data_ov031_0224ad70.
// Root certification authority descriptor. RSA integer buffers use big-endian octets.
// Observed values: hex 84ad240280000000c8ad2402030000006cad2402.
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
extern char ProgramData_TextUSVeriSignIncClass3PublicPrimaryCertificationAuthority[];
// Original data: arm9/ov031 @ 0x224adc8; symbol: data_ov031_0224adc8.
// US, VeriSign, Inc., Class 3 Public Primary Certification Authority RSA public modulus, big-endian octets. Active length 128 bytes.
// Initial values: hex c95c599ef21b8a0114b410df0440dbe357af6a45408f840c0bd133d9d911cfee02581f25f72aa84405aaec031f787f9e93b99a00aa237dd6ac85a26345c77227 ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateUSVeriSignIncClass3PublicPrimaryCertificationAuthorityPublicModulus[];
// Original data: arm9/ov031 @ 0x224ad6c; symbol: data_ov031_0224ad6c.
// US, VeriSign, Inc., Class 3 Public Primary Certification Authority RSA public exponent 65537 (01 00 01), followed by zero alignment byte.
// Initial values: hex 01000100.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateUSVeriSignIncClass3PublicPrimaryCertificationAuthorityPublicExponent[];
WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy11 = {
    ProgramData_TextUSVeriSignIncClass3PublicPrimaryCertificationAuthority, 128, SharedData_CertificateUSVeriSignIncClass3PublicPrimaryCertificationAuthorityPublicModulus, 3, SharedData_CertificateUSVeriSignIncClass3PublicPrimaryCertificationAuthorityPublicExponent
};
}
