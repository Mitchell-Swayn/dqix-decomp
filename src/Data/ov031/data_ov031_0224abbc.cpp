// Root certification authority descriptor. RSA integer buffers use big-endian octets.
struct WifiRootCertificate {
    const char *authorityName;
    unsigned int modulusLength;
    const unsigned char *modulus;
    unsigned int exponentLength;
    const unsigned char *exponent;
};
extern "C" {
extern char data_ov031_0224abd0[];
extern unsigned char data_ov031_0224ac6c[];
extern unsigned char data_ov031_0224abb8[];
WifiRootCertificate data_ov031_0224abbc = {
    data_ov031_0224abd0, 256, data_ov031_0224ac6c, 3, data_ov031_0224abb8
};
}
