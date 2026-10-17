// Wi-Fi supported-rate conversion table. Network_ExpandWirelessScanRecord tests
// each capabilityMask against supported/basic masks and emits rateCode,
// adding 0x80 when the rate is basic. rateCode uses 500 kbit/s units.
struct WifiRateEntry { unsigned short capabilityMask; unsigned char rateCode; unsigned char padding; };
extern "C" WifiRateEntry data_ov031_0224b0e4[12] = {
    { 0x0001, 2, 0 },
    { 0x0002, 4, 0 },
    { 0x0004, 11, 0 },
    { 0x0008, 12, 0 },
    { 0x0010, 18, 0 },
    { 0x0020, 22, 0 },
    { 0x0040, 24, 0 },
    { 0x0080, 36, 0 },
    { 0x0100, 48, 0 },
    { 0x0200, 72, 0 },
    { 0x0400, 96, 0 },
    { 0x0800, 108, 0 },
};
