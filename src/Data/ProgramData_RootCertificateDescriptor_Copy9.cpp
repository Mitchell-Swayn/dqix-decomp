// Original data: arm9/ov031 @ 0x224aa90; symbol: data_ov031_0224aa90.
// Root certification authority descriptor. RSA integer buffers use big-endian octets.
// Observed values: hex 24ab240280000000a4aa2402030000008caa2402.
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
extern char ProgramData_TextUSVeriSignIncClass3PublicPrimaryCertificationAuthorityG2C1998VeriSignIncForAuthorizedUseOnlyVeriText[];
// Original data: arm9/ov031 @ 0x224aaa4; symbol: data_ov031_0224aaa4.
// US, VeriSign, Inc., Class 3 Public Primary Certification Authority - G2, (c) 1998 VeriSign, Inc. - For authorized use only, VeriSign Trust Network RSA public modulus, big-endian octets. Active length 128 bytes.
// Initial values: hex cc5ed1115d5c69d0abd3b96a4c991f5998308e168520466d473fd4852084e16db3f8a4ed0cf1170f3bf9a7f925d7c1cf8463f27c63cfa247f2c65b338e644004 ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateUSVeriSignIncClass3PublicPrimaryCertificationAuthorityG2C1998VeriSignIncForAuthorizedPublicModulus[];
// Original data: arm9/ov031 @ 0x224aa8c; symbol: data_ov031_0224aa8c.
// US, VeriSign, Inc., Class 3 Public Primary Certification Authority - G2, (c) 1998 VeriSign, Inc. - For authorized use only, VeriSign Trust Network RSA public exponent 65537 (01 00 01), followed by zero alignment byte.
// Initial values: hex 01000100.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateUSVeriSignIncClass3PublicPrimaryCertificationAuthorityG2C1998VeriSignIncForAuthorizedPublicExponent[];
WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy9 = {
    ProgramData_TextUSVeriSignIncClass3PublicPrimaryCertificationAuthorityG2C1998VeriSignIncForAuthorizedUseOnlyVeriText, 128, SharedData_CertificateUSVeriSignIncClass3PublicPrimaryCertificationAuthorityG2C1998VeriSignIncForAuthorizedPublicModulus, 3, SharedData_CertificateUSVeriSignIncClass3PublicPrimaryCertificationAuthorityG2C1998VeriSignIncForAuthorizedPublicExponent
};
}
