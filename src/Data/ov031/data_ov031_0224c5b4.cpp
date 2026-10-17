// Root certification authority descriptor. RSA integer buffers use big-endian octets.
struct WifiRootCertificate {
    const char *authorityName;
    unsigned int modulusLength;
    const unsigned char *modulus;
    unsigned int exponentLength;
    const unsigned char *exponent;
};
extern "C" {
extern char data_ov031_0224c5c8[];
extern unsigned char data_ov031_0224c618[];
extern unsigned char data_ov031_0224c5b0[];
WifiRootCertificate data_ov031_0224c5b4 = {
    data_ov031_0224c5c8, 128, data_ov031_0224c618, 3, data_ov031_0224c5b0
};
}
