// Root certification authority descriptor. RSA integer buffers use big-endian octets.
struct WifiRootCertificate {
    const char *authorityName;
    unsigned int modulusLength;
    const unsigned char *modulus;
    unsigned int exponentLength;
    const unsigned char *exponent;
};
extern "C" {
extern char data_ov031_0224a8ec[];
extern unsigned char data_ov031_0224a86c[];
extern unsigned char data_ov031_0224a854[];
WifiRootCertificate data_ov031_0224a858 = {
    data_ov031_0224a8ec, 128, data_ov031_0224a86c, 3, data_ov031_0224a854
};
}
