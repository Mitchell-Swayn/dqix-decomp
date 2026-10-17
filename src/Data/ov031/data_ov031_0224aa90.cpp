// Root certification authority descriptor. RSA integer buffers use big-endian octets.
struct WifiRootCertificate {
    const char *authorityName;
    unsigned int modulusLength;
    const unsigned char *modulus;
    unsigned int exponentLength;
    const unsigned char *exponent;
};
extern "C" {
extern char data_ov031_0224ab24[];
extern unsigned char data_ov031_0224aaa4[];
extern unsigned char data_ov031_0224aa8c[];
WifiRootCertificate data_ov031_0224aa90 = {
    data_ov031_0224ab24, 128, data_ov031_0224aaa4, 3, data_ov031_0224aa8c
};
}
