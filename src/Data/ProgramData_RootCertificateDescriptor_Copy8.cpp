// Original data: arm9/ov031 @ 0x224a978; symbol: data_ov031_0224a978.
// Root certification authority descriptor. RSA integer buffers use big-endian octets.
// Observed values: hex 8ca92402800000000caa24020300000074a92402.
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
extern char ProgramData_TextZAWesternCapeCapeTownThawteConsultingCcCertificationServicesDivisionThawteServerCAServerCertsThaText[];
// Original data: arm9/ov031 @ 0x224aa0c; symbol: data_ov031_0224aa0c.
// ZA, Western Cape, Cape Town, Thawte Consulting cc, Certification Services Division, Thawte Server CA, server-certs@thawte.com RSA public modulus, big-endian octets. Active length 128 bytes.
// Initial values: hex d3a4506ec8ff566be6cf5db6ea0c687547a2aac2da8425fca8f44751da85b5207494861e0f75c9e90861f5066d306e151902e952c062db4d999ee26a0c4438cd ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateZAWesternCapeCapeTownThawteConsultingCcCertificationServicesDivisionThawteServerCASerPublicModulus[];
// Original data: arm9/ov031 @ 0x224a974; symbol: data_ov031_0224a974.
// ZA, Western Cape, Cape Town, Thawte Consulting cc, Certification Services Division, Thawte Server CA, server-certs@thawte.com RSA public exponent 65537 (01 00 01), followed by zero alignment byte.
// Initial values: hex 01000100.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char SharedData_CertificateZAWesternCapeCapeTownThawteConsultingCcCertificationServicesDivisionThawteServerCASerPublicExponent[];
WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy8 = {
    ProgramData_TextZAWesternCapeCapeTownThawteConsultingCcCertificationServicesDivisionThawteServerCAServerCertsThaText, 128, SharedData_CertificateZAWesternCapeCapeTownThawteConsultingCcCertificationServicesDivisionThawteServerCASerPublicModulus, 3, SharedData_CertificateZAWesternCapeCapeTownThawteConsultingCcCertificationServicesDivisionThawteServerCASerPublicExponent
};
}
