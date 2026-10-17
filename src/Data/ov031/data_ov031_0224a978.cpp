// Root certification authority descriptor. RSA integer buffers use big-endian octets.
struct WifiRootCertificate {
    const char *authorityName;
    unsigned int modulusLength;
    const unsigned char *modulus;
    unsigned int exponentLength;
    const unsigned char *exponent;
};
extern "C" {
extern char data_ov031_0224a98c[];
extern unsigned char data_ov031_0224aa0c[];
extern unsigned char data_ov031_0224a974[];
WifiRootCertificate data_ov031_0224a978 = {
    data_ov031_0224a98c, 128, data_ov031_0224aa0c, 3, data_ov031_0224a974
};
}
