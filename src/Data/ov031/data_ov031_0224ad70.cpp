// Root certification authority descriptor. RSA integer buffers use big-endian octets.
struct WifiRootCertificate {
    const char *authorityName;
    unsigned int modulusLength;
    const unsigned char *modulus;
    unsigned int exponentLength;
    const unsigned char *exponent;
};
extern "C" {
extern char data_ov031_0224ad84[];
extern unsigned char data_ov031_0224adc8[];
extern unsigned char data_ov031_0224ad6c[];
WifiRootCertificate data_ov031_0224ad70 = {
    data_ov031_0224ad84, 128, data_ov031_0224adc8, 3, data_ov031_0224ad6c
};
}
