// Root certification authority descriptor. RSA integer buffers use big-endian octets.
struct WifiRootCertificate {
    const char *authorityName;
    unsigned int modulusLength;
    const unsigned char *modulus;
    unsigned int exponentLength;
    const unsigned char *exponent;
};
extern "C" {
extern char data_ov031_0224a6c0[];
extern unsigned char data_ov031_0224a6ec[];
extern unsigned char data_ov031_0224a6a8[];
WifiRootCertificate data_ov031_0224a6ac = {
    data_ov031_0224a6c0, 128, data_ov031_0224a6ec, 3, data_ov031_0224a6a8
};
}
