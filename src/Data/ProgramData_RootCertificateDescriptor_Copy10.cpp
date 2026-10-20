// Original data: arm9/ov031 @ 0x224abbc; symbol: data_ov031_0224abbc.
// Root certification authority descriptor. RSA integer buffers use big-endian octets.
// Observed values: hex d0ab2402000100006cac240203000000b8ab2402.
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
extern char ProgramData_TextUSVeriSignIncVeriSignTrustNetworkC1999VeriSignIncForAuthorizedUseOnlyVeriSignClass3PublicPrimaryText[];
// Original data: arm9/ov031 @ 0x224ac6c; symbol: data_ov031_0224ac6c.
// US, VeriSign, Inc., VeriSign Trust Network, (c) 1999 VeriSign, Inc. - For authorized use only, VeriSign Class 3 Public Primary Certification Authority - G3 RSA public modulus, big-endian octets. Active length 256 bytes.
// Initial values: hex cbba9c52fc781f1a1e6f1b3773bdf8c96b9412304ff03647f5d0910af517c8a561c116404dfb8a6190e57620c111067dab2c6ea6f511418efa2dad2a6159a467 ...; full span in module reference.
// Observed span: 256 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateUSVeriSignIncVeriSignTrustNetworkC1999VeriSignIncForAuthorizedUseOnlyVeriSignClass3PuPublicModulus[];
// Original data: arm9/ov031 @ 0x224abb8; symbol: data_ov031_0224abb8.
// US, VeriSign, Inc., VeriSign Trust Network, (c) 1999 VeriSign, Inc. - For authorized use only, VeriSign Class 3 Public Primary Certification Authority - G3 RSA public exponent 65537 (01 00 01), followed by zero alignment byte.
// Initial values: hex 01000100.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateUSVeriSignIncVeriSignTrustNetworkC1999VeriSignIncForAuthorizedUseOnlyVeriSignClass3PuPublicExponent[];
WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy10 = {
    ProgramData_TextUSVeriSignIncVeriSignTrustNetworkC1999VeriSignIncForAuthorizedUseOnlyVeriSignClass3PublicPrimaryText, 256, SharedData_CertificateUSVeriSignIncVeriSignTrustNetworkC1999VeriSignIncForAuthorizedUseOnlyVeriSignClass3PuPublicModulus, 3, SharedData_CertificateUSVeriSignIncVeriSignTrustNetworkC1999VeriSignIncForAuthorizedUseOnlyVeriSignClass3PuPublicExponent
};
}
