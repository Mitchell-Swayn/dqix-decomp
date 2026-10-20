#include <globaldefs.h>
ARM
void InitializeArenas();void InitializeInterProcessorCommunication();void InitializeGamecardBusOwnership();void InitializeExtendedArena();void InitializeInterruptBlockedThreadList();void InitializeCardReading();
extern "C" {void OS_SetIrqStackChecker();void System_InitializeExceptionHandler();void Graphics_ResetVRAMBankHAndDMAChannelZero();void OS_InitVAlarm();void OS_InitVramExclusive();void OS_InitThread();void IPC_InitializeChannelTwelveHandler();void IPC_InitializeCommandThirteenHandshakeOnce();void PowerManagement_InitializeIPCHandler();void OSi_WaitVCount0();
// Original: arm9/main @ 0x020C8368; symbol: func_020c8368; size: 0x48.
void System_InitializeCoreSubsystems(){InitializeArenas();InitializeInterProcessorCommunication();InitializeGamecardBusOwnership();InitializeExtendedArena();InitializeInterruptBlockedThreadList();OS_SetIrqStackChecker();System_InitializeExceptionHandler();Graphics_ResetVRAMBankHAndDMAChannelZero();OS_InitVAlarm();OS_InitVramExclusive();OS_InitThread();IPC_InitializeChannelTwelveHandler();IPC_InitializeCommandThirteenHandshakeOnce();InitializeCardReading();PowerManagement_InitializeIPCHandler();OSi_WaitVCount0();}}
