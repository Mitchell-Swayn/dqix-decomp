#include "globaldefs.h"
#pragma optimize_for_size off
ARM
extern "C" void _Z21InitializeCardReadingv(); extern "C" void _Z22SetReadContextPriorityj(unsigned); extern "C" int _Z19GenerateLockOwnerIDv(); extern "C" void DisableInterruptsAndHaltForever(); extern "C" void LockCardReadManagerModeTwo(unsigned short); extern "C" void Card_WaitForIdleAndUnlockReadManager(unsigned short); extern "C" void CardReadManager_ExecuteModeCommandSynchronously(unsigned);
struct State {unsigned short a,owner;}; extern "C" State data_02108dfc; extern "C" unsigned char data_020f0dc8;
// Original: arm9/main @ 0x020758A8; symbol: func_020758a8; size: 0x68.
extern "C" void Filesystem_InitializeCardReadingAndLockOwner(){_Z21InitializeCardReadingv();_Z22SetReadContextPriorityj(8);int owner=_Z19GenerateLockOwnerIDv();if(owner==-3)DisableInterruptsAndHaltForever();data_02108dfc.owner=owner;LockCardReadManagerModeTwo(data_02108dfc.owner);CardReadManager_ExecuteModeCommandSynchronously(0x1001);Card_WaitForIdleAndUnlockReadManager(data_02108dfc.owner);data_020f0dc8=1;}
