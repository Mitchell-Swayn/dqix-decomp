// Root certification authority descriptor. RSA integer buffers use big-endian octets.
struct WifiRootCertificate {
    const char *authorityName;
    unsigned int modulusLength;
    const unsigned char *modulus;
    unsigned int exponentLength;
    const unsigned char *exponent;
};
extern "C" {
extern char data_ov031_0224a488[];
extern unsigned char data_ov031_0224a4c0[];
extern unsigned char data_ov031_0224a470[];
WifiRootCertificate data_ov031_0224a474 = {
    data_ov031_0224a488, 256, data_ov031_0224a4c0, 3, data_ov031_0224a470
};
}
