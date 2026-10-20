// Original BSS: arm9/main @ 0x02114308; symbol: data_02114308; size: 0x28.
// Zero-filled at load; contents are mutable at runtime.
// Ten pointer-sized entries backing the wireless free-command-buffer queue.
// Wireless_InitializeSharedCommandBuffers passes this array and capacity10 to
// OS_InitMessageQueue, then queues pointers to each of its ten command buffers.
// The queue control object is separately owned at 0x021142E8.
typedef char WirelessCommandQueuePointerSizeCheck[sizeof(void*) == 4 ? 1 : -1];
extern "C" {
void* WirelessInitializeSharedCommandBuffers_UnknownRoleZeroInitializedStorage[10];
}
