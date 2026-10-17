// Root certification authority descriptor. RSA integer buffers use big-endian octets.
struct WifiRootCertificate {
    const char *authorityName;
    unsigned int modulusLength;
    const unsigned char *modulus;
    unsigned int exponentLength;
    const unsigned char *exponent;
};
extern "C" {
extern char data_ov031_02249950[];
extern unsigned char data_ov031_02249974[];
extern unsigned char data_ov031_02249924[];
WifiRootCertificate data_ov031_02249930 = {
    data_ov031_02249950, 128, data_ov031_02249974, 3, data_ov031_02249924
};
}
