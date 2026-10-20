// Original data: arm9/ov031 @ 0x2249d84; symbol: data_ov031_02249d84.
// Trust store entries in verification order.
// Initial values: hex bcab240290aa240270ad24024cae240228a32402c4a52402aca6240274a4240278a9240258a8240228af240270a72402.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Trust store entries in verification order.
struct WifiRootCertificate { const char *authorityName; unsigned int modulusLength; const unsigned char *modulus; unsigned int exponentLength; const unsigned char *exponent; };
extern "C" {
extern WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy2;
extern WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy3;
extern WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy4;
extern WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy5;
extern WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy6;
extern WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy7;
extern WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy8;
extern WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy9;
extern WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy10;
extern WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy11;
extern WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy12;
extern WifiRootCertificate ProgramData_RootCertificateDescriptor_Copy13;
const WifiRootCertificate *HttpDownloadRunRequestTransfer_TrustStoreEntriesInVerificationOrder[12] = {
    &ProgramData_RootCertificateDescriptor_Copy10,
    &ProgramData_RootCertificateDescriptor_Copy9,
    &ProgramData_RootCertificateDescriptor_Copy11,
    &ProgramData_RootCertificateDescriptor_Copy12,
    &ProgramData_RootCertificateDescriptor_Copy2,
    &ProgramData_RootCertificateDescriptor_Copy4,
    &ProgramData_RootCertificateDescriptor_Copy5,
    &ProgramData_RootCertificateDescriptor_Copy3,
    &ProgramData_RootCertificateDescriptor_Copy8,
    &ProgramData_RootCertificateDescriptor_Copy7,
    &ProgramData_RootCertificateDescriptor_Copy13,
    &ProgramData_RootCertificateDescriptor_Copy6,
};
}
