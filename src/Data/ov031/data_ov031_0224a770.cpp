// Root certification authority descriptor. RSA integer buffers use big-endian octets.
struct WifiRootCertificate {
    const char *authorityName;
    unsigned int modulusLength;
    const unsigned char *modulus;
    unsigned int exponentLength;
    const unsigned char *exponent;
};
extern "C" {
extern char data_ov031_0224a784[];
extern unsigned char data_ov031_0224a7d4[];
extern unsigned char data_ov031_0224a76c[];
WifiRootCertificate data_ov031_0224a770 = {
    data_ov031_0224a784, 128, data_ov031_0224a7d4, 3, data_ov031_0224a76c
};
}
