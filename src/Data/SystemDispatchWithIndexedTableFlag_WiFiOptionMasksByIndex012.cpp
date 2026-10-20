// Wi-Fi option masks by index 0..12. System_DispatchWithIndexedTableFlag clamps
// the input index to 12 and ORs the selected word into caller flags.
// Original data: arm9/ov031 @ 0x2245ff4; symbol: data_ov031_02245ff4.
// Wi-Fi option masks by index 0..12. System_DispatchWithIndexedTableFlag clamps the input index to 12 and ORs the selected word into caller flags.
// Initial values: hex 02800000048000000880000010800000208000004080000080800000008100000082000000840000008800000090000000a00000.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" const unsigned int SystemDispatchWithIndexedTableFlag_WiFiOptionMasksByIndex012[13] = {
    0x00008002U, 0x00008004U, 0x00008008U, 0x00008010U, 0x00008020U, 0x00008040U, 0x00008080U, 0x00008100U, 0x00008200U, 0x00008400U, 0x00008800U, 0x00009000U, 0x0000a000U
};
