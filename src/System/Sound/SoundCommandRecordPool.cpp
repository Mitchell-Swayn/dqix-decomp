// Original BSS: arm9/main @ 0x02112A60; symbol: data_02112a60; size: 0x1800.
// The sound command pool consists of 256 linked 24-byte records. The original
// initializer at 0x020D2220 links next fields with stride 24; command producers
// write the command and four argument words, then SND_PushCommand queues them.
// The argument words encode command-dependent values; no speculative payload
// unions, pointee types or command-specific field meanings are introduced.
struct SNDCommand {
    SNDCommand* next;
    unsigned command;
    unsigned arguments[4];
};
typedef char SNDCommandRecordSizeCheck[sizeof(SNDCommand) == 24 ? 1 : -1];
// Preserve original interior labels as linker aliases to records 140 and 255:
// 0x02113780 = base+0xD20; 0x02114248 = base+0x17E8.
// These aliases reserve no additional storage.
extern "C" {
SNDCommand SoundCommandFlushPendingBatch_UnknownRoleZeroInitializedStorage_Variant2[256];
}
