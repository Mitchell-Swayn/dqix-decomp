#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2245ff4; symbol: data_ov031_02245ff4.
// Wi-Fi option masks by index 0..12. System_DispatchWithIndexedTableFlag clamps the input index to 12 and ORs the selected word into caller flags.
// Initial values: hex 02800000048000000880000010800000208000004080000080800000008100000082000000840000008800000090000000a00000.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int SystemDispatchWithIndexedTableFlag_WiFiOptionMasksByIndex012[];
extern "C" void Network_RequestScanOrStopScan(void *first, void *second, unsigned int flags);
// Original: arm9/ov031 @ 0x022151B0; symbol: func_ov031_022151b0; size: 0x24.
extern "C" void System_DispatchWithIndexedTableFlag(void *first, void *second, int index, unsigned int flags) {
    if (index > 0x0c)
        index = 0x0c;
    unsigned int combined = flags | SystemDispatchWithIndexedTableFlag_WiFiOptionMasksByIndex012[index];
    Network_RequestScanOrStopScan(first, second, combined);
}
