// Original data: arm9/ov031 @ 0x224a770; symbol: data_ov031_0224a770.
// Root certification authority descriptor. RSA integer buffers use big-endian octets.
// Observed values: hex 84a7240280000000d4a72402030000006ca72402.
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
extern char ProgramData_TextUSWashingtonNintendoOfAmericaIncNOANintendoCACaNoaNintendoCom[];
// Original data: arm9/ov031 @ 0x224a7d4; symbol: data_ov031_0224a7d4.
// US, Washington, Nintendo of America Inc, NOA, Nintendo CA, ca@noa.nintendo.com RSA public modulus, big-endian octets. Active length 128 bytes.
// Initial values: hex b3cd7997775d8aaf86a8e8d7731c77df10901f81f8419e2155dfbcfc63fb1943f1f6c4724249bdad44684ef3da1de64dd8f95988dcae3e9b3809ca7fffdc24a2 ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateUSWashingtonNintendoOfAmericaIncNOANintendoCACaNoaNintendoComPublicModulus[];
// Original data: arm9/ov031 @ 0x224a76c; symbol: data_ov031_0224a76c.
// US, Washington, Nintendo of America Inc, NOA, Nintendo CA, ca@noa.nintendo.com RSA public exponent 65537 (01 00 01), followed by zero alignment byte.
// Initial values: hex 01000100.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateUSWashingtonNintendoOfAmericaIncNOANintendoCACaNoaNintendoComPublicExponent[];
WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy6 = {
    ProgramData_TextUSWashingtonNintendoOfAmericaIncNOANintendoCACaNoaNintendoCom, 128, SharedData_CertificateUSWashingtonNintendoOfAmericaIncNOANintendoCACaNoaNintendoComPublicModulus, 3, SharedData_CertificateUSWashingtonNintendoOfAmericaIncNOANintendoCACaNoaNintendoComPublicExponent
};
}
