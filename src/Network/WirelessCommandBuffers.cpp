// Original BSS: arm9/main @ 0x02114380; symbol: data_02114380; size: 0xA00.
// Zero-filled at load; contents are mutable at runtime.
// Ten 256-byte command buffers populated by the wireless command path.
// Wireless_InitializeSharedCommandBuffers visits every buffer, sets the first
// halfword to 0x8000, cleans that halfword from cache and enqueues its address.
// WMi_SendCommandDirect copies a command into a received free buffer and passes
// the same address through IPC before returning it to the queue.
struct WirelessCommandBuffer {
    unsigned short type;
    char bytes[254];
};
typedef char WirelessCommandBufferSizeCheck[sizeof(WirelessCommandBuffer) == 256 ? 1 : -1];
extern "C" {
WirelessCommandBuffer WirelessInitializeSharedCommandBuffers_UnknownRoleZeroInitializedStorage_Variant2[10];
}
