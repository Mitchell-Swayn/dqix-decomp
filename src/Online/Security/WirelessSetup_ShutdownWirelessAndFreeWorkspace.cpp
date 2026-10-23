#pragma thumb on
#pragma optimize_for_size off
#pragma optimization_level 4
extern "C" int Network_BeginManagedSessionShutdown(void);
extern "C" unsigned WirelessSetup_PopEvent(void);
#pragma thumb off
extern "C" void _Z19SleepCurrentContextj(unsigned);
#pragma thumb on
// Original data: arm9/ov031 @ 0x0224F670; symbol: data_ov031_0224f670.
// Shared zero-initialized wireless context; callbacks and fields are established by accesses.
// See docs/data-symbols/ov031.md; the full logical object extent remains unresolved.
extern "C" unsigned char WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221FB38; symbol: func_ov031_0221fb38; size: 0x58.
// Drains shutdown events until completion, releases the wireless workspace through its callback and clears its pointer.
extern "C" int WirelessSetup_ShutdownWirelessAndFreeWorkspace(void)
{
    int waiting = 1;
    if (Network_BeginManagedSessionShutdown()) {
        do {
            _Z19SleepCurrentContextj(10);
            unsigned event;
            while ((event = WirelessSetup_PopEvent()) != 0) {
                switch (event) {
                case 4:
                case 5:
                    break;
                case 20:
                    waiting = 0;
                    break;
                default:
                    waiting = 0;
                    break;
                }
            }
        } while (waiting);
    }
    unsigned char* state = WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage;
    void* workspace = *(void**)(state + 0x54);
    if (workspace) {
        (*(void (**)(void*))(state + 0x0c))(workspace);
        *(void**)(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage + 0x54) = 0;
    }
    return 1;
}
