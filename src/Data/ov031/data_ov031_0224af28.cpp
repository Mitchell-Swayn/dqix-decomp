// Root certification authority descriptor. RSA integer buffers use big-endian octets.
struct WifiRootCertificate {
    const char *authorityName;
    unsigned int modulusLength;
    const unsigned char *modulus;
    unsigned int exponentLength;
    const unsigned char *exponent;
};
extern "C" {
extern char data_ov031_0224af3c[];
extern unsigned char data_ov031_0224af6c[];
extern unsigned char data_ov031_0224af24[];
WifiRootCertificate data_ov031_0224af28 = {
    data_ov031_0224af3c, 256, data_ov031_0224af6c, 3, data_ov031_0224af24
};
}
