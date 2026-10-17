// Root certification authority descriptor. RSA integer buffers use big-endian octets.
struct WifiRootCertificate {
    const char *authorityName;
    unsigned int modulusLength;
    const unsigned char *modulus;
    unsigned int exponentLength;
    const unsigned char *exponent;
};
extern "C" {
extern char data_ov031_0224ae60[];
extern unsigned char data_ov031_0224aea4[];
extern unsigned char data_ov031_0224ae48[];
WifiRootCertificate data_ov031_0224ae4c = {
    data_ov031_0224ae60, 125, data_ov031_0224aea4, 3, data_ov031_0224ae48
};
}
