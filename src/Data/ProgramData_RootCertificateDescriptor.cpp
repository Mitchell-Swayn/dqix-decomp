// Original data: arm9/ov031 @ 0x2249930; symbol: data_ov031_02249930.
// Root certification authority descriptor. RSA integer buffers use big-endian octets.
// Observed values: hex 5099240280000000749924020300000024992402.
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
extern char ProgramData_TextJPTokyoShinjyukuSQEXRootCA[];
// Original data: arm9/ov031 @ 0x2249974; symbol: data_ov031_02249974.
// JP, Tokyo, Shinjyuku, SQEX, Root CA RSA public modulus, big-endian octets. Active length 128 bytes.
// Initial values: hex dc822e2d12a58e6eda4c6400aebb60889a9a4dc9dbd136b305170027d30338444bbac4aef00d33e0f5b9d501ca90258ffa92f305b06f9e80f4b10b7ff2e625a2 ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateJPTokyoShinjyukuSQEXRootCAPublicModulus[];
// Original data: arm9/ov031 @ 0x2249924; symbol: data_ov031_02249924.
// JP, Tokyo, Shinjyuku, SQEX, Root CA RSA public exponent 65537 (01 00 01), followed by zero alignment byte.
// Initial values: hex 01000100.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateJPTokyoShinjyukuSQEXRootCAPublicExponent[];
WifiRootCertificate ProgramData_RootCertificateDescriptor = {
    ProgramData_TextJPTokyoShinjyukuSQEXRootCA, 128, SharedData_CertificateJPTokyoShinjyukuSQEXRootCAPublicModulus, 3, SharedData_CertificateJPTokyoShinjyukuSQEXRootCAPublicExponent
};
}
