// Original data: arm9/ov031 @ 0x224a858; symbol: data_ov031_0224a858.
// Root certification authority descriptor. RSA integer buffers use big-endian octets.
// Observed values: hex eca82402800000006ca824020300000054a82402.
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
extern char ProgramData_TextZAWesternCapeCapeTownThawteConsultingCcCertificationServicesDivisionThawtePremiumServerCAPremiumText[];
// Original data: arm9/ov031 @ 0x224a86c; symbol: data_ov031_0224a86c.
// ZA, Western Cape, Cape Town, Thawte Consulting cc, Certification Services Division, Thawte Premium Server CA, premium-server@thawte.com RSA public modulus, big-endian octets. Active length 128 bytes.
// Initial values: hex d236366a8bd7c25b9eda8141628f38ee490455d6d0ef1c1b951647ef1848353a52f42b6a068f3b2fea56e3af868d9e17f79eb46575024defcb09a22151d89bd0 ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateZAWesternCapeCapeTownThawteConsultingCcCertificationServicesDivisionThawtePremiumServPublicModulus[];
// Original data: arm9/ov031 @ 0x224a854; symbol: data_ov031_0224a854.
// ZA, Western Cape, Cape Town, Thawte Consulting cc, Certification Services Division, Thawte Premium Server CA, premium-server@thawte.com RSA public exponent 65537 (01 00 01), followed by zero alignment byte.
// Initial values: hex 01000100.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateZAWesternCapeCapeTownThawteConsultingCcCertificationServicesDivisionThawtePremiumServPublicExponent[];
WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy7 = {
    ProgramData_TextZAWesternCapeCapeTownThawteConsultingCcCertificationServicesDivisionThawtePremiumServerCAPremiumText, 128, SharedData_CertificateZAWesternCapeCapeTownThawteConsultingCcCertificationServicesDivisionThawtePremiumServPublicModulus, 3, SharedData_CertificateZAWesternCapeCapeTownThawteConsultingCcCertificationServicesDivisionThawtePremiumServPublicExponent
};
}
