// Root certification authority descriptor. RSA integer buffers use big-endian octets.
struct WifiRootCertificate {
    const char *authorityName;
    unsigned int modulusLength;
    const unsigned char *modulus;
    unsigned int exponentLength;
    const unsigned char *exponent;
};
extern "C" {
extern char data_ov031_0224a33c[];
extern unsigned char data_ov031_0224a370[];
extern unsigned char data_ov031_0224a324[];
WifiRootCertificate data_ov031_0224a328 = {
    data_ov031_0224a33c, 256, data_ov031_0224a370, 3, data_ov031_0224a324
};
}
