// Root certification authority descriptor. RSA integer buffers use big-endian octets.
struct WifiRootCertificate {
    const char *authorityName;
    unsigned int modulusLength;
    const unsigned char *modulus;
    unsigned int exponentLength;
    const unsigned char *exponent;
};
extern "C" {
extern char data_ov031_0224a5d8[];
extern unsigned char data_ov031_0224a628[];
extern unsigned char data_ov031_0224a5c0[];
WifiRootCertificate data_ov031_0224a5c4 = {
    data_ov031_0224a5d8, 128, data_ov031_0224a628, 3, data_ov031_0224a5c0
};
}
